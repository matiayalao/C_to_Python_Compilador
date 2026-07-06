%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Importamos tu lógica rústica de la tabla de símbolos */
#include "tabla_de_simbolos.c"

void yyerror(const char *s);
int yylex(void); 

int tipo_actual = 0;
int es_constante_actual = 0;
int contador_parametros = 0;

#define MAX_PARAMS 32
// Buffer que se llena mientras se parsea la DECLARACIÓN de una función
int tipos_params_actuales[MAX_PARAMS];
// Buffer que se llena mientras se parsea la LLAMADA a una función
int tipos_args_actuales[MAX_PARAMS];


extern int yylineno; //contador de lineas

extern FILE *yyin; // Variable que usa Lex para leer la entrada         
FILE *yyout_py;    // Nuestra variable para escribir la salida Python 
int nivel_indentacion = 0; 
void imprimir_indentacion() {
    for (int i = 0; i < nivel_indentacion; i++) {
        fprintf(yyout_py, "    "); // Imprime 4 espacios por nivel
    }
}

int max_tipo(int t1, int t2) {
    if ((t1 == T_INT || t1 == T_FLOAT || t1 == T_DOUBLE) &&
        (t2 == T_INT || t2 == T_FLOAT || t2 == T_DOUBLE)) {
        return (t1 > t2) ? t1 : t2;
    }
    return t1;
}

struct InfoExpresion {
        char *codigo;
        int tipo_dato; 
    };

%}

%union {
    char *nombre;     
    double val_num;   
    struct InfoExpresion *info_expr;
}

%token IF ELSE WHILE RETURN INT FLOAT CHAR CONST DOUBLE FOR SWITCH CASE VOID
%token MAYOR_IGUAL IGUAL_IGUAL MENOR_IGUAL NO_IGUAL BREAK DEFAULT AND OR
%token <nombre> ID
%token <val_num> NUMERO 
%type <nombre> loop_consecuencia
%type <nombre> inicializador_array lista_inicializadores valor_o_anidado asignacion_array accesos_array
%type <nombre> usar_variables_funcion lista_parametros_llamar_funcion parametro_llamar_funcion

/* --- NUEVO: Tipos para funciones en expresiones y arrays --- */
%type <nombre> usar_variables_funcion_expr lista_parametros_llamar_funcion_expr
%type <info_expr> llamada_funcion_expr

%left OR
%left AND
%left IGUAL_IGUAL NO_IGUAL
%left '<' '>' MENOR_IGUAL MAYOR_IGUAL
%left '+' '-'
%left '*' '/' '%'
%right '!'
%type <info_expr> expresion 

%%

programa: instrucciones
        ;


instrucciones : instrucciones instruccion 
             | /* vacío (regla lambda) */
             | error ';' {
                printf("[Error Sintáctico] Línea %d: Instrucción mal formada. Ignorando hasta encontrar un ';'.\n", yylineno);
                yyerrok; // Le indicamos a Bison que nos hemos recuperado del error
           }
             ;

instruccion : declaracion 
           | asignacion
           | loop
           | condicionales
           | funcion_void
           | funcion_NO_void
           | llamar_funcion
           | arrays
           | RETURN expresion ';' {
                imprimir_indentacion();
                fprintf(yyout_py, "return %s\n", $2->codigo);
                free($2->codigo); free($2);
           }
           | RETURN ';' {
                imprimir_indentacion();
                fprintf(yyout_py, "return\n");
           }
           ;

