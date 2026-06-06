%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Importamos tu lógica rústica de la tabla de símbolos */
#include "tabla_simbolos.c"

void yyerror(const char *s);
int yylex(void); 

int tipo_actual = 0;
%}

/* CONFIGURAMOS LA UNION PARA TRABAJAR CON STRINGS*/
%asis
%union {
    char *nombre;     /* Para transportar el nombre de los identificadores */
    double val_num;   /* Por si usás números más adelante */
}

/* DECLARAMOS LOS TOKENS Y LE ASIGNAMOS EL TIPO DE LA UNION A ID */
%token IF ELSE WHILE RETURN INT FLOAT CHAR CONST DOUBLE
%token <nombre> ID

%%

programa: bloque
        ;

/* REGLA BLOQUE: Maneja el Scope de forma inline y rústica aquí mismo */
bloque: '{' {
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

instrucciones: instrucciones instruccion 
             | /* vacío (regla lambda) */
             ;

/* AQUÍ ESTÁ EL SECRETO: Una instrucción puede ser una declaración O un bloque nuevo */
instruccion: declaracion 
           | bloque
           ;

declaracion: tipo lista_ids ';'
           ;

/* Corregidos los puntos y comas internos de C */
tipo: INT    { tipo_actual = T_INT; }
    | FLOAT  { tipo_actual = T_FLOAT; }
    | CHAR   { tipo_actual = T_CHAR; }
    | DOUBLE { tipo_actual = T_DOUBLE; }
    ;

lista_ids: ID {
                /* Caso base: int x; -> El nombre está en $1 */
                struct entrada_tabla *entrada = declara_variable($1);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $1);
                } else {
                    entrada->tipo_base = tipo_actual;
                }
                free($1); /* Limpiamos el strdup que vino de Flex */
         }
         | lista_ids ',' ID {
                /* Caso recursivo: int x, y; -> El nombre está en $3 */
                struct entrada_tabla *entrada = declara_variable($3);
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada en este bloque.\n", $3);
                } else {
                    entrada->tipo_base = tipo_actual;
                }
                free($3);
         }
         ;

%%

/* Inclusión rústica del analizador léxico al final del archivo */
#include "lex.yy.c"

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico: %s\n", s);
}