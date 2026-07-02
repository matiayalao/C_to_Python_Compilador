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

Conflictos Shift/Reduce: Cuando quisimos hacer que la inicialización del for
soportara tanto declarar variables nuevas (int i = 0) como reasignar variables ya
existentes ( i=0 ), yacc se volvió loco y nos escupió advertencias de shift/reduce y
reduce/reduce conflicts. El problema técnico era que nuestras gramáticas de
"declaración" y "asignación" empezaban igual (ambas con un  ID ), entonces cuando
yacc leía el primer  ID  (ej:  i = 0 ), no sabía por cuál de los dos caminos ir, y
terminaba bloqueando o ignorando reglas por la ambigüedad. Vivimos en carne
propia ejemplos de conflictos sobre los que hablaba el libro. La solución fue separar

limpiamente las responsabilidades desde el origen: obligamos a que una
declaración  siempre empiece con un tipo explícito (como int o float ), y creamos una
regla separada llamada  asignacion_unitaria  para cuando la instrucción arranca
directamente con la variable. Luego, creamos la regla  for_init  que acepta cualquiera
de las dos opciones por separado.

La mayor dificultad de este primer aspecto fue que fue el primero: como comenzaba
a crear el archivo, comencé a conectar con el parser.y  con los otros dos archivos, la
tabla_de_simbolos.c y el lexico.l, entonces tuve que leer el libro, revisar mi
presentación (tuve la suerte de que fui el que presentó la unidad de yacc), preguntar
a IA’s, prueba y error; básicamente, entender como lo que era el flujo del trabajo
práctico, y sumarle a hacer las gramáticas en sí: probar qué se puede hacer en c y
qué no, tomar en cuenta que una variable puede ser constante, de por qué el parser
no reducía a ciertas producciones, etc.

-Ciclos (loops): Para los ciclos hicimos gramática para while y for. Lo primero y
más interesante de esta parte es cómo traducimos el for de C a Python. Como
Python maneja sus ciclos for de una forma muy rara (iterando sobre listas o rangos
en lugar de usar contadores puros), decidimos que la forma menos complicada para
nosotros era traducir el for de C en un while de Python. Así, un  for(int i = 0; i < 10;
i++)  se convierte en una inicialización previa (después explico el problemón que fue
esta parte), seguida de un  while i < 10: , y el paso ( i += 1 ) se inyecta al final del
bloque de instrucciones generado.

El manejo de scopes (entornos): Algo vital que implementamos es que cada ciclo
abre su propio entorno. Cada vez que el parser detecta un for o un while, hacemos
un malloc para un nuevo Entorno, lo enlazamos con el  entorno_actual  como padre
y aumentamos el contador_entornos. Para qué este sarambi? esto permite que si el
usuario declara un  int z = 90;  dentro del loop, esa variable "nazca y muera" ahí
adentro. Al encontrar la llave de cierre  ‘}’ , volvemos al entorno padre y destruimos
(liberamos) el entorno local del ciclo. Gracias a esto, si se intenta usar z fuera del
bucle, el compilador frena y lanza un "Error semántico: la variable 'z' no existe",
demostrando que nuestra tabla de símbolos y memoria semántica funcionan bien.

El desafío de la indentación: El tema tabú que no pudimos aplazar más: en C, que
se usa llaves  { }  para delimitar los bloques, a Python, que separa los bloques con la
indentación, tuvimos que crear una variable global nivel_indentacion  y una función
auxiliar  imprimir_indentacion() . La lógica dice que cada vez que abrimos la llave de
un ciclo, hacemos  nivel_indentacion++ , y al cerrarla  nivel_indentacion-- . Parecía
fácil, pero tuvimos un bug bastante molesto donde la indentación de Python se iba
"arrastrando" hacia la derecha de forma infinita (doblando y triplicando los espacios).

