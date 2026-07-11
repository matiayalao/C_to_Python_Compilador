%{
#include <string.h>
%}

%option yylineno
%option noyywrap
delim   [ \t\n]
ws      {delim}+
letra   [A-Za-z_]
digito  [0-9]
id      {letra}({letra}|{digito})*
numero  {digito}+(\.{digito}+)?
caracter \'([^\\'\n]|\\[nrt0\\'])\'


%%
{ws}        { /* Ignorar espacios en blanco */ }
"//".*      { /* Ignorar comentarios de una linea */ }
"/*"([^*]|\*+[^*/])*\*+"/"    { /* Ignorar comentarios de bloque */ }

"if"        { return(IF); }
"else"      { return(ELSE); }
"while"     { return(WHILE); }
"switch"    { return(SWITCH); }
"case"      { return(CASE); }
"break"     { return(BREAK); }
"default"   { return(DEFAULT); }
"return"    { return(RETURN); }
"for"       { return(FOR); }

"int"       { return(INT); }
"float"     { return(FLOAT); }
"double"    { return(DOUBLE); }
"char"      { return(CHAR); }
"const"     { return(CONST); }
"void"      { return(VOID); }

{caracter}  { yylval.nombre = strdup(yytext); return(CARACTER); }
{id}        { yylval.nombre = strdup(yytext); return(ID); }
{numero}    { yylval.val_num = atof(yytext); return(NUMERO); }

"{"         { return('{'); }
"}"         { return('}'); }
"["         { return('['); }
"]"         { return(']'); }
"*"         { return('*'); }
"="         { return('='); }
"=="        { return(IGUAL_IGUAL); }                                 
"!="        { return(NO_IGUAL); }
"<="        { return(MENOR_IGUAL); }                                 
">="        { return(MAYOR_IGUAL); }
"&&"        { return(AND); }
"||"        { return(OR); }                                 
";"         { return(';'); }
","         { return(','); }
"+"         { return('+'); }                                  
"-"         { return('-'); }                                  
"<"         { return('<'); }                                  
">"         { return('>'); }
"("         { return('('); }
")"         { return(')'); }
":"         { return(':'); }
"!"         { return('!'); }
"%"         { return('%'); }
"/"         { return('/'); }

.           { printf("Error léxico: caracter inválido %s\n", yytext); }
%%
