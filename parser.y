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


extern int yylineno; //contador de lineas

extern FILE *yyin; // Variable que usa Lex para leer la entrada         
FILE *yyout_py;    // Nuestra variable para escribir la salida Python 
int nivel_indentacion = 0; 
void imprimir_indentacion() {
    for (int i = 0; i < nivel_indentacion; i++) {
        fprintf(yyout_py, "    "); // Imprime 4 espacios por nivel
    }
}

struct InfoExpresion {
        char *codigo;
        int tipo_dato; 
    };

%}

/* union: Su función en el mundo es redefinir la "caja de encomiendas" (yylval) 
para que tenga compartimentos de distintos tipos de datos.*/
%union {
    char *nombre;     
    double val_num;   
    struct InfoExpresion *info_expr;
}

/* DECLARAMOS LOS TOKENS Y LE ASIGNAMOS EL TIPO DE LA UNION A ID */
%token IF ELSE WHILE RETURN INT FLOAT CHAR CONST DOUBLE FOR SWITCH CASE VOID
%token MAYOR_IGUAL IGUAL_IGUAL MENOR_IGUAL BREAK DEFAULT
%token <nombre> ID
%token <val_num> NUMERO 
%type <nombre> loop_consecuencia
%type <nombre> inicializador_array lista_inicializadores valor_o_anidado asignacion_array

%left '+' '-'
%left '*' '/'
%type <info_expr> expresion 

%%

programa: instrucciones
        ;

bloque   : '{' {
                /* Acción intermedia: Al abrir '{', creamos entorno local */
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
            } 
        instrucciones '}' {
                /* Acción final: Al cerrar '}', regresamos de nivel al padre */
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                
                /* Opcional: Podés liberar la memoria de 'viejo' aquí si querés */
            }
      ;

instrucciones : instrucciones instruccion 
             | /* vacío (regla lambda) */
             ;

instruccion : declaracion 
           | asignacion
           | bloque
           | loop
           | condicionales
           | funcion_void
           | funcion_NO_void
           | llamar_funcion
           | arrays
           ;

declaracion : prefijo_declaracion declarar_lista_ids ';' { es_constante_actual = 0; }
            | CONST declarar_lista_ids ';' {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
            | ';'
            ;

for_init : declaracion
         | asignacion
         ;

asignacion : lista_asignaciones ';' ;

prefijo_declaracion : tipo             { es_constante_actual = 0; }
                    | CONST tipo       { es_constante_actual = 1; } /* ¡Se activa ANTES de lista_ids! */
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

                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Cada uno imprime su espacio al inicio
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
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
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
                    // ¡OJO! Te faltaba esta línea fundamental para que el while sepa su ID real:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno; 

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
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
                    // ¡OJO! Aquí también te faltaba:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    
                    imprimir_indentacion(); // Indentamos
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
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, $3->codigo);
                        }
                        free($1); free($3);
                    }
                    | ID'+''+' {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $1);
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free($1);
                    }
                    | ID'-''-' {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $1);
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free($1);
                    }
                    | '+''+'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $3);
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free($3);
                    }
                    | '-''-'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $3);
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free($3);
                    }
                    | ID {
                        struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $1);
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free($1);
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

            nivel_indentacion--; // Bajamos la indentación de Python

            /* 2. Destruimos el entorno local del loop */
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
                    free($1); free($3);
            }
               | expresion '>' expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s > %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion '<' expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s < %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion MAYOR_IGUAL expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s >= %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion MENOR_IGUAL expresion { // NUMERO '<=' ID
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s <= %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion IGUAL_IGUAL expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s == %s:\n", $1->codigo, $3->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
            | expresion {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", $1->codigo);
                    nivel_indentacion++;
                    free($1->codigo); free($1);
            }
            ;

loop_consecuencia: ID {
                    struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                    $$ = strdup("");
                } else {
                    $$ = strdup("");
                }
            }
                | ID'+''+' {
                    struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                    $$ = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    $$ = strdup(buf);
                }
                }
                |  '-''-'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                    $$ = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    $$ = strdup(buf);
                }
                }
                | ID '=' expresion {
                    struct entrada_tabla *entrada = buscar_variable($1);
                    if (entrada == NULL){
                        printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                        $$ = strdup("");
                    } else {
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, $3->codigo);
                        $$ = strdup(buf);
                    }
                    free($1); free($3);
                }
                ;

