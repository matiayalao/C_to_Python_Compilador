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
                
                /* Caso base: int x; -> El nombre está en $1 */
                struct entrada_tabla *entrada = declarar_variable($1);
            
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $1);
                } else {
                    entrada->tipo_base = tipo_actual;

                    if(es_constante_actual == 1){
                        entrada->es_constante = 1;
                    }

                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
    			    fprintf(yyout_py, "%s = None\n", $1);
                }
                free($1); /* Limpiamos el strdup que vino de Flex */
         }
         | lista_ids ',' ID {
                /* Caso recursivo: int x, y; -> El nombre está en $3 */
                struct entrada_tabla *entrada = declarar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;

                    if(es_constante_actual == 1){
                        entrada->es_constante = 1;
                    }
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    fprintf(yyout_py, "%s = None\n", $3);
                }
                free($3);
         }
         | ID '=' NUMERO {
            struct entrada_tabla *entrada = declarar_variable($1);
            
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $1);
                } else {
                    entrada->tipo_base = tipo_actual;
                    if(es_constante_actual == 1){
                        entrada->es_constante = 1;
                    }
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
    			    fprintf(yyout_py, "%s = %g\n", $1, $3);
                }
                free($1);
         }
         | lista_ids ',' ID '=' NUMERO {
                /* Caso recursivo: int x, y; -> El nombre está en $3 */
                struct entrada_tabla *entrada = declarar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;

                    if(es_constante_actual == 1){
                        entrada->es_constante = 1;
                    }
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    fprintf(yyout_py, "%s = %g\n", $3, $5);
                }
                free($3);
         }
         ;

loop : FOR'('declaracion condicion_loop';' loop_consecuencia')' '{' instruccion '}'
     | WHILE '('

condicion_loop : ID '=' NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                 if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | NUMERO '=' ID {
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
               | NUMERO '>' ID {
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
               | ID '>' NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | ID '<' NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | NUMERO '<' ID {
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
               | ID MAYOR_IGUAL NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | NUMERO MENOR_IGUAL ID { // NUMERO '<=' ID
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
               | ID MENOR_IGUAL NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | NUMERO MAYOR_IGUAL ID {
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
               | ID IGUAL_IGUAL NUMERO {
                struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
               | NUMERO IGUAL_IGUAL ID {
                struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
            }
            ;

loop_consecuencia: ID {
                    struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
            }
                | ID'+''+' {
                    struct entrada_tabla *entrada = buscar_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $1);
                }
                }
                |  '-''-'ID {
                        struct entrada_tabla *entrada = buscar_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", $3);
                }
                }
                |
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