/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Importamos tu lógica rústica de la tabla de símbolos */
#include "tabla_de_simbolos.c"

void yyerror(const char *s);
int yylex(void); 

int tipo_actual = 0;
int es_constante_actual = 0;
int contador_parametros = 0;

#define MAX_PARAMS 32
// Buffer que se llena mientras se parsea la DECLARACIÓN de una función
int tipos_params_actuales[MAX_PARAMS];
// Buffer que se llena mientras se parsea la LLAMADA a una función
int tipos_args_actuales[MAX_PARAMS];


extern int yylineno; //contador de lineas

extern FILE *yyin; // Variable que usa Lex para leer la entrada         
FILE *yyout_py;    // Nuestra variable para escribir la salida Python 
int nivel_indentacion = 0; 
void imprimir_indentacion() {
    for (int i = 0; i < nivel_indentacion; i++) {
        fprintf(yyout_py, "    "); // Imprime 4 espacios por nivel
    }
}

int max_tipo(int t1, int t2) {
    if ((t1 == T_INT || t1 == T_FLOAT || t1 == T_DOUBLE) &&
        (t2 == T_INT || t2 == T_FLOAT || t2 == T_DOUBLE)) {
        return (t1 > t2) ? t1 : t2;
    }
    return t1;
}

struct InfoExpresion {
        char *codigo;
        int tipo_dato; 
    };