declaracion : prefijo_declaracion declarar_lista_ids ';' { es_constante_actual = 0; }
            | CONST declarar_lista_ids ';' {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
            | prefijo_declaracion error ';' {
                printf("[Error Sintáctico] Línea %d: Declaración inválida. Revisá la lista de identificadores o la inicialización.\n", yylineno);
                yyerrok;
            }
            | ';'
            ;

for_init : declaracion
         | asignacion
         ;

asignacion : lista_asignaciones ';' ;

prefijo_declaracion : tipo             { es_constante_actual = 0; }
                    | CONST tipo       { es_constante_actual = 1; } 
                    ;

tipo : INT    { tipo_actual = T_INT; }
    | FLOAT  { tipo_actual = T_FLOAT; }
    | CHAR   { tipo_actual = T_CHAR; }
    | DOUBLE { tipo_actual = T_DOUBLE; }
    ;

declarar_lista_ids : ID {
                struct entrada_tabla *entrada = declarar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $1);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    imprimir_indentacion();
                    fprintf(yyout_py, "%s_%d = None\n", $1, entorno_actual->id_entorno);
                }
                free($1);
         }
         | declarar_lista_ids ',' ID {
                struct entrada_tabla *entrada = declarar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    imprimir_indentacion(); 
                    fprintf(yyout_py, "%s_%d = None\n", $3, entorno_actual->id_entorno);
                }
                free($3);
         }
         | ID '=' expresion {
                struct entrada_tabla *entrada = declarar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $1);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno; 
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // Comprobación de tipos: verificar que la expresión sea compatible
                    verificar_compatibilidad_tipos(tipo_actual, $3->tipo_dato, $1, yylineno);

                    imprimir_indentacion();
                    fprintf(yyout_py, "%s_%d = %s\n", $1, entorno_actual->id_entorno, $3->codigo);
                }
                free($1);
         }
         | declarar_lista_ids ',' ID '=' expresion {
                struct entrada_tabla *entrada = declarar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // Comprobación de tipos: verificar que la expresión sea compatible
                    verificar_compatibilidad_tipos(tipo_actual, $5->tipo_dato, $3, yylineno);
                    
                    imprimir_indentacion(); 
                    fprintf(yyout_py, "%s_%d = %s\n", $3, entorno_actual->id_entorno, $5->codigo);
                }
                free($3);
         }
         ;

lista_asignaciones : asignacion_unitaria
                   | lista_asignaciones ',' asignacion_unitaria
                   ;

asignacion_unitaria : ID '=' expresion {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $1);
                        } else {
                            // Comprobación de tipos en reasignación
                            if (!entrada->es_funcion) {
                                verificar_compatibilidad_tipos(entrada->tipo_base, $3->tipo_dato, entrada->nombre, yylineno);
                            }
                            // Verificar que no se asigne a una constante
                            if (entrada->es_constante) {
                                printf("[Error de Tipos] Línea %d: No se puede reasignar la constante '%s'.\n", yylineno, entrada->nombre);
                            }
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, $3->codigo);
                        }
                        free($1); free($3->codigo); free($3);
                    }
                    | ID '=' error {
                        printf("[Error Sintáctico] Línea %d: Asignación inválida para '%s'. Falta o está mal formada la expresión del lado derecho.\n", yylineno, $1);
                        free($1);
                        yyerrok;
                    }
                    /* --- NUEVO PUNTO 1: Permitir setear un array ej. matriz[0][1] = 5 --- */
                    | ID accesos_array '=' expresion {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable array '%s' no existe.\n", $1);
                        } else {
                            imprimir_indentacion();
                            // El nombre de python + los corchetes
                            fprintf(yyout_py, "%s_%d%s = %s\n", entrada->nombre, entrada->id_entorno_declarado, $2, $4->codigo);
                        }
                        free($1); free($2); free($4->codigo); free($4);
                    }
                    | ID'+''+' {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free($1);
                    }
                    | ID'-''-' {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free($1);
                    }
                    | '+''+'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free($3);
                    }
                    | '-''-'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free($3);
                    }
                    | ID {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free($1);
                    }
                    ;

/* --- NUEVO PUNTO 1: Regla para iterar y leer [][][] arrays --- */
accesos_array : '[' expresion ']' {
                    char buf[256];
                    sprintf(buf, "[%s]", $2->codigo);
                    $$ = strdup(buf);
                    free($2->codigo); free($2);
                }
                
              | accesos_array '[' expresion ']' {
                    char buf[512];
                    sprintf(buf, "%s[%s]", $1, $3->codigo);
                    $$ = strdup(buf);
                    free($1); free($3->codigo); free($3);
                }
                | '[' error ']' {
                    printf("[Error Sintáctico] Línea %d: Índice de array inválido.\n", yylineno);
                    // Asignamos un índice seguro "[0]" para que la traducción a Python no se rompa
                    $$ = strdup("[0]"); 
                    yyerrok;
              }
              ;

