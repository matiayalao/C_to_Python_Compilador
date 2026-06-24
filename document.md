Trabajo Práctico
Matías Ayala y Hector Bernal

1. Tabla de símbolos

El primer archivo con el que afrontamos este trabajo práctico fue la creación y uso
de la tabla de símbolos. La tabla de símbolos actúa como la memoria semántica del
compilador durante la fase de análisis. En el archivo tabla_de_simbolos.c,  cada
símbolo es un struct entrada_tabla que tiene los campos que un compilador
necesita, como su nombre (por ejemplo, “mi_variable_x”), su tipo (si es entero,
character, etc) que se maneja con los define definidos previamente, si tiene
modificaciones como long o unsigned, y para solucionar el tema de punteros a
punteros a punteros…, también se guarda la cantidada de * (asteriscos) que una
variable pueda tener.

También se usa el struct Entorno para solucionar el problema de los scopes: el libro
habla sobre lo importante que es saber distinguir entre las variables de un scope y
de otro, entonces cada entorno sería como el scope de cada { bloque_de_codigo },
cada scope tiene su propia tabla de símbolos (por eso la línea de
struct entrada_tabla *tabla_simbolos;
dentro del Estruct Entorno). Se tiene también la info de si este entorno tiene un
entorno padre, que se usa mucho en la función *busca_variable. Los enteros de
cantidad (cantidad_simbolos y capacidad_tabla son para poder manejar mejor el
realloc y no quedarnos sin espacio en la tabla de símbolos de cada entorno (scope)).

La parte importante ahora, las funciones. El primer prototipo tenía solo 1 funcion (en
el código actual es la función *declara_variable) que revisaba si el parámetro nombre
de la variable que se pasó para la función ya existía en la tabla de símbolos. Este
prototipo no manejaba ni entornos (scopes) por lo que el futuro análisis sintáctico no
iba a poder decirle a esta función que una variable NO estaba siendo declarada, sino
ya siendo usada por la declaración previamente definida. Entonces con el segundo
prototipo se elimina esa función y se implementa el tema del entorno y una función
que ve el entorno padre (un while (padre != NULL) ) para poder buscar la variable en
todos los scopes. El problema que surgió es obvio, no se podía declarar variables,
entonces nace el tercer prototipo, donde ya se tiene dos funciones, uno donde el
análisis sintáctico llama a *buscar_variable (búsqueda ascendente) si la variable NO
está siendo declarada, y *declara_variable si sí.

NOTA: también se añadieron las variables enteras id_entorno_delclarado y
id_entorno, para solucionar un problemón con la forma que c permite usar al usuario
el for

2. Archivo .lex

El archivo más aburrido pero de igual importancia que los otros dos.
El analizador léxico fue construido utilizando la herramienta Flex (o Lex). Su principal
responsabilidad es leer el código fuente carácter por carácter y agruparles en tokens
para dárselas a yacc (el analizador sintáctico).

  • Reconocimiento de Palabras Reservadas y Tipos: Se implementaron reglas exactas para
identificar estructuras de control: if, else, while, for, return y tipos de datos de C: int, float,
char, const

  • Identificadores ( id ): Se definió una expresión regular que permite reconocer nombres de
variables o funciones. Comienzan obligatoriamente con una letra y pueden ser seguidos por
combinaciones de letras y dígitos. Cuando se detecta un identificador, se extrae y copia su
valor mediante strdup(yytext) para enviarlo a yacc a través de  yylval.nombre .

  • Constantes Numéricas ( numero ): Se definió una única expresión regular capaz de
detectar números enteros y de punto flotante. Su valor se convierte con atof(yytext) y se
envía al parser en la variable  yylval.val_num

  • Operadores y Delimitadores: Se añadieron tokens para operadores relacionales ( == ,  <=
,  >= ), matemáticos ( + ,  - ,  * ), asignación ( = ), delimitadores de bloque ( { ,  } ) y signos
de puntuación o agrupación ( ; ,  , ,  ( ,  ) ).

  • Ignorado de Blancos: Los espacios, tabulaciones y saltos de línea son consumidos y
descartados silenciosamente mediante una expresión regular, ya que no aportan semántica
relevante a yacc.

  • Seguimiento de Líneas: Se habilitó la directiva  %option yylineno  que lleva la cuenta
automática de en qué línea se encuentra leyendo el analizador, añadí esto para poder
informar mejor al usuario sus errores al compilar.

  Para la detección de errores a nivel léxico se implementó la técnica de menor prioridad.