expresion : ID {
                $$ = malloc(sizeof(struct InfoExpresion));
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", $1);
                    $$->codigo = strdup($1); 
                    $$->tipo_dato = T_INT; // Asumimos INT por defecto si hay error
                } else {
                    // Si existe, generamos su nombre real de Python con su entorno: ej "i_1"
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    $$->codigo = strdup(buf);
                    $$->tipo_dato = entrada->tipo_base;
                }
                free($1);
          }
          | NUMERO {
            $$ = malloc(sizeof(struct InfoExpresion));
                char buf[50];
                sprintf(buf, "%g", $1);
                $$->codigo = strdup(buf);
                $$->tipo_dato = T_INT; // <-- ¡Faltaba esto!
          }
          | expresion '+' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s + %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                if ($1->tipo_dato != $3->tipo_dato) {
                        printf("[Error Semántico] Línea %d: Tipos incompatibles en la suma.\n", yylineno);
                }
                // 3. Heredamos el tipo (Asumimos que si llegamos acá el resultado es del mismo tipo)
                $$->tipo_dato = $1->tipo_dato; // <-- ¡Faltaba esto!
                
                free($1->codigo); free($1);
                free($3->codigo); free($3);
          }
          | expresion '-' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s - %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                
                if ($1->tipo_dato != $3->tipo_dato) {
                    printf("[Error Semántico] Línea %d: Tipos incompatibles en la resta.\n", yylineno);
                }
                
                $$->tipo_dato = $1->tipo_dato;
                
                free($1->codigo); free($1);
                free($3->codigo); free($3);
          }
          | expresion '*' expresion {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s * %s", $1->codigo, $3->codigo);
                $$->codigo = strdup(buf);
                
                if ($1->tipo_dato != $3->tipo_dato) {
                    printf("[Error Semántico] Línea %d: Tipos incompatibles en la multiplicación.\n", yylineno);
                }
                
                $$->tipo_dato = $1->tipo_dato;
                
                free($1->codigo); free($1);
                free($3->codigo); free($3);
          }
          | '(' expresion ')' {
                $$ = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "(%s)", $2->codigo);
                $$->codigo = strdup(buf);
                
                // Los paréntesis no cambian el tipo, solo lo pasan hacia arriba
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
            /*if($1 == float){
                printf("Error, prohibida sintaxis para switch, la expresion debe ser entera, arreglar linea %d\n", yylineno);
             } TODO cambiar esto cuando ya tengamos un verificador de tipos*/ 
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", $3->codigo);
            nivel_indentacion++;
            free($3);
        } switch_cases '}' {
            nivel_indentacion--;
        }
        ;

    bloque_else: ELSE IF '(' { 
                // Traducimos el 'else if' de C al 'elif' de Python
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
                // El caso base de cierre: un 'else:' simple
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           } 
           '{' instrucciones '}' {
                nivel_indentacion--;
           }
         
         | /* vacío (regla lambda por si el IF no tiene ningún ELSE) */
         ;

    switch_cases: CASE expresion ':'{
                    if (strchr($2->codigo, '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, $2->codigo);
                    } //si expresion trae un _ en su nombre, significa que es una variable, algo prohbido en c
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", $2->codigo);
                    nivel_indentacion++; //subimos la indentación para las instrucciones de este case específico
                    free($2);
    } instrucciones BREAK ';' {
        nivel_indentacion--;
    } switch_cases
                | DEFAULT ':' {
                    // Opcional: Agregamos soporte para el 'default:' de C -> 'case _:' de Python
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
              instrucciones {
                    nivel_indentacion--;
              }
                | error switch_cases { 
                    // Si algo falla dentro de un case, Bison limpia la pila 
                    // hasta encontrar el inicio del Siguiente CASE o el cierre '}'
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; // Indica a Bison que ya retomamos el control
              }

            | /* vacío */
            ;

    condicion_IF: expresion '=' expresion {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace, por favor, corregir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "%s = %s", $1->codigo, $3->codigo);
                    free($1); free($3);
            }
               | expresion '>' expresion {
                    fprintf(yyout_py, "%s > %s", $1->codigo, $3->codigo);
                    free($1); free($3);
            }
               | expresion '<' expresion {
                    fprintf(yyout_py, "%s < %s", $1->codigo, $3->codigo);
                    free($1); free($3);
            }
               | expresion MAYOR_IGUAL expresion {
                    fprintf(yyout_py, "%s >= %s", $1->codigo, $3->codigo);
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion MENOR_IGUAL expresion { // NUMERO '<=' ID
                    fprintf(yyout_py, "%s <= %s", $1->codigo, $3->codigo);
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
               | expresion IGUAL_IGUAL expresion {
                    fprintf(yyout_py, "%s == %s", $1->codigo, $3->codigo);
                    free($1->codigo); free($1); free($3->codigo); free($3);
            }
            | expresion {
                    fprintf(yyout_py, "%s", $1->codigo);
                    free($1->codigo); free($1);
            }
            ;

declaracion_variables_funcion : lista_parametros
                          | /* vacío (por si la función no recibe parámetros) */
                          ;

lista_parametros : parametro_void
                 | lista_parametros ',' { 
                        // TRUCO: Imprimimos la coma y un espacio justo cuando Bison detecta el token ','
                        fprintf(yyout_py, ", "); 
                   } 
                   parametro_void
                 ;

parametro_void : tipo ID { //realmente es malo este nombre parametro_void, porque las funciones que no son void tambien usan esta gramatica, pero no se me ocurre un nombre bueno y que no sea largo, y tampoco importa tanto
                struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // Imprimimos el nombre limpio directamente en Python, sin indentación extra
                    fprintf(yyout_py, "%s_%d", $2, entorno_actual->id_entorno);
                }
                free($2);
          }
          ;

            funcion_void: VOID ID '(' {
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", $2);
                free($2);
            } declaracion_variables_funcion ')' {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            } '{' instrucciones '}' {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }

            funcion_NO_void: prefijo_declaracion ID '(' { //estaba 'tipo' en vez de prefijo_declaracion, quilombo era
                struct entrada_tabla *entrada = declarar_variable($2);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $2);
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                }
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", $2);
                free($2);
            } declaracion_variables_funcion ')' {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            } '{' instrucciones RETURN expresion ';' '}' { //debilidad, no puede haber más de 1 return, y encima el bloque de la funcion debe terminar sí o sí con un return
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }




            llamar_funcion: ID '(' {
                struct entrada_tabla *entrada = buscar_variable($1);
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", $1);
                        }
                imprimir_indentacion();
                fprintf(yyout_py, "%s(", $1);
                free($1);
            } usar_variables_funcion ')' {
                fprintf(yyout_py, ")\n");
            } ';'
            ;

            usar_variables_funcion : lista_parametros_llamar_funcion
                          | /* vacío (por si la función no recibe parámetros) */
                          ;