loop : FOR {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}'('for_init condicion_loop';' loop_consecuencia')' '{' instrucciones '}'{
            if ($7 && strlen($7) > 0) {
                imprimir_indentacion();
                fprintf(yyout_py, "%s", $7);
                free($7);
            }
            nivel_indentacion--; 
            struct Entorno *viejo = entorno_actual;
            entorno_actual = entorno_actual->padre;
            free(viejo);
    }
    | WHILE '(' condicion_loop ')''{' instrucciones '}' {    
        nivel_indentacion--;
    }
    ;

condicion_loop : expresion '=' expresion {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", $1->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1);
            }
            |  error {
                    printf("[Error Sintáctico] Línea %d: Condición de bucle inválida.\n", yylineno);
                    yyerrok;
                }
            ;

loop_consecuencia: ID { $$ = strdup(""); }
                | ID'+''+' {
                    struct entrada_tabla *entrada = buscar_variable($1);
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        $$ = strdup(buf);
                    } else $$ = strdup("");
                }
                |  '-''-'ID {
                    struct entrada_tabla *entrada = buscar_variable($3);
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        $$ = strdup(buf);
                    } else $$ = strdup("");
                }
                | ID '=' expresion {
                    struct entrada_tabla *entrada = buscar_variable($1);
                    if (entrada != NULL){
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, $3->codigo);
                        $$ = strdup(buf);
                    } else $$ = strdup("");
                    free($1); free($3);
                }
                ;