#line 119 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    RETURN = 261,                  /* RETURN  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    CONST = 265,                   /* CONST  */
    DOUBLE = 266,                  /* DOUBLE  */
    FOR = 267,                     /* FOR  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    VOID = 270,                    /* VOID  */
    MAYOR_IGUAL = 271,             /* MAYOR_IGUAL  */
    IGUAL_IGUAL = 272,             /* IGUAL_IGUAL  */
    MENOR_IGUAL = 273,             /* MENOR_IGUAL  */
    NO_IGUAL = 274,                /* NO_IGUAL  */
    BREAK = 275,                   /* BREAK  */
    DEFAULT = 276,                 /* DEFAULT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    ID = 279,                      /* ID  */
    NUMERO = 280                   /* NUMERO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define RETURN 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define CONST 265
#define DOUBLE 266
#define FOR 267
#define SWITCH 268
#define CASE 269
#define VOID 270
#define MAYOR_IGUAL 271
#define IGUAL_IGUAL 272
#define MENOR_IGUAL 273
#define NO_IGUAL 274
#define BREAK 275
#define DEFAULT 276
#define AND 277
#define OR 278
#define ID 279
#define NUMERO 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "parser.y"

    char *nombre;     
    double val_num;   
    struct InfoExpresion *info_expr;

#line 225 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_MAYOR_IGUAL = 16,               /* MAYOR_IGUAL  */
  YYSYMBOL_IGUAL_IGUAL = 17,               /* IGUAL_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 18,               /* MENOR_IGUAL  */
  YYSYMBOL_NO_IGUAL = 19,                  /* NO_IGUAL  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 21,                   /* DEFAULT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_NUMERO = 25,                    /* NUMERO  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '!'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_instrucciones = 46,             /* instrucciones  */
  YYSYMBOL_instruccion = 47,               /* instruccion  */
  YYSYMBOL_declaracion = 48,               /* declaracion  */
  YYSYMBOL_for_init = 49,                  /* for_init  */
  YYSYMBOL_asignacion = 50,                /* asignacion  */
  YYSYMBOL_prefijo_declaracion = 51,       /* prefijo_declaracion  */
  YYSYMBOL_tipo = 52,                      /* tipo  */
  YYSYMBOL_declarar_lista_ids = 53,        /* declarar_lista_ids  */
  YYSYMBOL_lista_asignaciones = 54,        /* lista_asignaciones  */
  YYSYMBOL_asignacion_unitaria = 55,       /* asignacion_unitaria  */
  YYSYMBOL_accesos_array = 56,             /* accesos_array  */
  YYSYMBOL_loop = 57,                      /* loop  */
  YYSYMBOL_58_1 = 58,                      /* $@1  */
  YYSYMBOL_condicion_loop = 59,            /* condicion_loop  */
  YYSYMBOL_loop_consecuencia = 60,         /* loop_consecuencia  */
  YYSYMBOL_expresion = 61,                 /* expresion  */
  YYSYMBOL_condicionales = 62,             /* condicionales  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_bloque_else = 68,               /* bloque_else  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_switch_cases = 73,              /* switch_cases  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_75_12 = 75,                     /* $@12  */
  YYSYMBOL_76_13 = 76,                     /* $@13  */
  YYSYMBOL_condicion_IF = 77,              /* condicion_IF  */
  YYSYMBOL_declaracion_variables_funcion = 78, /* declaracion_variables_funcion  */
  YYSYMBOL_lista_parametros = 79,          /* lista_parametros  */
  YYSYMBOL_80_14 = 80,                     /* $@14  */
  YYSYMBOL_parametro_void = 81,            /* parametro_void  */
  YYSYMBOL_funcion_void = 82,              /* funcion_void  */
  YYSYMBOL_83_15 = 83,                     /* $@15  */
  YYSYMBOL_84_16 = 84,                     /* $@16  */
  YYSYMBOL_funcion_NO_void = 85,           /* funcion_NO_void  */
  YYSYMBOL_86_17 = 86,                     /* $@17  */
  YYSYMBOL_87_18 = 87,                     /* $@18  */
  YYSYMBOL_llamar_funcion = 88,            /* llamar_funcion  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_90_20 = 90,                     /* $@20  */
  YYSYMBOL_usar_variables_funcion = 91,    /* usar_variables_funcion  */
  YYSYMBOL_lista_parametros_llamar_funcion = 92, /* lista_parametros_llamar_funcion  */
  YYSYMBOL_93_21 = 93,                     /* $@21  */
  YYSYMBOL_parametro_llamar_funcion = 94,  /* parametro_llamar_funcion  */
  YYSYMBOL_llamada_funcion_expr = 95,      /* llamada_funcion_expr  */
  YYSYMBOL_usar_variables_funcion_expr = 96, /* usar_variables_funcion_expr  */
  YYSYMBOL_lista_parametros_llamar_funcion_expr = 97, /* lista_parametros_llamar_funcion_expr  */
  YYSYMBOL_volumen_array = 98,             /* volumen_array  */
  YYSYMBOL_dimension_array = 99,           /* dimension_array  */
  YYSYMBOL_arrays = 100,                   /* arrays  */
  YYSYMBOL_asignacion_array = 101,         /* asignacion_array  */
  YYSYMBOL_inicializador_array = 102,      /* inicializador_array  */
  YYSYMBOL_lista_inicializadores = 103,    /* lista_inicializadores  */
  YYSYMBOL_valor_o_anidado = 104           /* valor_o_anidado  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   671

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    32,     2,     2,
      39,    40,    30,    28,    35,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    34,
      26,    36,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    82,    83,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    99,   105,   106,   109,   112,   113,
     116,   118,   119,   122,   123,   124,   125,   128,   142,   156,
     173,   192,   193,   196,   215,   226,   232,   238,   244,   250,
     259,   265,   273,   273,   290,   295,   302,   310,   311,   319,
     327,   338,   354,   370,   373,   385,   394,   402,   411,   419,
     427,   435,   443,   451,   456,   461,   466,   471,   476,   481,
     491,   494,   497,   491,   500,   502,   500,   512,   516,   520,
     512,   524,   524,   533,   536,   544,   536,   547,   547,   555,
     559,   562,   567,   573,   574,   577,   578,   578,   581,   599,
     616,   599,   641,   658,   641,   680,   687,   680,   717,   718,
     721,   722,   722,   725,   736,   771,   772,   775,   783,   795,
     795,   797,   797,   799,   820,   821,   825,   834,   839,   849,
     853
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "FLOAT", "CHAR", "CONST", "DOUBLE", "FOR", "SWITCH",
  "CASE", "VOID", "MAYOR_IGUAL", "IGUAL_IGUAL", "MENOR_IGUAL", "NO_IGUAL",
  "BREAK", "DEFAULT", "AND", "OR", "ID", "NUMERO", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "';'", "','", "'='", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "':'", "$accept", "programa",
  "instrucciones", "instruccion", "declaracion", "for_init", "asignacion",
  "prefijo_declaracion", "tipo", "declarar_lista_ids",
  "lista_asignaciones", "asignacion_unitaria", "accesos_array", "loop",
  "$@1", "condicion_loop", "loop_consecuencia", "expresion",
  "condicionales", "$@2", "$@3", "$@4", "$@5", "$@6", "bloque_else", "$@7",
  "$@8", "$@9", "$@10", "switch_cases", "$@11", "$@12", "$@13",
  "condicion_IF", "declaracion_variables_funcion", "lista_parametros",
  "$@14", "parametro_void", "funcion_void", "$@15", "$@16",
  "funcion_NO_void", "$@17", "$@18", "llamar_funcion", "$@19", "$@20",
  "usar_variables_funcion", "lista_parametros_llamar_funcion", "$@21",
  "parametro_llamar_funcion", "llamada_funcion_expr",
  "usar_variables_funcion_expr", "lista_parametros_llamar_funcion_expr",
  "volumen_array", "dimension_array", "arrays", "asignacion_array",
  "inicializador_array", "lista_inicializadores", "valor_o_anidado", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -190,     7,   451,  -190,   -24,   -21,    56,  -190,  -190,  -190,
       1,  -190,  -190,    10,    31,   -23,    55,    58,  -190,  -190,
    -190,  -190,    70,  -190,    57,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,    97,    -2,  -190,    97,  -190,    97,   579,
    -190,    60,  -190,    69,    59,    97,    78,    79,    89,    97,
      97,  -190,    21,    96,   103,   -10,    90,  -190,    23,    97,
      88,   537,    97,    94,  -190,   465,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,  -190,
      97,  -190,   108,    12,   484,  -190,  -190,  -190,   598,   503,
      97,    97,    97,  -190,  -190,   110,  -190,  -190,   127,  -190,
     558,   101,   112,    97,   598,   111,   102,  -190,   144,   639,
     144,   639,   632,   615,   144,   144,   128,   128,  -190,  -190,
    -190,   598,   118,  -190,    97,  -190,   133,  -190,    68,  -190,
     598,   129,   132,  -190,   598,   520,  -190,   130,    68,    97,
    -190,  -190,   598,  -190,    97,    97,   143,   139,   154,   141,
     148,  -190,  -190,  -190,  -190,   147,   145,   598,   146,   137,
     598,   598,    49,  -190,  -190,  -190,  -190,   155,    97,   110,
     152,  -190,  -190,  -190,   -25,   161,   151,     3,   164,    68,
    -190,  -190,   157,   166,   159,   167,   191,   181,    97,   186,
     170,     3,    97,   169,   171,  -190,  -190,   147,     9,  -190,
    -190,  -190,  -190,  -190,   598,  -190,  -190,  -190,    83,  -190,
    -190,   231,  -190,   598,  -190,    -4,  -190,   269,   210,   307,
    -190,  -190,  -190,     9,  -190,  -190,   213,  -190,  -190,  -190,
     451,  -190,   179,   180,   421,  -190,  -190,   188,    97,   345,
    -190,   183,  -190,     3,  -190,  -190,   185,  -190,   383,  -190,
     210,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,    23,    24,    25,
       0,    26,    42,     0,     0,    39,     0,     0,    17,     3,
       5,     6,     0,    21,     0,    31,     7,     8,     9,    10,
      11,    12,    70,     0,    51,    54,     0,    14,     0,     0,
      53,    27,    22,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,    27,     0,    20,     0,     0,
       0,    46,   116,    52,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,    16,     0,     0,     0,    99,    35,    36,    33,     0,
     109,     0,     0,    37,    38,   120,   102,    15,    39,    32,
      92,     0,     0,     0,   117,     0,   115,    69,    67,    65,
      68,    66,    60,    61,    64,    63,    55,    56,    57,    58,
      59,    29,    28,    18,     0,    19,     0,    74,    94,    40,
     113,     0,   108,   110,    34,     0,   119,     0,    94,     0,
      71,     4,    45,   114,     0,     0,     0,     0,     0,     0,
      93,    95,   106,   111,    41,   122,     0,    91,     0,     0,
     118,    30,     0,    75,    98,   100,    96,     0,     0,   120,
     125,   103,     4,    44,    47,     0,     0,     0,     0,     0,
     107,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,    97,   122,     0,   124,
     123,     4,    72,    48,    50,    49,     4,    89,     0,    87,
      76,     0,   121,   129,   130,     0,   127,     0,    83,     0,
      84,     4,   101,     0,   126,   104,    81,    73,    43,     4,
      88,   128,     0,     0,     0,    77,     4,     0,     0,     0,
      85,     0,    82,     0,    78,    86,     0,     4,     0,    79,
      83,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -113,  -190,   162,  -190,   165,   168,    -9,   214,
    -190,   172,   193,  -190,  -190,   104,  -190,    -6,  -190,  -190,
    -190,  -190,  -190,  -190,   -19,  -190,  -190,  -190,  -190,  -189,
    -190,  -190,  -190,    -3,    91,  -190,  -190,    71,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
      81,  -190,  -190,  -190,    84,    50,  -190,  -190,    73,  -190,
      29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    19,    20,   124,    21,    22,    23,    56,
      24,    25,    52,    26,    44,    60,   176,    61,    27,    59,
     158,   218,   147,   177,   227,   238,   246,   250,   233,   194,
     229,   243,   221,   101,   149,   150,   179,   151,    28,   128,
     178,    29,   138,   185,    30,    90,   167,   131,   132,   168,
     133,    40,   105,   106,   137,   170,    31,   184,   214,   215,
     216
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    42,   207,   187,   191,    47,    48,     3,     7,     8,
       9,   188,    11,    49,    50,    32,    51,   192,    33,     7,
       8,     9,    10,    11,   193,    41,    80,    95,   159,    96,
      64,   223,    65,    34,    35,    50,    98,    62,   224,    84,
      16,    17,    36,    88,    89,   -90,    18,    98,    38,    45,
     198,    16,    17,   100,   245,    46,   104,    91,    92,   186,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   174,   121,     7,     8,     9,   175,    11,
      34,    35,   211,    53,   130,   134,   135,    54,   217,    36,
      37,    57,    58,   219,    55,    38,    80,   142,    83,    66,
      67,    68,    69,    81,    82,    70,    71,    86,   230,    72,
      73,    74,    75,    76,    77,    78,   234,    85,    87,   148,
      93,    34,    35,   239,    97,    82,   220,    94,   102,   148,
      36,    92,   122,   157,   248,   136,    38,   144,   160,   161,
       4,   140,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   143,    14,   141,   145,    47,    48,    41,    76,    77,
      78,    15,   130,    49,    50,    16,    17,   153,   155,   152,
     148,    18,    74,    75,    76,    77,    78,   162,   164,   173,
     163,   165,   204,   166,   169,   171,   208,   172,   183,   180,
     189,   190,   213,   200,     4,   197,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   195,    14,   198,   201,   203,
     205,   206,   209,   210,   226,    15,   232,   213,   235,    16,
      17,   236,   240,   244,    43,    18,   247,    63,   146,   156,
      99,   251,   100,   202,     4,   241,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   123,    14,   212,   125,   181,
     196,   126,   231,   182,     0,    15,   199,     0,     0,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     4,   222,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,    16,    17,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       4,   225,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     4,   228,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    16,    17,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     4,   242,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,    16,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     4,   249,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
       0,   237,     0,     0,     0,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     4,    18,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    16,
      17,    66,    67,    68,    69,    18,     0,    70,    71,     0,
       0,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      66,    67,    68,    69,     0,   107,    70,    71,     0,     0,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    66,
      67,    68,    69,     0,   127,    70,    71,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    66,    67,    68,    69,
       0,   129,    70,    71,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    66,    67,    68,    69,     0,   154,    70,
      71,     0,     0,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,   103,    66,    67,    68,    69,     0,     0,
      70,    71,     0,     0,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,   139,    66,    67,    68,    69,     0,
       0,    70,    71,     0,     0,    72,    73,    74,    75,    76,
      77,    78,     0,    79,    66,    67,    68,    69,     0,     0,
      70,    71,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    66,    67,    68,    69,     0,     0,    70,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    66,    67,
      68,    69,     0,     0,     0,    66,     0,    68,    72,    73,
      74,    75,    76,    77,    78,    72,    73,    74,    75,    76,
      77,    78
};

static const yytype_int16 yycheck[] =
{
       6,    10,   191,    28,     1,    28,    29,     0,     7,     8,
       9,    36,    11,    36,    37,    39,    39,    14,    39,     7,
       8,     9,    10,    11,    21,    24,    36,    37,   141,    39,
      36,    35,    38,    24,    25,    37,    24,    39,    42,    45,
      28,    29,    33,    49,    50,    42,    34,    24,    39,    39,
      41,    28,    29,    59,   243,    24,    62,    36,    37,   172,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    24,    80,     7,     8,     9,    29,    11,
      24,    25,   195,    28,    90,    91,    92,    29,   201,    33,
      34,    34,    35,   206,    24,    39,    36,   103,    39,    16,
      17,    18,    19,    34,    35,    22,    23,    28,   221,    26,
      27,    28,    29,    30,    31,    32,   229,    39,    29,   128,
      24,    24,    25,   236,    34,    35,    43,    24,    40,   138,
      33,    37,    24,   139,   247,    25,    39,    35,   144,   145,
       3,    40,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    40,    15,    41,    36,    28,    29,    24,    30,    31,
      32,    24,   168,    36,    37,    28,    29,    35,    38,    40,
     179,    34,    28,    29,    30,    31,    32,    34,    24,    42,
      41,    40,   188,    35,    37,    40,   192,    41,    36,    34,
      29,    40,   198,    34,     3,    38,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    41,    15,    41,    41,    28,
      24,    41,    43,    42,     4,    24,     3,   223,    39,    28,
      29,    41,    34,    40,    10,    34,    41,    34,   124,   138,
      58,   250,   238,    42,     3,   238,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    83,    15,   197,    83,   168,
     179,    83,   223,   169,    -1,    24,   183,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    42,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    42,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,     3,    42,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    42,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    42,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,     3,    34,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    16,    17,    18,    19,    34,    -1,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      16,    17,    18,    19,    -1,    40,    22,    23,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    16,
      17,    18,    19,    -1,    40,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    16,    17,    18,    19,
      -1,    38,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    16,    17,    18,    19,    -1,    38,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,    16,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    16,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    16,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    16,    17,
      18,    19,    -1,    -1,    -1,    16,    -1,    18,    26,    27,
      28,    29,    30,    31,    32,    26,    27,    28,    29,    30,
      31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    15,    24,    28,    29,    34,    47,
      48,    50,    51,    52,    54,    55,    57,    62,    82,    85,
      88,   100,    39,    39,    24,    25,    33,    34,    39,    61,
      95,    24,    52,    53,    58,    39,    24,    28,    29,    36,
      37,    39,    56,    28,    29,    24,    53,    34,    35,    63,
      59,    61,    39,    56,    61,    61,    16,    17,    18,    19,
      22,    23,    26,    27,    28,    29,    30,    31,    32,    34,
      36,    34,    35,    39,    61,    39,    28,    29,    61,    61,
      89,    36,    37,    24,    24,    37,    39,    34,    24,    55,
      61,    77,    40,    36,    61,    96,    97,    40,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    24,    48,    49,    50,    51,    40,    83,    38,
      61,    91,    92,    94,    61,    61,    25,    98,    86,    36,
      40,    41,    61,    40,    35,    36,    59,    66,    52,    78,
      79,    81,    40,    35,    38,    38,    78,    61,    64,    46,
      61,    61,    34,    41,    24,    40,    35,    90,    93,    37,
      99,    40,    41,    42,    24,    29,    60,    67,    84,    80,
      34,    94,    98,    36,   101,    87,    46,    28,    36,    29,
      40,     1,    14,    21,    73,    41,    81,    38,    41,   102,
      34,    41,    42,    28,    61,    24,    41,    73,    61,    43,
      42,    46,    99,    61,   102,   103,   104,    46,    65,    46,
      43,    76,    42,    35,    42,    42,     4,    68,    42,    74,
      46,   104,     3,    72,    46,    39,    41,    20,    69,    46,
      34,    77,    42,    75,    40,    73,    70,    41,    46,    42,
      71,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    58,    57,    57,    59,    59,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      63,    64,    65,    62,    66,    67,    62,    69,    70,    71,
      68,    72,    68,    68,    74,    75,    73,    76,    73,    73,
      73,    77,    77,    78,    78,    79,    80,    79,    81,    83,
      84,    82,    86,    87,    85,    89,    90,    88,    91,    91,
      92,    93,    92,    94,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   103,   103,   104,
     104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     3,     3,
       5,     1,     3,     3,     4,     3,     3,     3,     3,     1,
       3,     4,     0,    11,     7,     3,     1,     1,     3,     3,
       3,     1,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       0,     0,     0,    11,     0,     0,     9,     0,     0,     0,
      12,     0,     5,     0,     0,     0,     9,     0,     4,     2,
       0,     3,     1,     1,     0,     1,     0,     4,     2,     0,
       0,    10,     0,     0,    10,     0,     0,     7,     1,     0,
       1,     0,     4,     1,     4,     1,     0,     1,     3,     1,
       0,     4,     0,     8,     2,     0,     3,     1,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 13: /* instruccion: RETURN expresion ';'  */
