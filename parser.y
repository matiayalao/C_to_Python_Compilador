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

%}

/* union: Su función en el mundo es redefinir la "caja de encomiendas" (yylval) 
para que tenga compartimentos de distintos tipos de datos.*/
%union {
    char *nombre;     
    double val_num;   
}

/* DECLARAMOS LOS TOKENS Y LE ASIGNAMOS EL TIPO DE LA UNION A ID */
%token IF ELSE WHILE RETURN INT FLOAT CHAR CONST DOUBLE FOR 
%token MAYOR_IGUAL IGUAL_IGUAL MENOR_IGUAL
%token <nombre> ID
%token <val_num> NUMERO 
%type <nombre> loop_consecuencia

%left '+' '-'
%left '*' '/'
%type <nombre> expresion_loop 

%%

programa : instrucciones
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

/* AQUÍ ESTÁ EL SECRETO: Una instrucción puede ser una declaración O un bloque nuevo */
instruccion : declaracion 
           | bloque
           | loop
           ;

declaracion : prefijo_declaracion lista_ids ';' { es_constante_actual = 0; }
            | CONST lista_ids ';' {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
            | 
            ;

prefijo_declaracion : tipo             { es_constante_actual = 0; }
                    | CONST tipo       { es_constante_actual = 1; } /* ¡Se activa ANTES de lista_ids! */
                    ;

tipo : INT    { tipo_actual = T_INT; }
    | FLOAT  { tipo_actual = T_FLOAT; }
    | CHAR   { tipo_actual = T_CHAR; }
    | DOUBLE { tipo_actual = T_DOUBLE; }
    ;

lista_ids : ID {
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
         | lista_ids ',' ID {
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
         | ID '=' expresion_loop {
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
                    fprintf(yyout_py, "%s_%d = %s\n", $1, entorno_actual->id_entorno, $3);
                }
                free($1);
         }
         | lista_ids ',' ID '=' expresion_loop {
                struct entrada_tabla *entrada = declarar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;
                    // ¡OJO! Aquí también te faltaba:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    
                    imprimir_indentacion(); // Indentamos
                    fprintf(yyout_py, "%s_%d = %s\n", $3, entorno_actual->id_entorno, $5);
                }
                free($3);
         }
         ;


loop : FOR {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}'('declaracion condicion_loop';' loop_consecuencia')' '{' {
            nivel_indentacion++; 
    }
    instrucciones '}' {
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
    | WHILE '(' expresion_loop ')''{' {
        /* Acción intermedia: Abrimos entorno y loop */
        imprimir_indentacion();
        fprintf(yyout_py, "while %s:\n", $3);
        nivel_indentacion++;
        free($3); // Liberamos el string de la expresión
    } instrucciones '}' {    
        nivel_indentacion--;
    }
    ;
     

condicion_loop : expresion_loop '=' expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s = %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion_loop '>' expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s > %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion_loop '<' expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s < %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion_loop MAYOR_IGUAL expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s >= %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion_loop MENOR_IGUAL expresion_loop { // NUMERO '<=' ID
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s <= %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
               | expresion_loop IGUAL_IGUAL expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s == %s:\n", $1, $3);
                    nivel_indentacion++;
                    free($1); free($3);
            }
            | expresion_loop {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", $1);
                    nivel_indentacion++;
                    free($1);
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
                
                ;

expresion_loop : ID {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", $1);
                    $$ = strdup($1); 
                } else {
                    // Si existe, generamos su nombre real de Python con su entorno: ej "i_1"
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    $$ = strdup(buf);
                }
                free($1);
          }
          | NUMERO {
                char buf[50];
                sprintf(buf, "%g", $1);
                $$ = strdup(buf);
          }
          | expresion_loop '+' expresion_loop {
                char buf[256];
                sprintf(buf, "%s + %s", $1, $3);
                $$ = strdup(buf);
                free($1); free($3); // Limpiamos memoria de los hijos
          }
          | expresion_loop '-' expresion_loop {
                char buf[256];
                sprintf(buf, "%s - %s", $1, $3);
                $$ = strdup(buf);
                free($1); free($3);
          }
          | expresion_loop '*' expresion_loop {
                char buf[256];
                sprintf(buf, "%s * %s", $1, $3);
                $$ = strdup(buf);
                free($1); free($3);
          }
          | '(' expresion_loop ')' {
                char buf[256];
                sprintf(buf, "(%s)", $2);
                $$ = strdup(buf);
                free($2);
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