expresion : ID {
                $$ = malloc(sizeof(struct InfoExpresion));
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", $1);
                    $$->codigo = strdup($1); 
                    $$->tipo_dato = T_INT; 
                } else {
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    $$->codigo = strdup(buf);
                    $$->tipo_dato = entrada->tipo_base;
                }
                free($1);
          }
          /* --- NUEVO PUNTO 1: Leer un elemento de array ej. x = matriz[0][1] --- */
          | ID accesos_array {
                $$ = malloc(sizeof(struct InfoExpresion));
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL) {
                    printf("Error semántico: '%s' (array) no declarada.\n", $1);
                    $$->codigo = strdup($1); 
                    $$->tipo_dato = T_INT;
                } else {
                    char buf[512];
                    sprintf(buf, "%s_%d%s", entrada->nombre, entrada->id_entorno_declarado, $2);
                    $$->codigo = strdup(buf);
                    $$->tipo_dato = entrada->tipo_base;
                }
                free($1); free($2);
          }
          /* --- NUEVO PUNTO 3: Poder llamar a funciones desde expresiones --- */
          | llamada_funcion_expr {
                $$ = $1;
          }
          | NUMERO {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[50];
                sprintf(buf, "%g", $1);
                $$->codigo = strdup(buf);
                /* --- NUEVO PUNTO 5: Si el string tiene un punto, es float --- */
                if (strchr(buf, '.') != NULL) {
                    $$->tipo_dato = T_FLOAT;
                } else {
                    $$->tipo_dato = T_INT;
                }
          }
          | expresion '+' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s + %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                /* --- NUEVO PUNTO 2: Promoción de tipos automática --- */
                $$->tipo_dato = max_tipo($1->tipo_dato, $3->tipo_dato); 
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion '-' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s - %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                $$->tipo_dato = max_tipo($1->tipo_dato, $3->tipo_dato);
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion '*' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s * %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                $$->tipo_dato = max_tipo($1->tipo_dato, $3->tipo_dato);
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          /* --- NUEVO PUNTO 5: División, Modulo y Lógicos/Relacionales --- */
          | expresion '/' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s / %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                $$->tipo_dato = max_tipo($1->tipo_dato, $3->tipo_dato);
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion '%' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s %% %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion AND expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s and %s", $1->codigo, $3->codigo); // Traduccion a python "and"
                $$->codigo = strdup(buf);
                $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion OR expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s or %s", $1->codigo, $3->codigo); // Traduccion a python "or"
                $$->codigo = strdup(buf);
                $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | '!' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "not %s", $2->codigo); // Traduccion a python "not"
                $$->codigo = strdup(buf);
                $$->tipo_dato = T_INT;
                free($2->codigo); free($2);
          }
          | expresion '>' expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s > %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion '<' expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s < %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion IGUAL_IGUAL expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s == %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion NO_IGUAL expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s != %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion MAYOR_IGUAL expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s >= %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | expresion MENOR_IGUAL expresion {
                $$ = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s <= %s", $1->codigo, $3->codigo); $$->codigo = strdup(buf); $$->tipo_dato = T_INT;
                free($1->codigo); free($1); free($3->codigo); free($3);
          }
          | '(' expresion ')' {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "(%s)", $2->codigo);
                $$->codigo = strdup(buf);
                $$->tipo_dato = $2->tipo_dato; 
                free($2->codigo); free($2);
          }
          ;

    condicionales: IF '(' {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        } condicion_IF ')' {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        } '{' instrucciones '}' { 
            nivel_indentacion--;
        } bloque_else
        | SWITCH '(' expresion ')' {
            
        }'{' {
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", $3->codigo);
            nivel_indentacion++;
            free($3);
        } switch_cases '}' {
            nivel_indentacion--;
        }
        ;

    bloque_else: ELSE IF '(' { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           } 
           condicion_IF ')' { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           } 
           '{' instrucciones '}' {
                nivel_indentacion--;
           } bloque_else
         
         | ELSE { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           } 
           '{' instrucciones '}' {
                nivel_indentacion--;
           }
         
         | /* vacío */
         ;

    switch_cases: CASE expresion ':'{
                    if (strchr($2->codigo, '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, $2->codigo);
                    }
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", $2->codigo);
                    nivel_indentacion++; 
                    free($2);
    } instrucciones BREAK ';' {
        nivel_indentacion--;
    } switch_cases
                | DEFAULT ':' {
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
              instrucciones {
                    nivel_indentacion--;
              }
                | error switch_cases { 
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; 
              }
            | /* vacío */
            ;

    condicion_IF: expresion '=' expresion {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace.\n");
                    fprintf(yyout_py, "%s = %s", $1->codigo, $3->codigo);
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion {
                    fprintf(yyout_py, "%s", $1->codigo);
                    free($1->codigo); free($1);
            }
            | error {
                    printf("[Error Sintáctico] Línea %d: Condición de 'if' inválida.\n", yylineno);
                    yyerrok;
            }
            ;

declaracion_variables_funcion : lista_parametros
                          | /* vacío */
                          ;

lista_parametros : parametro_void
                 | lista_parametros ',' { fprintf(yyout_py, ", "); } parametro_void
                 ;

parametro_void : tipo ID { 
                struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    // Guardamos el tipo de este parámetro en el buffer de declaración
                    if (contador_parametros < MAX_PARAMS)
                        tipos_params_actuales[contador_parametros] = tipo_actual;
                    contador_parametros++;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    fprintf(yyout_py, "%s_%d", $2, entorno_actual->id_entorno);
                }
                free($2);
          }
          | ID '(' error ')' ';' {
                    printf("[Error Sintáctico] Línea %d: Error en los parámetros de la función '%s'.\n", yylineno, $1);
                    yyerrok;
               }
          ;

            funcion_void: VOID ID '(' {
                struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = T_VOID;
                    entrada->es_funcion = 1;
                    struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                    nuevo->tabla_simbolos = NULL;
                    nuevo->cantidad_simbolos = 0;
                    nuevo->capacidad_tabla = 0;
                    nuevo->padre = entorno_actual;
                    nuevo->id_entorno = contador_entornos++; 
                    entorno_actual = nuevo; 
                    imprimir_indentacion();
                    fprintf(yyout_py, "def %s(", $2);
                }
            } declaracion_variables_funcion ')' {
                struct entrada_tabla *entrada = buscar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' no existe. Línea %d\n", $2, yylineno);
                } else {
                    entrada->cantidad_parametros_funcion = contador_parametros;
                    // Copiar el buffer de tipos al arreglo dinámico de la entrada
                    if (contador_parametros > 0) {
                        entrada->tipos_parametros = (int *) malloc(contador_parametros * sizeof(int));
                        for (int i = 0; i < contador_parametros; i++)
                            entrada->tipos_parametros[i] = tipos_params_actuales[i];
                    }
                    contador_parametros = 0;
                    free($2);
                }
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            } '{' instrucciones '}' {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }

            /* --- NUEVO PUNTO 3: funcion_NO_void con flexibildad de Returns --- */
            funcion_NO_void: prefijo_declaracion ID '(' {
                struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->es_funcion = 1;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                }
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++;
                entorno_actual = nuevo;
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", $2);
            } declaracion_variables_funcion ')' {
                struct entrada_tabla *entrada = buscar_variable($2);
                if (entrada != NULL) {
                    entrada->cantidad_parametros_funcion = contador_parametros;
                    // Copiar el buffer de tipos al arreglo dinámico de la entrada
                    if (contador_parametros > 0) {
                        entrada->tipos_parametros = (int *) malloc(contador_parametros * sizeof(int));
                        for (int i = 0; i < contador_parametros; i++)
                            entrada->tipos_parametros[i] = tipos_params_actuales[i];
                    }
                }
                contador_parametros = 0;
                free($2);
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            } '{' instrucciones '}' {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }

            llamar_funcion: ID '(' {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL) {
                    printf("Error semántico: la función '%s' no existe.\n", $1);
                }
                imprimir_indentacion();
                fprintf(yyout_py, "%s(", $1);
            } usar_variables_funcion ')' {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada != NULL && entrada->es_funcion) {
                    if (contador_parametros != entrada->cantidad_parametros_funcion) {
                        printf("[Error de Tipos] Línea %d: La función '%s' espera %d parámetro(s) pero se le pasaron %d.\n",
                               yylineno, $1,
                               entrada->cantidad_parametros_funcion,
                               contador_parametros);
                    } else if (entrada->tipos_parametros != NULL) {
                        // Verificar el tipo de cada argumento posición a posición
                        for (int i = 0; i < contador_parametros; i++) {
                            if (!verificar_compatibilidad_tipos(
                                    entrada->tipos_parametros[i],
                                    tipos_args_actuales[i],
                                    entrada->nombre,
                                    yylineno)) {
                                printf("  (parámetro %d: se esperaba '%s', se recibió '%s')\n",
                                       i + 1,
                                       nombre_tipo(entrada->tipos_parametros[i]),
                                       nombre_tipo(tipos_args_actuales[i]));
                            }
                        }
                    }
                }
                contador_parametros = 0;
                free($1);
                fprintf(yyout_py, ")\n");
            } ';'
            ;

            usar_variables_funcion : lista_parametros_llamar_funcion
                          | /* vacío */ { $$ = strdup(""); }
                          ;