#line 94 "parser.y"
                                  {
                imprimir_indentacion();
                fprintf(yyout_py, "return %s\n", (yyvsp[-1].info_expr)->codigo);
                free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
           }
#line 1579 "y.tab.c"
    break;

  case 14: /* instruccion: RETURN ';'  */
#line 99 "parser.y"
                        {
                imprimir_indentacion();
                fprintf(yyout_py, "return\n");
           }
#line 1588 "y.tab.c"
    break;

  case 15: /* declaracion: prefijo_declaracion declarar_lista_ids ';'  */
#line 105 "parser.y"
                                                         { es_constante_actual = 0; }
#line 1594 "y.tab.c"
    break;

  case 16: /* declaracion: CONST declarar_lista_ids ';'  */
#line 106 "parser.y"
                                           {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
#line 1602 "y.tab.c"
    break;

  case 21: /* prefijo_declaracion: tipo  */
#line 118 "parser.y"
                                       { es_constante_actual = 0; }
#line 1608 "y.tab.c"
    break;

  case 22: /* prefijo_declaracion: CONST tipo  */
#line 119 "parser.y"
                                       { es_constante_actual = 1; }
#line 1614 "y.tab.c"
    break;

  case 23: /* tipo: INT  */
#line 122 "parser.y"
              { tipo_actual = T_INT; }
#line 1620 "y.tab.c"
    break;

  case 24: /* tipo: FLOAT  */
#line 123 "parser.y"
             { tipo_actual = T_FLOAT; }
#line 1626 "y.tab.c"
    break;

  case 25: /* tipo: CHAR  */
#line 124 "parser.y"
             { tipo_actual = T_CHAR; }
#line 1632 "y.tab.c"
    break;

  case 26: /* tipo: DOUBLE  */
#line 125 "parser.y"
             { tipo_actual = T_DOUBLE; }
#line 1638 "y.tab.c"
    break;

  case 27: /* declarar_lista_ids: ID  */
#line 128 "parser.y"
                        {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    imprimir_indentacion();
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1657 "y.tab.c"
    break;

  case 28: /* declarar_lista_ids: declarar_lista_ids ',' ID  */
#line 142 "parser.y"
                                     {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    imprimir_indentacion(); 
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1676 "y.tab.c"
    break;

  case 29: /* declarar_lista_ids: ID '=' expresion  */
#line 156 "parser.y"
                            {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno; 
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // Comprobación de tipos: verificar que la expresión sea compatible
                    verificar_compatibilidad_tipos(tipo_actual, (yyvsp[0].info_expr)->tipo_dato, (yyvsp[-2].nombre), yylineno);

                    imprimir_indentacion();
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].info_expr)->codigo);
                }
                free((yyvsp[-2].nombre));
         }