Esto ocurrió porque, sin darnos cuenta, incrementábamos la variable dos veces: una
vez al evaluar la condición del loop y otra vez al abrir la llave. Por suerte, pudimos
rastrearlo y ajustar el contador para que la generación de espacios quede impecable
en el  .py . Aunque esta función nueva ya se usó en gramáticas anteriores, su
creación e implementación fue recién en la creación de las gramáticas de los loops.

Condicionales (IF y SWITCH): Con el IF fuimos un poco más rápido
porque ya le habíamos agarrado bien a la dinámica de yacc sobre la creación de
gramáticas. Al comienzo, el bloque de la condición del IF estaba como que
hardcodeado, más o menos así:

Pero con la creación de la gramática de ‘expresiones’, TODO se volvió mas fluido:

Algo simpático que aprendí gracias a esta parte del trabajo es que python ya no
permite condicionales así:

Esto es porque en C, se dieron cuenta que al permitir eso, se causaban muchísimos
errores porque los programadores normalmente querían poner ‘x == 20’ y no ‘x=20’.
Pusimos un error de sintaxis al respecto.

Con la otra condicional (switch) más de lo mismo, el uso de expresión facilitó
bastante el proceso.

-Procedimientos y funciones: Esta fue otra de las partes donde nos
topamos con algunas dificultades, pero nos forzó a implementar conocimientos que
ya habíamos dado en clase. Uno de los primeros problemas fue a nivel léxico, en un
intento de ser súper ordenados, creamos un token específico NOMBRE_FUNCION
con su propia expresión regular, el detalle que se nos escapó fue que esa expresión
regular era idéntica a la de los identificadores comunes (id), y como la regla de id
estaba definida primero, el analizador léxico siempre devolvía el token ID, la regla de
NOMBRE_FUNCION jamás se llegaba a ejecutar

(Imágen ilustrativa, ya no se encuentra en el código)
Gracias a la IA, nos enteramos que en C, el nombre de una función no deja de ser
un identificador, así que borramos nombre_funcion y usamos directamente el token
ID en yacc, diferenciando si es función o variable puramente por la sintaxis (los
paréntesis). Otros problemas, los típicos errores de despiste (no poner la gramática
de las funciones dentro del bloque de ‘instrucciones’, olvidar cerrar los corchetes,
etc)

Nos encontramos también con un conflicto shift/reduce en Yacc, al agregar
funciones que devuelven tipos (como int o float), el compilador nos tiró un warning
de conflicto:

diferenciar entre declarar una variable (int a;) y declarar una función (int a() { ... }),
cuando el parser leía la palabra int (y la reducía a tipo), veía el siguiente token y veía
un ID, y ahí entraba en pánico porque con un lookahead de solo 1 token, no sabía
qué camino tomar: la opción Reduce (reduzco este tipo a un prefijo_declaracion para
preparar el terreno de una variable y ejecutar el código que resetea la bandera de
constante) o la opción Shift (me guardo el tipo y hago shift del ID a la pila para
empezar a construir la regla de la función):

como ambos caminos eran válidos con un ID enfrente, Yacc no sabía qué hacer
La solución fue unificar el inicio de las reglas para posponer la decisión: en lugar de
definir la función arrancando con tipo ID, la hicimos arrancar con prefijo_declaracion
ID (exactamente igual que las variables), de esta forma, al leer int, el parser siempre
lo reduce a prefijo_declaracion, luego lee el ID, y recién ahí, cuando mira el tercer
token, toma la decisión obvia: si viene un paréntesis (, sabe que es la regla de la
función y hace shift; si viene un punto y coma ; o una coma ,, sabe que es una
variable y hace reduce.

-Vectores y Arrays:  pLa creación de la gramática me tomó 10 minutos en
escribir, más por un problema con un conflicto de reduccion/reduccion, pero con el
conflicto anterior de funciones, aprendimo cómo manejarnos mejor con estos
problemas:

Lo que directamente causaba el error era el epsilon, pero el problema venía antes,
no usaba la ventaja del lookahead(1), y arreglamos añadiendole como obligación a
la gramática que vea que debe haber un ‘[‘:

La parte que sí fue todo un desafío fue la parte de inicializar los arrays. UFF.