lista_parametros_llamar_funcion : parametro_llamar_funcion
                 | lista_parametros_llamar_funcion ',' { fprintf(yyout_py, ", "); } parametro_llamar_funcion
    ;

    parametro_llamar_funcion : expresion { 
        fprintf(yyout_py, "%s", $1->codigo);
        // Guardar el tipo del argumento en el buffer de llamadas
        if (contador_parametros < MAX_PARAMS)
            tipos_args_actuales[contador_parametros] = $1->tipo_dato;
        contador_parametros++;
        free($1->codigo); free($1);
    }
    ;

    /* --- NUEVO PUNTO 3: Llamar a funciones dentro de asignaciones/if/while --- */
    llamada_funcion_expr : ID '(' usar_variables_funcion_expr ')' {
            $$ = malloc(sizeof(struct InfoExpresion));
            struct entrada_tabla *entrada = buscar_variable($1);
            // Verificar cantidad y tipos de parámetros
            if (entrada != NULL && entrada->es_funcion) {
                if (contador_parametros != entrada->cantidad_parametros_funcion) {
                    printf("[Error de Tipos] Línea %d: La función '%s' espera %d parámetro(s) pero se le pasaron %d.\n",
                           yylineno, $1,
                           entrada->cantidad_parametros_funcion,
                           contador_parametros);
                } else if (entrada->tipos_parametros != NULL) {
                    // Verificar el tipo de cada argumento posición a posición
                    for (int i = 0; i < contador_parametros; i++) {
                        if (!verificar_compatibilidad_tipos(
                                entrada->tipos_parametros[i],
                                tipos_args_actuales[i],
                                entrada->nombre,
                                yylineno)) {
                            printf("  (parámetro %d: se esperaba '%s', se recibió '%s')\n",
                                   i + 1,
                                   nombre_tipo(entrada->tipos_parametros[i]),
                                   nombre_tipo(tipos_args_actuales[i]));
                        }
                    }
                }
            }
            contador_parametros = 0;
            char buf[1024];
            sprintf(buf, "%s(%s)", $1, $3);
            $$->codigo = strdup(buf);
            $$->tipo_dato = entrada ? entrada->tipo_base : T_INT;
            free($1); free($3);
    }
    ;

    usar_variables_funcion_expr : lista_parametros_llamar_funcion_expr { $$ = $1; }
                                | /* vacío */ { $$ = strdup(""); }
                                ;

    lista_parametros_llamar_funcion_expr : expresion { 
            $$ = strdup($1->codigo);
            // Guardar el tipo del argumento en el buffer de llamadas
            if (contador_parametros < MAX_PARAMS)
                tipos_args_actuales[contador_parametros] = $1->tipo_dato;
            contador_parametros++;
            free($1->codigo); free($1); 
        }
        | lista_parametros_llamar_funcion_expr ',' expresion { 
            char buf[1024];
            sprintf(buf, "%s, %s", $1, $3->codigo);
            $$ = strdup(buf);
            // Guardar el tipo del argumento en el buffer de llamadas
            if (contador_parametros < MAX_PARAMS)
                tipos_args_actuales[contador_parametros] = $3->tipo_dato;
            contador_parametros++;
            free($1); free($3->codigo); free($3);
        }
        ;

    volumen_array: NUMERO | ;
    
    dimension_array: '[' volumen_array ']' dimension_array | ;

    arrays: prefijo_declaracion ID '[' volumen_array ']' dimension_array asignacion_array ';' {
        struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    imprimir_indentacion();
                    if ($7 != NULL) {
                        fprintf(yyout_py, "%s_%d = %s\n", $2, entorno_actual->id_entorno, $7);
                        free($7);
                    } else {
                        fprintf(yyout_py, "%s_%d = []\n", $2, entorno_actual->id_entorno);
                    }
                }
                free($2);
    }
    ;

    asignacion_array: '=' inicializador_array { $$ = strdup($2); free($2); }
                    | /* vacío */ { $$ = NULL; }
                    ;