#line 1698 "y.tab.c"
    break;

  case 30: /* declarar_lista_ids: declarar_lista_ids ',' ID '=' expresion  */
#line 173 "parser.y"
                                                   {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // Comprobación de tipos: verificar que la expresión sea compatible
                    verificar_compatibilidad_tipos(tipo_actual, (yyvsp[0].info_expr)->tipo_dato, (yyvsp[-2].nombre), yylineno);
                    
                    imprimir_indentacion(); 
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].info_expr)->codigo);
                }
                free((yyvsp[-2].nombre));
         }
#line 1720 "y.tab.c"
    break;

  case 33: /* asignacion_unitaria: ID '=' expresion  */
#line 196 "parser.y"
                                       {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            // Comprobación de tipos en reasignación
                            if (!entrada->es_funcion) {
                                verificar_compatibilidad_tipos(entrada->tipo_base, (yyvsp[0].info_expr)->tipo_dato, entrada->nombre, yylineno);
                            }
                            // Verificar que no se asigne a una constante
                            if (entrada->es_constante) {
                                printf("[Error de Tipos] Línea %d: No se puede reasignar la constante '%s'.\n", yylineno, entrada->nombre);
                            }
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].info_expr)->codigo);
                        }
                        free((yyvsp[-2].nombre)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
                    }
