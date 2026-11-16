# Casos de prueba del traductor

Estos archivos estan separados en casos exitosos y casos con errores. 
## Como ejecutar

Abrir la terminal **MSYS2 UCRT64** y ubicarse en la raiz del proyecto:

```bash
lex lexico.l
yacc parser.y
gcc y.tab.c -o compilador.exe
./compilador.exe casos_prueba/exitosos/01_variables_condicionales_loops.c salida.py
```

Para probar todos manualmente, cambiar el archivo de entrada por cualquiera de los `.c` listados abajo.

## Casos exitosos

### `exitosos/01_variables_condicionales_loops.c`

Funcionalidades probadas:

- Declaracion de variables y constantes.
- Asignaciones.
- `for` traducido a `while`.
- `while`.
- `if/else`.
- Incremento `contador++`.
- Reglas de ambito dentro del `for`.

Resultado esperado:

- No deberia emitir errores.
- Debe generar un `.py` con variables renombradas por entorno, por ejemplo `global_0`, `i_1`, etc.

### `exitosos/02_funciones_y_llamadas.c`

Funcionalidades probadas:

- Funcion con retorno.
- Procedimiento `void`.
- Parametros.
- Llamadas a funcion desde expresiones.
- Llamadas a procedimiento como instruccion.
- `return`.

Resultado esperado:

- No deberia emitir errores.
- Debe generar funciones Python con `def sumar(...)` y `def mostrar(...)`.

### `exitosos/03_arrays_switch_scope.c`

Funcionalidades probadas:

- Array multidimensional.
- Inicializador anidado.
- Acceso a array.
- `switch/case/default`.
- Variable local dentro de un `for`.

Resultado esperado:

- No deberia emitir errores.
- Debe traducir el `switch` usando `match`.
- La variable local del `for` debe quedar con el sufijo del entorno del ciclo.

### `exitosos/04_tipos_y_comentarios.c`

Funcionalidades probadas:

- Tipo `double`.
- Literales de tipo `char`.
- Comentarios de una linea y de bloque.

Resultado esperado:

- No deberia emitir errores.
- Debe generar un `.py` con los valores equivalentes y sin los comentarios de entrada.

## Casos con errores

### `con_errores/01_error_lexico.c`

Error probado:

- Caracter invalido `@`.

Mensaje principal esperado:

```text
Error léxico: caracter inválido @
```

Nota: tambien puede aparecer un `Error sintáctico en la línea 2: syntax error` y el mensaje de recuperacion de instruccion mal formada, porque el parser intenta seguir leyendo luego del caracter invalido.

### `con_errores/02_redeclaracion.c`

Error probado:

- Redeclaracion de variable en el mismo ambito.

Mensaje esperado:

```text
Error semántico: la variable 'x' ya fue declarada.
```

### `con_errores/03_variable_no_declarada.c`

Error probado:

- Uso de variable no declarada en una asignacion.

Mensaje esperado:

```text
Error semántico: la variable 'x' no existe.
```

### `con_errores/04_constante_sin_tipo.c`

Error probado:

- Declaracion `const` sin tipo de dato.

Mensajes esperados:

```text
[Error de Tipos] Línea 1: No se puede asignar un valor de tipo 'int' a la variable 'x' (tipo 'desconocido').
[Error de Sintaxis] Línea 1: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).
```

El primer mensaje aparece porque, al faltar el tipo, la tabla de simbolos queda con tipo desconocido antes de que se dispare el mensaje especifico de `const` sin tipo.

### `con_errores/05_reasignar_constante.c`

Error probado:

- Reasignacion de una constante.

Mensaje esperado:

```text
[Error de Tipos] Línea 2: No se puede reasignar la constante 'limite'.
```

### `con_errores/06_perdida_precision.c`

Error probado:

- Asignar un valor `float` a una variable `int`.

Mensaje esperado:

```text
[Warning] Línea 1: Posible pérdida de precisión al asignar 'entero' (tipo int) con un valor de tipo float.
```

### `con_errores/07_parametros_funcion.c`

Error probado:

- Llamada a funcion con cantidad incorrecta de parametros.

Mensaje esperado:

```text
[Error de Tipos] Línea 5: La función 'sumar' espera 2 parámetro(s) pero se le pasaron 1.
```

### `con_errores/08_case_no_constante.c`

Error probado:

- Uso de variable como valor de `case`.

Mensaje esperado:

```text
[Error Semántico] Línea 5: El valor del 'case' debe ser una constante, no una variable ('variable_0').
```

### `con_errores/09_indice_array_invalido.c`

Error probado:

- Indice de array mal formado.

Mensaje principal esperado:

```text
[Error Sintáctico] Línea 2: Índice de array inválido.
```

Nota: tambien puede aparecer antes `Error sintáctico en la línea 2: syntax error`, que es el mensaje generico de Yacc antes de la recuperacion especifica.

### `con_errores/10_asignacion_invalida.c`

Error probado:

- Asignacion sin expresion del lado derecho.

Mensaje esperado:

```text
[Error Sintáctico] Línea 2: Asignación inválida para 'x'. Falta o está mal formada la expresión del lado derecho.
```

Nota: tambien puede aparecer antes `Error sintáctico en la línea 2: syntax error`.

### `con_errores/11_funcion_no_declarada_expr.c`

Error probado:

- Llamada a una funcion inexistente dentro de una expresion.

Mensaje esperado:

```text
Error semantico: la funcion 'foo' no existe.
```

### `con_errores/12_scope_bloques.c`

Error probado:

- Uso de variables declaradas dentro de bloques `while`, `if/else` y `switch` fuera de su entorno.

Resultado esperado:

- Debe informar que `dentro_while`, `dentro_if`, `dentro_else` y `dentro_switch` no existen al intentar utilizarlas fuera de sus respectivos bloques.
