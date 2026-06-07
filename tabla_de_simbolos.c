#include <stdio.h>
#include <string.h> //strcmp y esas funciones
#include <stdlib.h>

#define T_VOID   1
#define T_CHAR   2
#define T_INT    3
#define T_FLOAT  4
#define T_DOUBLE 5

// 1. Definimos cómo es una "fila" de nuestra planilla (el struct)
struct entrada_tabla {
    char *nombre;        // Nombre de la variable (ej: "mi_puntero")
    int tipo_base;       // T_INT, T_CHAR, T_FLOAT, etc.
    int es_constante;    // 0 = variable, 1 = constante
    int cant_asteriscos; // 0 = normal, 1 = *, 2 = **, etc.
    int es_unsigned;     // 0 = signed (por defecto), 1 = unsigned
    int es_long;         // 0 = normal, 1 = long, 2 = long long
    int es_short;
    
};

struct Entorno {
    struct entrada_tabla *tabla_simbolos; // El "Excel" exclusivo de ESTE bloque
    int cantidad_simbolos;                // Cuántos usó ESTE bloque
    int capacidad_tabla;                  // Capacidad de ESTE bloque
    
    struct Entorno *padre;                // ¡La clave! Puntero al entorno de afuera
};
struct Entorno *entorno_actual = NULL;

/*
---EXPLICACION DE COMO SE MANEJA EL SCOPE--
Al principio de todo (Ámbito Global): Creamos un Entorno para las variables globales. 
Como no hay nada afuera de él, su puntero padre es NULL. 
Nuestro entorno_actual apunta aquí.
Cuando Yacc ve un { (Entrar a un bloque): Creamos un nuevo struct Entorno en memoria. 
Le decimos: "Che, tu padre es el entorno_actual", y acto seguido, 
actualizamos nuestro puntero global: entorno_actual = nuevo_entorno;. 
¡Ahora todo lo que se declare se guardará en esta nueva sub-tabla!
*/


struct entrada_tabla *buscar_variable(char *nombre_buscado) {
    struct Entorno *aux = entorno_actual;
    
    while (aux != NULL) {
        for (int i = 0; i < aux->cantidad_simbolos; i++) {
            if (strcmp(aux->tabla_simbolos[i].nombre, nombre_buscado) == 0) {
                return &aux->tabla_simbolos[i]; // ¡Encontrada en algún scope!
            }
        }
        aux = aux->padre; // Sube al padre
    }
    return NULL; // No existe en ningún lado
}

struct entrada_tabla *declarar_variable(char *nombre_buscado) {
        
        for (int i = 0; i < entorno_actual->cantidad_simbolos; i++) {
        if (strcmp(entorno_actual->tabla_simbolos[i].nombre, nombre_buscado) == 0) {
            return NULL; // ¡Error! Ya existe en este mismo bloque.
        }
    }
    

    // 2. CONTROL DE ESPACIO: Si el bloque se llenó, lo agrandamos
    if (entorno_actual->cantidad_simbolos >= entorno_actual->capacidad_tabla) {
        // Si la capacidad es 0, empezamos con 10. Si ya tenía tamaño, lo duplicamos (* 2)
        entorno_actual->capacidad_tabla = (entorno_actual->capacidad_tabla == 0) ? 10 : entorno_actual->capacidad_tabla * 2;
        
        // realloc se encarga de reubicar y agrandar nuestro "Excel" en la memoria
        entorno_actual->tabla_simbolos = (struct entrada_tabla *) realloc(entorno_actual->tabla_simbolos, entorno_actual->capacidad_tabla * sizeof(struct entrada_tabla));
        
        if (entorno_actual->tabla_simbolos == NULL) {
            fprintf(stderr, "Error fatal: Nos quedamos sin memoria ram.\n");
            exit(1);
        }
    }

    //Como no existe la variable dentro de la tabla,la CREAMOS
    struct entrada_tabla *nueva_fila = &entorno_actual->tabla_simbolos[entorno_actual->cantidad_simbolos];
    nueva_fila->nombre = strdup(nombre_buscado); // Guardamos el nombre (una sola vez)
    nueva_fila->tipo_base = 0;       // Corregido: tipo_base en vez de tipo
    nueva_fila->es_constante = 0;    // Por defecto no es constante
    nueva_fila->cant_asteriscos = 0; // Por defecto es variable normal (no puntero)
    nueva_fila->es_unsigned = 0;     // Por defecto es signed
    nueva_fila->es_long = 0;         // Por defecto no es long
    nueva_fila->es_short = 0;        // Por defecto no es short
    /*
    pregunté por qué es necesario declarar qué valores tienen los campos del
    estruct:
    si en el codigo se declara int x; yacc pondrá que es un entero,
    Qué pasa con los otros campos del struct, y Como nadie los puso en 0, 
    el campo cant_asteriscos va a tener cualquier 
    número loco que hubiera en la RAM (por ejemplo, 32764). 
    Cuando más adelante intentes sumar variables, 
    tu compilador va a mirar la tabla, va a ver ese número y 
    va a decir: "¡Epa! x no es un entero normal, 
    ¡es un puntero con 32.764 asteriscos!", y te va a 
    tirar errores semánticos por todos lados.*/


    entorno_actual->cantidad_simbolos++; // Ahora tenemos una fila más ocupada
    return nueva_fila; // Devolvemos el puntero a la nueva fila creada
}