#line 1743 "y.tab.c"
    break;

  case 34: /* asignacion_unitaria: ID accesos_array '=' expresion  */
#line 215 "parser.y"
                                                     {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-3].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable array '%s' no existe.\n", (yyvsp[-3].nombre));
                        } else {
                            imprimir_indentacion();
                            // El nombre de python + los corchetes
                            fprintf(yyout_py, "%s_%d%s = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[-2].nombre), (yyvsp[0].info_expr)->codigo);
                        }
                        free((yyvsp[-3].nombre)); free((yyvsp[-2].nombre)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
                    }
#line 1759 "y.tab.c"
    break;

  case 35: /* asignacion_unitaria: ID '+' '+'  */
#line 226 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[-2].nombre));
                    }
#line 1770 "y.tab.c"
    break;

  case 36: /* asignacion_unitaria: ID '-' '-'  */
#line 232 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[-2].nombre));
                    }
#line 1781 "y.tab.c"
    break;

  case 37: /* asignacion_unitaria: '+' '+' ID  */
#line 238 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1792 "y.tab.c"
    break;

  case 38: /* asignacion_unitaria: '-' '-' ID  */
#line 244 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1803 "y.tab.c"
    break;

  case 39: /* asignacion_unitaria: ID  */
#line 250 "parser.y"
                         {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1814 "y.tab.c"
    break;

  case 40: /* accesos_array: '[' expresion ']'  */
#line 259 "parser.y"
                                  {
                    char buf[256];
                    sprintf(buf, "[%s]", (yyvsp[-1].info_expr)->codigo);
                    (yyval.nombre) = strdup(buf);
                    free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
                }
#line 1825 "y.tab.c"
    break;

  case 41: /* accesos_array: accesos_array '[' expresion ']'  */
#line 265 "parser.y"
                                                {
                    char buf[512];
                    sprintf(buf, "%s[%s]", (yyvsp[-3].nombre), (yyvsp[-1].info_expr)->codigo);
                    (yyval.nombre) = strdup(buf);
                    free((yyvsp[-3].nombre)); free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
                }
#line 1836 "y.tab.c"
    break;

  case 42: /* $@1: %empty  */
#line 273 "parser.y"
           {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}
#line 1848 "y.tab.c"
    break;

  case 43: /* loop: FOR $@1 '(' for_init condicion_loop ';' loop_consecuencia ')' '{' instrucciones '}'  */
#line 279 "parser.y"
                                                                         {
            if ((yyvsp[-4].nombre) && strlen((yyvsp[-4].nombre)) > 0) {
                imprimir_indentacion();
                fprintf(yyout_py, "%s", (yyvsp[-4].nombre));
                free((yyvsp[-4].nombre));
            }
            nivel_indentacion--; 
            struct Entorno *viejo = entorno_actual;
            entorno_actual = entorno_actual->padre;
            free(viejo);
    }
#line 1864 "y.tab.c"
    break;

  case 44: /* loop: WHILE '(' condicion_loop ')' '{' instrucciones '}'  */
#line 290 "parser.y"
                                                        {    
        nivel_indentacion--;
    }
#line 1872 "y.tab.c"
    break;

  case 45: /* condicion_loop: expresion '=' expresion  */
#line 295 "parser.y"
                                         {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                    nivel_indentacion++;
                    free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 1884 "y.tab.c"
    break;

  case 46: /* condicion_loop: expresion  */
#line 302 "parser.y"
                           {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", (yyvsp[0].info_expr)->codigo);
                    nivel_indentacion++;
                    free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 1895 "y.tab.c"
    break;

  case 47: /* loop_consecuencia: ID  */
#line 310 "parser.y"
                      { (yyval.nombre) = strdup(""); }
#line 1901 "y.tab.c"
    break;

  case 48: /* loop_consecuencia: ID '+' '+'  */
#line 311 "parser.y"
                           {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                }
#line 1914 "y.tab.c"
    break;

  case 49: /* loop_consecuencia: '-' '-' ID  */
#line 319 "parser.y"
                            {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                }
#line 1927 "y.tab.c"
    break;

  case 50: /* loop_consecuencia: ID '=' expresion  */
#line 327 "parser.y"
                                   {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada != NULL){
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].info_expr)->codigo);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                    free((yyvsp[-2].nombre)); free((yyvsp[0].info_expr));
                }
#line 1941 "y.tab.c"
    break;

  case 51: /* expresion: ID  */
#line 338 "parser.y"
               {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", (yyvsp[0].nombre));
                    (yyval.info_expr)->codigo = strdup((yyvsp[0].nombre)); 
                    (yyval.info_expr)->tipo_dato = T_INT; 
                } else {
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.info_expr)->codigo = strdup(buf);
                    (yyval.info_expr)->tipo_dato = entrada->tipo_base;
                }
                free((yyvsp[0].nombre));
          }
#line 1961 "y.tab.c"
    break;

  case 52: /* expresion: ID accesos_array  */
#line 354 "parser.y"
                             {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-1].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: '%s' (array) no declarada.\n", (yyvsp[-1].nombre));
                    (yyval.info_expr)->codigo = strdup((yyvsp[-1].nombre)); 
                    (yyval.info_expr)->tipo_dato = T_INT;
                } else {
                    char buf[512];
                    sprintf(buf, "%s_%d%s", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].nombre));
                    (yyval.info_expr)->codigo = strdup(buf);
                    (yyval.info_expr)->tipo_dato = entrada->tipo_base;
                }
                free((yyvsp[-1].nombre)); free((yyvsp[0].nombre));
          }
#line 1981 "y.tab.c"
    break;

  case 53: /* expresion: llamada_funcion_expr  */
#line 370 "parser.y"
                                 {
                (yyval.info_expr) = (yyvsp[0].info_expr);
          }
#line 1989 "y.tab.c"
    break;

  case 54: /* expresion: NUMERO  */
#line 373 "parser.y"
                   {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[50];
                sprintf(buf, "%g", (yyvsp[0].val_num));
                (yyval.info_expr)->codigo = strdup(buf);
                /* --- NUEVO PUNTO 5: Si el string tiene un punto, es float --- */
                if (strchr(buf, '.') != NULL) {
                    (yyval.info_expr)->tipo_dato = T_FLOAT;
                } else {
                    (yyval.info_expr)->tipo_dato = T_INT;
                }
          }