inicializador_array:
    '{' lista_inicializadores '}'
    {
        $$ = malloc(strlen($2) + 3);
        sprintf($$, "[%s]", $2);
        free($2);
    }
    ;

lista_inicializadores:
    valor_o_anidado
    {
        $$ = strdup($1);
        free($1);
    }
    | lista_inicializadores ',' valor_o_anidado
    {
        $$ = malloc(strlen($1) + strlen($3) + 3);
        sprintf($$, "%s, %s", $1, $3);
        free($1);
        free($3);
    }
    ;

valor_o_anidado:
    expresion {
        $$ = strdup($1->codigo);
        free($1);
    }
    | inicializador_array {
        $$ = strdup($1); 
        free($1);
    }
    ;

%%

/* Inclusión rústica del analizador léxico al final del archivo */
#include "lex.yy.c"

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en la línea %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {                                       
        if (argc != 3) {                                                    
            printf("Uso: %s <archivo_entrada.c> <archivo_salida.py>\n", argv[0]);                                                                 
            return 1;                                                       
        }                                                                   
                                                                            
        yyin = fopen(argv[1], "r");                                         
        if (!yyin) {                                                        
            printf("No se pudo abrir el archivo %s\n", argv[1]);            
            return 1;                                                       
        }                                                                   
                                                                            
        yyout_py = fopen(argv[2], "w");                                     
        if (!yyout_py) {                                                    
            printf("No se pudo crear el archivo %s\n", argv[2]);            
            fclose(yyin);                                                   
            return 1;                                                       
        }                                                                   
                                                                            
        entorno_actual = (struct Entorno *) malloc(sizeof(struct Entorno));
        entorno_actual->tabla_simbolos = NULL;
        entorno_actual->cantidad_simbolos = 0;
        entorno_actual->capacidad_tabla = 0;
        entorno_actual->padre = NULL;
        entorno_actual->id_entorno = contador_entornos++;

        printf("Iniciando compilacion de %s a %s...\n", argv[1], argv[2]);  
        yyparse();                                                          
        printf("Compilacion finalizada.\n");                                
                                                                            
        fclose(yyin);                                                       
        fclose(yyout_py);                                                   
        return 0;                                                           
}
