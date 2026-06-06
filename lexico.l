%{
#include "y.tab.h"  /* Acá Yacc le va a pasar a Flex la lista de tokens (INT, FLOAT, ID...) */
#include <string.h>
%}

delim   [ \t\n]
ws      {delim}+
letra   [A-Za-z_]
digito  [0-9]
id      {letra}({letra}|{digito})*
numero  {digito}+(\.{digito}+)?

%%
{ws}        { /* Ignorar espacios en blanco */ }

"if"        { return(IF); }
"else"      { return(ELSE); }
"while"     { return(WHILE); }
"return"    { return(RETURN); }

"int"       { return(INT); }
"float"     { return(FLOAT); }
"char"      { return(CHAR); }
"const"     { return(CONST); }

{id}        { yylval.nombre = strdup(yytext); return(ID); }
{numero}    { yylval.val_num = atof(yytext); return(NUMERO); }

"{"         { return('{'); }
"}"         { return('}'); }
"*"         { return('*'); }
"="         { return('='); }
";"         { return(';'); }

.           { printf("Error léxico: caracter inválido %s\n", yytext); }
%%