#line 2006 "y.tab.c"
    break;

  case 55: /* expresion: expresion '+' expresion  */
#line 385 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s + %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                /* --- NUEVO PUNTO 2: Promoción de tipos automática --- */
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato); 
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2020 "y.tab.c"
    break;

  case 56: /* expresion: expresion '-' expresion  */
#line 394 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s - %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2033 "y.tab.c"
    break;

  case 57: /* expresion: expresion '*' expresion  */
#line 402 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s * %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2046 "y.tab.c"
    break;

  case 58: /* expresion: expresion '/' expresion  */
#line 411 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s / %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2059 "y.tab.c"
    break;

  case 59: /* expresion: expresion '%' expresion  */
#line 419 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s %% %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2072 "y.tab.c"
    break;

  case 60: /* expresion: expresion AND expresion  */
#line 427 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s and %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); // Traduccion a python "and"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2085 "y.tab.c"
    break;

  case 61: /* expresion: expresion OR expresion  */
#line 435 "parser.y"
                                   {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s or %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); // Traduccion a python "or"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2098 "y.tab.c"
    break;

  case 62: /* expresion: '!' expresion  */
#line 443 "parser.y"
                          {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "not %s", (yyvsp[0].info_expr)->codigo); // Traduccion a python "not"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2111 "y.tab.c"
    break;

  case 63: /* expresion: expresion '>' expresion  */
#line 451 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s > %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2121 "y.tab.c"
    break;

  case 64: /* expresion: expresion '<' expresion  */
#line 456 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s < %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2131 "y.tab.c"
    break;

  case 65: /* expresion: expresion IGUAL_IGUAL expresion  */
#line 461 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s == %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2141 "y.tab.c"
    break;

  case 66: /* expresion: expresion NO_IGUAL expresion  */
#line 466 "parser.y"
                                         {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s != %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2151 "y.tab.c"
    break;

  case 67: /* expresion: expresion MAYOR_IGUAL expresion  */
#line 471 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s >= %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2161 "y.tab.c"
    break;

  case 68: /* expresion: expresion MENOR_IGUAL expresion  */
#line 476 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s <= %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2171 "y.tab.c"
    break;

  case 69: /* expresion: '(' expresion ')'  */
#line 481 "parser.y"
                              {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "(%s)", (yyvsp[-1].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = (yyvsp[-1].info_expr)->tipo_dato; 
                free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
          }
#line 2184 "y.tab.c"
    break;

  case 70: /* $@2: %empty  */
#line 491 "parser.y"
                          {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        }
#line 2193 "y.tab.c"
    break;

  case 71: /* $@3: %empty  */
#line 494 "parser.y"
                           {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        }
#line 2202 "y.tab.c"
    break;

  case 72: /* $@4: %empty  */
#line 497 "parser.y"
                                { 
            nivel_indentacion--;
        }
#line 2210 "y.tab.c"
    break;

  case 74: /* $@5: %empty  */
#line 500 "parser.y"
                                   {
            
        }
#line 2218 "y.tab.c"
    break;

  case 75: /* $@6: %empty  */
#line 502 "parser.y"
             {
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", (yyvsp[-3].info_expr)->codigo);
            nivel_indentacion++;
            free((yyvsp[-3].info_expr));
        }
#line 2229 "y.tab.c"
    break;

  case 76: /* condicionales: SWITCH '(' expresion ')' $@5 '{' $@6 switch_cases '}'  */
#line 507 "parser.y"
                           {
            nivel_indentacion--;
        }
#line 2237 "y.tab.c"
    break;

  case 77: /* $@7: %empty  */
#line 512 "parser.y"
                             { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           }
#line 2246 "y.tab.c"
    break;

  case 78: /* $@8: %empty  */
#line 516 "parser.y"
                            { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           }
#line 2255 "y.tab.c"
    break;

  case 79: /* $@9: %empty  */
#line 520 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2263 "y.tab.c"
    break;

  case 81: /* $@10: %empty  */
#line 524 "parser.y"
                { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           }
#line 2273 "y.tab.c"
    break;

  case 82: /* bloque_else: ELSE $@10 '{' instrucciones '}'  */
#line 529 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2281 "y.tab.c"
    break;

  case 84: /* $@11: %empty  */
#line 536 "parser.y"
                                    {
                    if (strchr((yyvsp[-1].info_expr)->codigo, '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, (yyvsp[-1].info_expr)->codigo);
                    }
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", (yyvsp[-1].info_expr)->codigo);
                    nivel_indentacion++; 
                    free((yyvsp[-1].info_expr));
    }
#line 2295 "y.tab.c"
    break;

  case 85: /* $@12: %empty  */
#line 544 "parser.y"
                              {
        nivel_indentacion--;
    }
#line 2303 "y.tab.c"
    break;

  case 87: /* $@13: %empty  */
#line 547 "parser.y"
                              {
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
#line 2313 "y.tab.c"
    break;

  case 88: /* switch_cases: DEFAULT ':' $@13 instrucciones  */
#line 552 "parser.y"
                            {
                    nivel_indentacion--;
              }
#line 2321 "y.tab.c"
    break;

  case 89: /* switch_cases: error switch_cases  */
#line 555 "parser.y"
                                     { 
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; 
              }
#line 2330 "y.tab.c"
    break;

  case 91: /* condicion_IF: expresion '=' expresion  */
#line 562 "parser.y"
                                          {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace.\n");
                    fprintf(yyout_py, "%s = %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                    free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 2340 "y.tab.c"
    break;

  case 92: /* condicion_IF: expresion  */
#line 567 "parser.y"
                           {
                    fprintf(yyout_py, "%s", (yyvsp[0].info_expr)->codigo);
                    free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 2349 "y.tab.c"
    break;

  case 96: /* $@14: %empty  */
#line 578 "parser.y"
                                        { fprintf(yyout_py, ", "); }
#line 2355 "y.tab.c"
    break;

  case 98: /* parametro_void: tipo ID  */
#line 581 "parser.y"
                         { 
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    // Guardamos el tipo de este parámetro en el buffer de declaración
                    if (contador_parametros < MAX_PARAMS)
                        tipos_params_actuales[contador_parametros] = tipo_actual;
                    contador_parametros++;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    fprintf(yyout_py, "%s_%d", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
          }
#line 2376 "y.tab.c"
    break;

  case 99: /* $@15: %empty  */
#line 599 "parser.y"
                                      {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-1].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' ya fue declarada.\n", (yyvsp[-1].nombre));
                } else {
                    entrada->tipo_base = T_VOID;
                    entrada->es_funcion = 1;
                    struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                    nuevo->tabla_simbolos = NULL;
                    nuevo->cantidad_simbolos = 0;
                    nuevo->capacidad_tabla = 0;
                    nuevo->padre = entorno_actual;
                    nuevo->id_entorno = contador_entornos++; 
                    entorno_actual = nuevo; 
                    imprimir_indentacion();
                    fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
                }
            }
#line 2399 "y.tab.c"
    break;

  case 100: /* $@16: %empty  */
#line 616 "parser.y"
                                                {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-4].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' no existe. Línea %d\n", (yyvsp[-4].nombre), yylineno);
                } else {
                    entrada->cantidad_parametros_funcion = contador_parametros;
                    // Copiar el buffer de tipos al arreglo dinámico de la entrada
                    if (contador_parametros > 0) {
                        entrada->tipos_parametros = (int *) malloc(contador_parametros * sizeof(int));
                        for (int i = 0; i < contador_parametros; i++)
                            entrada->tipos_parametros[i] = tipos_params_actuales[i];
                    }
                    contador_parametros = 0;
                    free((yyvsp[-4].nombre));
                }
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2422 "y.tab.c"
    break;

  case 101: /* funcion_void: VOID ID '(' $@15 declaracion_variables_funcion ')' $@16 '{' instrucciones '}'  */
#line 633 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2433 "y.tab.c"
    break;

  case 102: /* $@17: %empty  */
#line 641 "parser.y"
                                                        {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-1].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la función '%s' ya fue declarada.\n", (yyvsp[-1].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->es_funcion = 1;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                }
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++;
                entorno_actual = nuevo;
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
            }
#line 2456 "y.tab.c"
    break;

  case 103: /* $@18: %empty  */
#line 658 "parser.y"
                                                {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-4].nombre));
                if (entrada != NULL) {
                    entrada->cantidad_parametros_funcion = contador_parametros;
                    // Copiar el buffer de tipos al arreglo dinámico de la entrada
                    if (contador_parametros > 0) {
                        entrada->tipos_parametros = (int *) malloc(contador_parametros * sizeof(int));
                        for (int i = 0; i < contador_parametros; i++)
                            entrada->tipos_parametros[i] = tipos_params_actuales[i];
                    }
                }
                contador_parametros = 0;
                free((yyvsp[-4].nombre));
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2477 "y.tab.c"
    break;

  case 104: /* funcion_NO_void: prefijo_declaracion ID '(' $@17 declaracion_variables_funcion ')' $@18 '{' instrucciones '}'  */
#line 673 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2488 "y.tab.c"
    break;

  case 105: /* $@19: %empty  */
#line 680 "parser.y"
                                   {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-1].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: la función '%s' no existe.\n", (yyvsp[-1].nombre));
                }
                imprimir_indentacion();
                fprintf(yyout_py, "%s(", (yyvsp[-1].nombre));
            }