Como Lex/Flex evalúa las expresiones de arriba hacia abajo y siempre toma la coincidencia
más larga, el punto ( . ) atrapa de a un carácter por vez cualquier símbolo suelto que no
haya coincidido con ninguna regla válida del lenguaje (por ejemplo, un  @  o un  $ ). Al caer
en esta regla, el traductor emite el mensaje: "Error léxico: caracter inválido..." en la terminal.

1. Archivo de yacc (parser.y)

La parte más interesante y desafiante del trabajo práctico, vayamos punto por punto:
- Preparando terreno: como primera parte, tenemos las librerías necesarias para
poder usar las funciones útiles de c, y tambien traemos el código de la tabla de
símbolos. Tambien, algo interesante, es la declaración de la función
int yylex(void); una declaración de de funcion necesaria al comienzo del
archivo, y esto es interesante ya que el libro no lo hace, pero en las versiones
actuales de yacc, es necesario ponerlo porque al compilarlo aparece

El error es interesante ya que esto no tendría que pasar, ya que al final del archivo,
está la línea:
#include "lex.yy.c" , pero como dije, las versiones de yacc necesitan que ya
declares antes esta función yylex()
Otra parte interesante de este bloque es la de

Esta directiva es salvatore. Por defecto, Bison asume que el valor semántico de
todos los tokens y no-terminales es simplemente un entero. Y para este trabajo
práctico, necesitamos más que eso, entonces yacc ofrece esta solución para poder
manejar distintos tipos de datos como el nombre o identificador de una variable o el
valor de un literal numérico (un número real: double). Esto se completa con el bloque
de la declaración de tokens, donde asignamos al token ID el compartimiento de un
array de caracteres con la etiqueta
%type <nombre> loop_consecuencia
%type <nombre> ID

-Las gramáticas: la primera gramática que usa el compilador es la de:

Esto originalmente no era así, gran parte del tiempo haciendo este tp, se empezaba
esta gramática, osea el programa debía empezar sí o sí con ‘{‘ y terminar con ‘}’,
cosa que en c no pasa, entonces intenté solucionar añadiendo la producción
‘instrucciones’ a la gramática de bloque y…

El problema fue que había un bucle infinito entre las gramáticas bloque,
instrucciones e instruccion, ya que una instruccion podría ser un bloque, un bloque
podría ser una instrucciones, e instrucciones podía ser epsilon. Osea, con la nada,

podía reducir a instrucciones, reducir a bloque, bloque a instrucción, e instruccion a
instrucciones, pudiendo hacer esto infinitas veces (por eso número tan grande como
70, pero me parece raro que paró ahí, ha de ser un número de emergencia de yacc).
Esto se solucionó con la gramática de ‘programa’ que mostré, ya que el programa no
es produccion de ninguna gramática.
-instrucción: con esta gramática, hago de todo. Acá meto todas las funcionalidades
que pide el tp, como declarar variables, loops, condicionales, etc.
-Declaraciones de variables y constantes (tabla de símbolos): logré
que el compilador procese cosas como int a, b = 5, c; de una sola vez, soportando
variables con o sin valor inicial en la misma línea sin romper el análisis. Esto gracias
a la gramática de:

Creé también una regla intermedia para capturar la palabra clave const antes de leer
los identificadores. De esta forma, activo una bandera global y sé exactamente
cuáles variables marcar como constantes en la tabla de símbolos.

C tiene cosas medio raras en los scopes de algunas funciones, como los for o los
while, se explicará con más detalle posteriormente, cuando entremos en la
explicación de los loops, pero ahora saber nomas que una variable x en el código c,
tendrá su equivalente x_i en el código de python, siendo i un número entero que
representa el “scope” en el que se declaró

Antes de registrar cualquier variable, el compilador verifica si ya existe en el entorno
actual. Si se detecta una REDECLARACIÓN, frena el proceso y lanza un error
semántico explícito (acá se usan mucho las funciones dentro de la
tabla_de_simbolos.c)

La mayor dificultad de este primer aspecto fue que fue el primero: como comenzaba
a crear el archivo, comencé a conectar con el parser.y  con los otros dos archivos, la
tabla_de_simbolos.c y el lexico.l, entonces tuve que leer el libro, revisar mi
presentación (tuve la suerte de que fui el que presentó la unidad de yacc), preguntar
a IA’s, prueba y error; básicamente, entender como lo que era el flujo del trabajo
práctico, y sumarle a hacer las gramáticas en sí: probar qué se puede hacer en c y
qué no, tomar en cuenta que una variable puede ser constate, de por qué el parser
no reducía a ciertas producciones, etc.

-Ciclos (loops)