lista_parametros_llamar_funcion : parametro_llamar_funcion
                 | lista_parametros_llamar_funcion ',' { 
                        // TRUCO: Imprimimos la coma y un espacio justo cuando Bison detecta el token ','
                        fprintf(yyout_py, ", "); 
                   } 
                   parametro_llamar_funcion
    ;

    parametro_llamar_funcion : expresion { 
        fprintf(yyout_py, "%s", $1->codigo); 
        free($1->codigo); 
    }
    ;

    volumen_array: NUMERO
                    |
    ;
    
    dimension_array: '[' volumen_array ']' dimension_array
                    | 
    ;

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

    asignacion_array: '=' inicializador_array {
                        $$ = strdup($2);
                        free($2);
                    }
                    | /* vacío */ {
                        $$ = NULL;
                    }
                    ;

    // 1. La regla base del inicializador que encierra todo entre llaves
inicializador_array:
    '{' lista_inicializadores '}'
    {
        // En C entraron { y }, pero para Python armamos el string con [ y ]
        $$ = malloc(strlen($2) + 3);
        sprintf($$, "[%s]", $2);
        free($2);
    }
    ;

// 2. Una lista de cosas separadas por comas (recursividad por la izquierda)
lista_inicializadores:
    valor_o_anidado
    {
        $$ = strdup($1);
        free($1);
    }
    | lista_inicializadores ',' valor_o_anidado
    {
        // Concatenamos lo que ya teníamos con el nuevo valor
        $$ = malloc(strlen($1) + strlen($3) + 3);
        sprintf($$, "%s, %s", $1, $3);
        free($1);
        free($3);
    }
    ;

// 3. LA REGLA CLAVE: Un elemento puede ser un simple número/expresión, 
// o puede ser OTRO array anidado.
valor_o_anidado:
    expresion // Tu regla actual que maneja NUMERO, ID, operaciones, etc.
    {
        $$ = strdup($1->codigo);
        free($1);
    }
    | inicializador_array
    {
        $$ = strdup($1); 
        free($1);
        // Ya viene con los corchetes [] armados desde inicializador_array
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
            printf("Uso: %s <archivo_entrada.c> <archivo_salida.py>\n",     
  argv[0]);                                                                 
            return 1;                                                       
        }                                                                   
                                                                            
        // 1. Abrimos el archivo .c de entrada y se lo pasamos a Lex        
        yyin = fopen(argv[1], "r");                                         
        if (!yyin) {                                                        
            printf("No se pudo abrir el archivo %s\n", argv[1]);            
            return 1;                                                       
        }                                                                   
                                                                            
        // 2. Abrimos/creamos el archivo .py de salida                      
        yyout_py = fopen(argv[2], "w");                                     
        if (!yyout_py) {                                                    
            printf("No se pudo crear el archivo %s\n", argv[2]);            
            fclose(yyin);                                                   
            return 1;                                                       
        }                                                                   
                                                                            
        // 3. Iniciamos el proceso de análisis
        entorno_actual = (struct Entorno *) malloc(sizeof(struct Entorno));
        entorno_actual->tabla_simbolos = NULL;
        entorno_actual->cantidad_simbolos = 0;
        entorno_actual->capacidad_tabla = 0;
        entorno_actual->padre = NULL;

        printf("Iniciando compilacion de %s a %s...\n", argv[1], argv[2]);  
        yyparse();                                                          
        printf("Compilacion finalizada.\n");                                
                                                                            
        // 4. Cerramos los archivos                                         
        fclose(yyin);                                                       
        fclose(yyout_py);                                                   
        return 0;                                                           
    }          