#line 2501 "y.tab.c"
    break;

  case 106: /* $@20: %empty  */
#line 687 "parser.y"
                                         {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-4].nombre));
                if (entrada != NULL && entrada->es_funcion) {
                    if (contador_parametros != entrada->cantidad_parametros_funcion) {
                        printf("[Error de Tipos] Línea %d: La función '%s' espera %d parámetro(s) pero se le pasaron %d.\n",
                               yylineno, (yyvsp[-4].nombre),
                               entrada->cantidad_parametros_funcion,
                               contador_parametros);
                    } else if (entrada->tipos_parametros != NULL) {
                        // Verificar el tipo de cada argumento posición a posición
                        for (int i = 0; i < contador_parametros; i++) {
                            if (!verificar_compatibilidad_tipos(
                                    entrada->tipos_parametros[i],
                                    tipos_args_actuales[i],
                                    entrada->nombre,
                                    yylineno)) {
                                printf("  (parámetro %d: se esperaba '%s', se recibió '%s')\n",
                                       i + 1,
                                       nombre_tipo(entrada->tipos_parametros[i]),
                                       nombre_tipo(tipos_args_actuales[i]));
                            }
                        }
                    }
                }
                contador_parametros = 0;
                free((yyvsp[-4].nombre));
                fprintf(yyout_py, ")\n");
            }
#line 2534 "y.tab.c"
    break;

  case 111: /* $@21: %empty  */
#line 722 "parser.y"
                                                       { fprintf(yyout_py, ", "); }
#line 2540 "y.tab.c"
    break;

  case 113: /* parametro_llamar_funcion: expresion  */
#line 725 "parser.y"
                                         { 
        fprintf(yyout_py, "%s", (yyvsp[0].info_expr)->codigo);
        // Guardar el tipo del argumento en el buffer de llamadas
        if (contador_parametros < MAX_PARAMS)
            tipos_args_actuales[contador_parametros] = (yyvsp[0].info_expr)->tipo_dato;
        contador_parametros++;
        free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
    }
#line 2553 "y.tab.c"
    break;

  case 114: /* llamada_funcion_expr: ID '(' usar_variables_funcion_expr ')'  */
#line 736 "parser.y"
                                                                  {
            (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
            struct entrada_tabla *entrada = buscar_variable((yyvsp[-3].nombre));
            // Verificar cantidad y tipos de parámetros
            if (entrada != NULL && entrada->es_funcion) {
                if (contador_parametros != entrada->cantidad_parametros_funcion) {
                    printf("[Error de Tipos] Línea %d: La función '%s' espera %d parámetro(s) pero se le pasaron %d.\n",
                           yylineno, (yyvsp[-3].nombre),
                           entrada->cantidad_parametros_funcion,
                           contador_parametros);
                } else if (entrada->tipos_parametros != NULL) {
                    // Verificar el tipo de cada argumento posición a posición
                    for (int i = 0; i < contador_parametros; i++) {
                        if (!verificar_compatibilidad_tipos(
                                entrada->tipos_parametros[i],
                                tipos_args_actuales[i],
                                entrada->nombre,
                                yylineno)) {
                            printf("  (parámetro %d: se esperaba '%s', se recibió '%s')\n",
                                   i + 1,
                                   nombre_tipo(entrada->tipos_parametros[i]),
                                   nombre_tipo(tipos_args_actuales[i]));
                        }
                    }
                }
            }
            contador_parametros = 0;
            char buf[1024];
            sprintf(buf, "%s(%s)", (yyvsp[-3].nombre), (yyvsp[-1].nombre));
            (yyval.info_expr)->codigo = strdup(buf);
            (yyval.info_expr)->tipo_dato = entrada ? entrada->tipo_base : T_INT;
            free((yyvsp[-3].nombre)); free((yyvsp[-1].nombre));
    }
#line 2591 "y.tab.c"
    break;

  case 115: /* usar_variables_funcion_expr: lista_parametros_llamar_funcion_expr  */
#line 771 "parser.y"
                                                                       { (yyval.nombre) = (yyvsp[0].nombre); }
#line 2597 "y.tab.c"
    break;

  case 116: /* usar_variables_funcion_expr: %empty  */
#line 772 "parser.y"
                                               { (yyval.nombre) = strdup(""); }
#line 2603 "y.tab.c"
    break;

  case 117: /* lista_parametros_llamar_funcion_expr: expresion  */
#line 775 "parser.y"
                                                     { 
            (yyval.nombre) = strdup((yyvsp[0].info_expr)->codigo);
            // Guardar el tipo del argumento en el buffer de llamadas
            if (contador_parametros < MAX_PARAMS)
                tipos_args_actuales[contador_parametros] = (yyvsp[0].info_expr)->tipo_dato;
            contador_parametros++;
            free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr)); 
        }
#line 2616 "y.tab.c"
    break;

  case 118: /* lista_parametros_llamar_funcion_expr: lista_parametros_llamar_funcion_expr ',' expresion  */
#line 783 "parser.y"
                                                             { 
            char buf[1024];
            sprintf(buf, "%s, %s", (yyvsp[-2].nombre), (yyvsp[0].info_expr)->codigo);
            (yyval.nombre) = strdup(buf);
            // Guardar el tipo del argumento en el buffer de llamadas
            if (contador_parametros < MAX_PARAMS)
                tipos_args_actuales[contador_parametros] = (yyvsp[0].info_expr)->tipo_dato;
            contador_parametros++;
            free((yyvsp[-2].nombre)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
        }
#line 2631 "y.tab.c"
    break;

  case 123: /* arrays: prefijo_declaracion ID '[' volumen_array ']' dimension_array asignacion_array ';'  */
#line 799 "parser.y"
                                                                                              {
        struct entrada_tabla *entrada = declarar_variable((yyvsp[-6].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-6].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;
                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    imprimir_indentacion();
                    if ((yyvsp[-1].nombre) != NULL) {
                        fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-6].nombre), entorno_actual->id_entorno, (yyvsp[-1].nombre));
                        free((yyvsp[-1].nombre));
                    } else {
                        fprintf(yyout_py, "%s_%d = []\n", (yyvsp[-6].nombre), entorno_actual->id_entorno);
                    }
                }
                free((yyvsp[-6].nombre));
    }
#line 2655 "y.tab.c"
    break;

  case 124: /* asignacion_array: '=' inicializador_array  */
#line 820 "parser.y"
                                              { (yyval.nombre) = strdup((yyvsp[0].nombre)); free((yyvsp[0].nombre)); }
#line 2661 "y.tab.c"
    break;

  case 125: /* asignacion_array: %empty  */
#line 821 "parser.y"
                                   { (yyval.nombre) = NULL; }
#line 2667 "y.tab.c"
    break;

  case 126: /* inicializador_array: '{' lista_inicializadores '}'  */
#line 826 "parser.y"
    {
        (yyval.nombre) = malloc(strlen((yyvsp[-1].nombre)) + 3);
        sprintf((yyval.nombre), "[%s]", (yyvsp[-1].nombre));
        free((yyvsp[-1].nombre));
    }
#line 2677 "y.tab.c"
    break;

  case 127: /* lista_inicializadores: valor_o_anidado  */
#line 835 "parser.y"
    {
        (yyval.nombre) = strdup((yyvsp[0].nombre));
        free((yyvsp[0].nombre));
    }
#line 2686 "y.tab.c"
    break;

  case 128: /* lista_inicializadores: lista_inicializadores ',' valor_o_anidado  */
#line 840 "parser.y"
    {
        (yyval.nombre) = malloc(strlen((yyvsp[-2].nombre)) + strlen((yyvsp[0].nombre)) + 3);
        sprintf((yyval.nombre), "%s, %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
        free((yyvsp[-2].nombre));
        free((yyvsp[0].nombre));
    }
#line 2697 "y.tab.c"
    break;

  case 129: /* valor_o_anidado: expresion  */
#line 849 "parser.y"
              {
        (yyval.nombre) = strdup((yyvsp[0].info_expr)->codigo);
        free((yyvsp[0].info_expr));
    }
#line 2706 "y.tab.c"
    break;

  case 130: /* valor_o_anidado: inicializador_array  */
#line 853 "parser.y"
                          {
        (yyval.nombre) = strdup((yyvsp[0].nombre)); 
        free((yyvsp[0].nombre));
    }
#line 2715 "y.tab.c"
    break;


#line 2719 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 859 "parser.y"


/* Inclusión rústica del analizador léxico al final del archivo */
#include "lex.yy.c"

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en la línea %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {                                       
        if (argc != 3) {                                                    
            printf("Uso: %s <archivo_entrada.c> <archivo_salida.py>\n", argv[0]);                                                                 
            return 1;                                                       
        }                                                                   
                                                                            
        yyin = fopen(argv[1], "r");                                         
        if (!yyin) {                                                        
            printf("No se pudo abrir el archivo %s\n", argv[1]);            
            return 1;                                                       
        }                                                                   
                                                                            
        yyout_py = fopen(argv[2], "w");                                     
        if (!yyout_py) {                                                    
            printf("No se pudo crear el archivo %s\n", argv[2]);            
            fclose(yyin);                                                   
            return 1;                                                       
        }                                                                   
                                                                            
        entorno_actual = (struct Entorno *) malloc(sizeof(struct Entorno));
        entorno_actual->tabla_simbolos = NULL;
        entorno_actual->cantidad_simbolos = 0;
        entorno_actual->capacidad_tabla = 0;
        entorno_actual->padre = NULL;

        printf("Iniciando compilacion de %s a %s...\n", argv[1], argv[2]);  
        yyparse();                                                          
        printf("Compilacion finalizada.\n");                                
                                                                            
        fclose(yyin);                                                       
        fclose(yyout_py);                                                   
        return 0;                                                           
}
