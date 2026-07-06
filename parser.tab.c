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


#line 119 "parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_bloque = 46,                    /* bloque  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_instrucciones = 48,             /* instrucciones  */
  YYSYMBOL_instruccion = 49,               /* instruccion  */
  YYSYMBOL_declaracion = 50,               /* declaracion  */
  YYSYMBOL_for_init = 51,                  /* for_init  */
  YYSYMBOL_asignacion = 52,                /* asignacion  */
  YYSYMBOL_prefijo_declaracion = 53,       /* prefijo_declaracion  */
  YYSYMBOL_tipo = 54,                      /* tipo  */
  YYSYMBOL_declarar_lista_ids = 55,        /* declarar_lista_ids  */
  YYSYMBOL_lista_asignaciones = 56,        /* lista_asignaciones  */
  YYSYMBOL_asignacion_unitaria = 57,       /* asignacion_unitaria  */
  YYSYMBOL_accesos_array = 58,             /* accesos_array  */
  YYSYMBOL_loop = 59,                      /* loop  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_condicion_loop = 61,            /* condicion_loop  */
  YYSYMBOL_loop_consecuencia = 62,         /* loop_consecuencia  */
  YYSYMBOL_expresion = 63,                 /* expresion  */
  YYSYMBOL_condicionales = 64,             /* condicionales  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_69_7 = 69,                      /* $@7  */
  YYSYMBOL_bloque_else = 70,               /* bloque_else  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_73_10 = 73,                     /* $@10  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_switch_cases = 75,              /* switch_cases  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_condicion_IF = 79,              /* condicion_IF  */
  YYSYMBOL_declaracion_variables_funcion = 80, /* declaracion_variables_funcion  */
  YYSYMBOL_lista_parametros = 81,          /* lista_parametros  */
  YYSYMBOL_82_15 = 82,                     /* $@15  */
  YYSYMBOL_parametro_void = 83,            /* parametro_void  */
  YYSYMBOL_funcion_void = 84,              /* funcion_void  */
  YYSYMBOL_85_16 = 85,                     /* $@16  */
  YYSYMBOL_86_17 = 86,                     /* $@17  */
  YYSYMBOL_funcion_NO_void = 87,           /* funcion_NO_void  */
  YYSYMBOL_88_18 = 88,                     /* $@18  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_llamar_funcion = 90,            /* llamar_funcion  */
  YYSYMBOL_91_20 = 91,                     /* $@20  */
  YYSYMBOL_92_21 = 92,                     /* $@21  */
  YYSYMBOL_usar_variables_funcion = 93,    /* usar_variables_funcion  */
  YYSYMBOL_lista_parametros_llamar_funcion = 94, /* lista_parametros_llamar_funcion  */
  YYSYMBOL_95_22 = 95,                     /* $@22  */
  YYSYMBOL_parametro_llamar_funcion = 96,  /* parametro_llamar_funcion  */
  YYSYMBOL_llamada_funcion_expr = 97,      /* llamada_funcion_expr  */
  YYSYMBOL_usar_variables_funcion_expr = 98, /* usar_variables_funcion_expr  */
  YYSYMBOL_lista_parametros_llamar_funcion_expr = 99, /* lista_parametros_llamar_funcion_expr  */
  YYSYMBOL_volumen_array = 100,            /* volumen_array  */
  YYSYMBOL_dimension_array = 101,          /* dimension_array  */
  YYSYMBOL_arrays = 102,                   /* arrays  */
  YYSYMBOL_asignacion_array = 103,         /* asignacion_array  */
  YYSYMBOL_inicializador_array = 104,      /* inicializador_array  */
  YYSYMBOL_lista_inicializadores = 105,    /* lista_inicializadores  */
  YYSYMBOL_valor_o_anidado = 106           /* valor_o_anidado  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   690

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

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
      41,    42,    30,    28,    37,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    36,
      26,    38,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
       0,    78,    78,    81,    81,    96,    97,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   114,   120,   121,
     124,   127,   128,   131,   133,   134,   137,   138,   139,   140,
     143,   157,   171,   188,   207,   208,   211,   230,   241,   247,
     253,   259,   265,   274,   280,   288,   288,   305,   310,   317,
     325,   326,   334,   342,   353,   369,   385,   388,   400,   409,
     417,   426,   434,   442,   450,   458,   466,   471,   476,   481,
     486,   491,   496,   506,   509,   512,   506,   515,   517,   515,
     527,   531,   535,   527,   539,   539,   548,   551,   559,   551,
     562,   562,   570,   574,   577,   582,   588,   589,   592,   593,
     593,   596,   614,   631,   614,   657,   674,   657,   698,   705,
     698,   735,   736,   739,   740,   740,   743,   754,   789,   790,
     793,   801,   813,   813,   815,   815,   817,   838,   839,   843,
     852,   857,   867,   871
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
  "'-'", "'*'", "'/'", "'%'", "'!'", "'{'", "'}'", "';'", "','", "'='",
  "'['", "']'", "'('", "')'", "':'", "$accept", "programa", "bloque",
  "$@1", "instrucciones", "instruccion", "declaracion", "for_init",
  "asignacion", "prefijo_declaracion", "tipo", "declarar_lista_ids",
  "lista_asignaciones", "asignacion_unitaria", "accesos_array", "loop",
  "$@2", "condicion_loop", "loop_consecuencia", "expresion",
  "condicionales", "$@3", "$@4", "$@5", "$@6", "$@7", "bloque_else", "$@8",
  "$@9", "$@10", "$@11", "switch_cases", "$@12", "$@13", "$@14",
  "condicion_IF", "declaracion_variables_funcion", "lista_parametros",
  "$@15", "parametro_void", "funcion_void", "$@16", "$@17",
  "funcion_NO_void", "$@18", "$@19", "llamar_funcion", "$@20", "$@21",
  "usar_variables_funcion", "lista_parametros_llamar_funcion", "$@22",
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

#define YYPACT_NINF (-195)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -195,    12,   469,  -195,   -22,     9,   -19,  -195,  -195,  -195,
      31,  -195,  -195,    17,    11,    -8,    83,    47,  -195,  -195,
    -195,  -195,  -195,  -195,    59,  -195,   -10,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,    57,    79,  -195,    57,  -195,
      57,   596,  -195,    81,  -195,    55,    45,    57,    87,    94,
     101,    57,    57,  -195,    98,   111,   117,  -195,    58,   103,
    -195,    33,    57,   100,   562,    57,   106,  -195,   490,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,  -195,    57,  -195,   122,     0,   507,  -195,  -195,
    -195,   617,   524,    57,    57,    57,  -195,  -195,    97,   123,
    -195,  -195,    56,  -195,   579,   112,   132,    57,   617,   115,
     131,  -195,    85,   658,    85,   658,   651,   634,    85,    85,
      48,    48,  -195,  -195,  -195,   617,   134,  -195,    57,  -195,
     145,  -195,    40,  -195,   617,   128,   137,  -195,   617,   543,
    -195,  -195,   138,    40,    57,  -195,  -195,   617,  -195,    57,
      57,   135,   143,   155,   140,   146,  -195,  -195,  -195,  -195,
     141,   142,   617,   151,   197,   617,   617,   -11,  -195,  -195,
    -195,  -195,   150,    57,   123,   152,  -195,  -195,  -195,   -13,
     160,   153,     2,   158,    40,  -195,  -195,   154,   159,   162,
     167,   233,   168,    57,   187,   179,     2,    57,   171,   180,
    -195,  -195,   141,    19,  -195,  -195,  -195,  -195,  -195,   617,
    -195,  -195,  -195,   133,  -195,  -195,   267,  -195,   617,  -195,
      92,  -195,   301,   212,   335,  -195,  -195,  -195,  -195,    19,
    -195,   214,  -195,  -195,  -195,   469,  -195,   177,   185,   369,
    -195,  -195,   184,    57,   401,  -195,   182,  -195,     2,  -195,
    -195,   188,  -195,   435,  -195,   212,  -195
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,     0,    26,    27,    28,
       0,    29,    45,     0,     0,    42,     0,     0,     3,    20,
       9,     5,     7,     8,     0,    24,     0,    34,    10,    11,
      12,    13,    14,    15,    73,     0,    54,    57,     0,    17,
       0,     0,    56,    30,    25,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     6,    30,     0,
      23,     0,     0,     0,    49,   119,    55,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    19,     0,     0,     0,   102,    38,
      39,    36,     0,   112,     0,     0,    40,    41,     0,   123,
     105,    18,    42,    35,    95,     0,     0,     0,   120,     0,
     118,    72,    70,    68,    71,    69,    63,    64,    67,    66,
      58,    59,    60,    61,    62,    32,    31,    21,     0,    22,
       0,    77,    97,    43,   116,     0,   111,   113,    37,     0,
       4,   122,     0,    97,     0,    74,     6,    48,   117,     0,
       0,     0,     0,     0,     0,    96,    98,   109,   114,    44,
     125,     0,    94,     0,     0,   121,    33,     0,    78,   101,
     103,    99,     0,     0,   123,   128,   106,     6,    47,    50,
       0,     0,     0,     0,     0,   110,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,   100,   125,     0,   127,   126,     6,    75,    51,    53,
      52,     6,    92,     0,    90,    79,     0,   124,   132,   133,
       0,   130,     0,    86,     0,    87,     6,   104,   129,     0,
     107,    84,    76,    46,     6,    91,   131,     0,     0,     0,
      80,     6,     0,     0,     0,    88,     0,    85,     0,    81,
      89,     0,     6,     0,    82,    86,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,  -195,   -53,  -195,   144,  -195,   148,   149,
      -9,   217,  -195,   186,   192,  -195,  -195,   121,  -195,    -6,
    -195,  -195,  -195,  -195,  -195,  -195,   -26,  -195,  -195,  -195,
    -195,  -194,  -195,  -195,  -195,     7,   108,  -195,  -195,    68,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,    80,  -195,  -195,  -195,    82,    52,  -195,  -195,
      67,  -195,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,    57,     2,    21,    22,   128,    23,    24,
      25,    59,    26,    27,    54,    28,    46,    63,   181,    64,
      29,    62,   163,   223,   152,   182,   232,   243,   251,   255,
     238,   199,   234,   248,   226,   105,   154,   155,   184,   156,
      30,   132,   183,    31,   143,   190,    32,    93,   172,   135,
     136,   173,   137,    42,   109,   110,   142,   175,    33,   189,
     219,   220,   221
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    44,   212,   196,    98,    36,    37,     7,     8,     9,
      10,    11,     3,   179,    38,   192,   197,    39,   180,    34,
      49,    50,    40,   198,   102,   193,    60,    61,    16,    17,
      51,    52,    67,    53,    68,    48,    19,   -93,     7,     8,
       9,    87,    11,    36,    37,    91,    92,     7,     8,     9,
      35,    11,    38,   203,   250,    43,   104,   102,    47,   108,
      40,    16,    17,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    56,   125,    79,    80,
      81,    36,    37,    58,    49,    50,    86,   134,   138,   139,
      38,    84,    85,   164,    51,    52,    83,    99,    40,   100,
       4,   147,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    55,    14,    77,    78,    79,    80,    81,    52,    83,
      65,    15,    89,   153,   191,    16,    17,   228,    88,   229,
      90,    18,   140,    19,   153,    96,    94,    95,   162,   101,
      85,    97,   106,   165,   166,    95,   126,   216,   141,    69,
      70,    71,    72,   222,   145,    73,    74,   148,   224,    75,
      76,    77,    78,    79,    80,    81,   146,   134,   149,    43,
     157,   167,   150,   235,   158,   153,   225,   168,   160,   169,
     174,   239,   170,   171,   176,   177,   185,   209,   244,   194,
     188,   213,   200,   203,   202,   195,   208,   218,   205,   253,
       4,   206,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   210,    14,   211,   214,   215,   231,   237,   240,   241,
     245,    15,   252,   218,   249,    16,    17,    45,    66,   256,
     127,    18,   178,    19,   129,   130,     4,   104,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   103,    14,   151,
     246,   161,   201,   186,   217,   204,   187,    15,   236,     0,
       0,    16,    17,     0,     0,     0,     0,    18,   207,    19,
       4,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,    16,    17,     0,     0,     0,
       0,    18,   227,    19,     4,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     0,    18,   230,    19,     4,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    16,    17,     0,     0,     0,     0,    18,
     233,    19,     4,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,     0,     0,   242,
       0,     0,     0,    15,     0,     0,     0,    16,    17,     0,
       0,     0,     0,    18,     4,    19,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    16,
      17,     0,     0,     0,     0,    18,   247,    19,     4,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    16,    17,     0,     0,     0,     0,    18,
     254,    19,     4,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,    16,    17,     0,
       0,     0,     0,    18,     0,    19,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    69,    70,    71,    72,     0,     0,    73,
      74,     0,   111,    75,    76,    77,    78,    79,    80,    81,
      69,    70,    71,    72,     0,     0,    73,    74,     0,   131,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    69,
      70,    71,    72,     0,   133,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    69,    70,
      71,    72,     0,   159,    73,    74,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    69,    70,    71,    72,     0,
     107,    73,    74,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    69,    70,    71,    72,     0,   144,    73,    74,
       0,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    82,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      69,    70,    71,    72,     0,     0,    73,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    69,    70,    71,
      72,     0,     0,     0,    69,     0,    71,    75,    76,    77,
      78,    79,    80,    81,    75,    76,    77,    78,    79,    80,
      81
};

static const yytype_int16 yycheck[] =
{
       6,    10,   196,     1,    57,    24,    25,     7,     8,     9,
      10,    11,     0,    24,    33,    28,    14,    36,    29,    41,
      28,    29,    41,    21,    24,    38,    36,    37,    28,    29,
      38,    39,    38,    41,    40,    24,    36,    35,     7,     8,
       9,    47,    11,    24,    25,    51,    52,     7,     8,     9,
      41,    11,    33,    34,   248,    24,    62,    24,    41,    65,
      41,    28,    29,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    29,    83,    30,    31,
      32,    24,    25,    24,    28,    29,    41,    93,    94,    95,
      33,    36,    37,   146,    38,    39,    38,    39,    41,    41,
       3,   107,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    28,    15,    28,    29,    30,    31,    32,    39,    38,
      41,    24,    28,   132,   177,    28,    29,    35,    41,    37,
      29,    34,    35,    36,   143,    24,    38,    39,   144,    36,
      37,    24,    42,   149,   150,    39,    24,   200,    25,    16,
      17,    18,    19,   206,    42,    22,    23,    42,   211,    26,
      27,    28,    29,    30,    31,    32,    34,   173,    37,    24,
      42,    36,    38,   226,    37,   184,    43,    34,    40,    24,
      39,   234,    42,    37,    42,    34,    36,   193,   241,    29,
      38,   197,    34,    34,    40,    42,    28,   203,    36,   252,
       3,    34,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    24,    15,    34,    43,    35,     4,     3,    41,    34,
      36,    24,    34,   229,    42,    28,    29,    10,    36,   255,
      86,    34,    35,    36,    86,    86,     3,   243,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    61,    15,   128,
     243,   143,   184,   173,   202,   188,   174,    24,   229,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,     3,    36,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    36,    16,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    16,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    42,    26,    27,    28,    29,    30,    31,    32,
      16,    17,    18,    19,    -1,    -1,    22,    23,    -1,    42,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    16,
      17,    18,    19,    -1,    40,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    16,    17,
      18,    19,    -1,    40,    22,    23,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    16,    17,    18,    19,    -1,
      38,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    16,    17,    18,    19,    -1,    38,    22,    23,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    16,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    16,    17,    18,
      19,    -1,    -1,    -1,    16,    -1,    18,    26,    27,    28,
      29,    30,    31,    32,    26,    27,    28,    29,    30,    31,
      32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    48,     0,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    15,    24,    28,    29,    34,    36,
      46,    49,    50,    52,    53,    54,    56,    57,    59,    64,
      84,    87,    90,   102,    41,    41,    24,    25,    33,    36,
      41,    63,    97,    24,    54,    55,    60,    41,    24,    28,
      29,    38,    39,    41,    58,    28,    29,    47,    24,    55,
      36,    37,    65,    61,    63,    41,    58,    63,    63,    16,
      17,    18,    19,    22,    23,    26,    27,    28,    29,    30,
      31,    32,    36,    38,    36,    37,    41,    63,    41,    28,
      29,    63,    63,    91,    38,    39,    24,    24,    48,    39,
      41,    36,    24,    57,    63,    79,    42,    38,    63,    98,
      99,    42,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    24,    50,    51,    52,
      53,    42,    85,    40,    63,    93,    94,    96,    63,    63,
      35,    25,   100,    88,    38,    42,    34,    63,    42,    37,
      38,    61,    68,    54,    80,    81,    83,    42,    37,    40,
      40,    80,    63,    66,    48,    63,    63,    36,    34,    24,
      42,    37,    92,    95,    39,   101,    42,    34,    35,    24,
      29,    62,    69,    86,    82,    36,    96,   100,    38,   103,
      89,    48,    28,    38,    29,    42,     1,    14,    21,    75,
      34,    83,    40,    34,   104,    36,    34,    35,    28,    63,
      24,    34,    75,    63,    43,    35,    48,   101,    63,   104,
     105,   106,    48,    67,    48,    43,    78,    35,    35,    37,
      35,     4,    70,    35,    76,    48,   106,     3,    74,    48,
      41,    34,    20,    71,    48,    36,    79,    35,    77,    42,
      75,    72,    34,    48,    35,    73,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    47,    46,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    52,    53,    53,    54,    54,    54,    54,
      55,    55,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    60,    59,    59,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    65,    66,    67,    64,    68,    69,    64,
      71,    72,    73,    70,    74,    70,    70,    76,    77,    75,
      78,    75,    75,    75,    79,    79,    80,    80,    81,    82,
      81,    83,    85,    86,    84,    88,    89,    87,    91,    92,
      90,    93,    93,    94,    95,    94,    96,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   103,   103,   104,
     105,   105,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     4,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     5,     1,     3,     3,     4,     3,     3,
       3,     3,     1,     3,     4,     0,    11,     7,     3,     1,
       1,     3,     3,     3,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     0,     0,     0,    11,     0,     0,     9,
       0,     0,     0,    12,     0,     5,     0,     0,     0,     9,
       0,     4,     2,     0,     3,     1,     1,     0,     1,     0,
       4,     2,     0,     0,    10,     0,     0,    10,     0,     0,
       7,     1,     0,     1,     0,     4,     1,     4,     1,     0,
       1,     3,     1,     0,     4,     0,     8,     2,     0,     3,
       1,     3,     1,     1
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
  case 3: /* $@1: %empty  */
#line 81 "parser.y"
               {
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
            }
#line 1491 "parser.tab.c"
    break;

  case 4: /* bloque: '{' $@1 instrucciones '}'  */
#line 90 "parser.y"
                          {
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
            }
#line 1500 "parser.tab.c"
    break;

  case 16: /* instruccion: RETURN expresion ';'  */
#line 109 "parser.y"
                                  {
                imprimir_indentacion();
                fprintf(yyout_py, "return %s\n", (yyvsp[-1].info_expr)->codigo);
                free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
           }
#line 1510 "parser.tab.c"
    break;

  case 17: /* instruccion: RETURN ';'  */
#line 114 "parser.y"
                        {
                imprimir_indentacion();
                fprintf(yyout_py, "return\n");
           }
#line 1519 "parser.tab.c"
    break;

  case 18: /* declaracion: prefijo_declaracion declarar_lista_ids ';'  */
#line 120 "parser.y"
                                                         { es_constante_actual = 0; }
#line 1525 "parser.tab.c"
    break;

  case 19: /* declaracion: CONST declarar_lista_ids ';'  */
#line 121 "parser.y"
                                           {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
#line 1533 "parser.tab.c"
    break;

  case 24: /* prefijo_declaracion: tipo  */
#line 133 "parser.y"
                                       { es_constante_actual = 0; }
#line 1539 "parser.tab.c"
    break;

  case 25: /* prefijo_declaracion: CONST tipo  */
#line 134 "parser.y"
                                       { es_constante_actual = 1; }
#line 1545 "parser.tab.c"
    break;

  case 26: /* tipo: INT  */
#line 137 "parser.y"
              { tipo_actual = T_INT; }
#line 1551 "parser.tab.c"
    break;

  case 27: /* tipo: FLOAT  */
#line 138 "parser.y"
             { tipo_actual = T_FLOAT; }
#line 1557 "parser.tab.c"
    break;

  case 28: /* tipo: CHAR  */
#line 139 "parser.y"
             { tipo_actual = T_CHAR; }
#line 1563 "parser.tab.c"
    break;

  case 29: /* tipo: DOUBLE  */
#line 140 "parser.y"
             { tipo_actual = T_DOUBLE; }
#line 1569 "parser.tab.c"
    break;

  case 30: /* declarar_lista_ids: ID  */
#line 143 "parser.y"
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
#line 1588 "parser.tab.c"
    break;

  case 31: /* declarar_lista_ids: declarar_lista_ids ',' ID  */
#line 157 "parser.y"
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
#line 1607 "parser.tab.c"
    break;

  case 32: /* declarar_lista_ids: ID '=' expresion  */
#line 171 "parser.y"
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
#line 1629 "parser.tab.c"
    break;

  case 33: /* declarar_lista_ids: declarar_lista_ids ',' ID '=' expresion  */
#line 188 "parser.y"
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
#line 1651 "parser.tab.c"
    break;

  case 36: /* asignacion_unitaria: ID '=' expresion  */
#line 211 "parser.y"
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
#line 1674 "parser.tab.c"
    break;

  case 37: /* asignacion_unitaria: ID accesos_array '=' expresion  */
#line 230 "parser.y"
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
#line 1690 "parser.tab.c"
    break;

  case 38: /* asignacion_unitaria: ID '+' '+'  */
#line 241 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[-2].nombre));
                    }
#line 1701 "parser.tab.c"
    break;

  case 39: /* asignacion_unitaria: ID '-' '-'  */
#line 247 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[-2].nombre));
                    }
#line 1712 "parser.tab.c"
    break;

  case 40: /* asignacion_unitaria: '+' '+' ID  */
#line 253 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1723 "parser.tab.c"
    break;

  case 41: /* asignacion_unitaria: '-' '-' ID  */
#line 259 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1734 "parser.tab.c"
    break;

  case 42: /* asignacion_unitaria: ID  */
#line 265 "parser.y"
                         {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL) printf("Error semántico.\n");
                        else { imprimir_indentacion(); fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado); }
                        free((yyvsp[0].nombre));
                    }
#line 1745 "parser.tab.c"
    break;

  case 43: /* accesos_array: '[' expresion ']'  */
#line 274 "parser.y"
                                  {
                    char buf[256];
                    sprintf(buf, "[%s]", (yyvsp[-1].info_expr)->codigo);
                    (yyval.nombre) = strdup(buf);
                    free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
                }
#line 1756 "parser.tab.c"
    break;

  case 44: /* accesos_array: accesos_array '[' expresion ']'  */
#line 280 "parser.y"
                                                {
                    char buf[512];
                    sprintf(buf, "%s[%s]", (yyvsp[-3].nombre), (yyvsp[-1].info_expr)->codigo);
                    (yyval.nombre) = strdup(buf);
                    free((yyvsp[-3].nombre)); free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
                }
#line 1767 "parser.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 288 "parser.y"
           {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}
#line 1779 "parser.tab.c"
    break;

  case 46: /* loop: FOR $@2 '(' for_init condicion_loop ';' loop_consecuencia ')' '{' instrucciones '}'  */
#line 294 "parser.y"
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
#line 1795 "parser.tab.c"
    break;

  case 47: /* loop: WHILE '(' condicion_loop ')' '{' instrucciones '}'  */
#line 305 "parser.y"
                                                        {    
        nivel_indentacion--;
    }
#line 1803 "parser.tab.c"
    break;

  case 48: /* condicion_loop: expresion '=' expresion  */
#line 310 "parser.y"
                                         {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                    nivel_indentacion++;
                    free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 1815 "parser.tab.c"
    break;

  case 49: /* condicion_loop: expresion  */
#line 317 "parser.y"
                           {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", (yyvsp[0].info_expr)->codigo);
                    nivel_indentacion++;
                    free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 1826 "parser.tab.c"
    break;

  case 50: /* loop_consecuencia: ID  */
#line 325 "parser.y"
                      { (yyval.nombre) = strdup(""); }
#line 1832 "parser.tab.c"
    break;

  case 51: /* loop_consecuencia: ID '+' '+'  */
#line 326 "parser.y"
                           {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                }
#line 1845 "parser.tab.c"
    break;

  case 52: /* loop_consecuencia: '-' '-' ID  */
#line 334 "parser.y"
                            {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                    if (entrada != NULL){
                        char buf[256];
                        snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                }
#line 1858 "parser.tab.c"
    break;

  case 53: /* loop_consecuencia: ID '=' expresion  */
#line 342 "parser.y"
                                   {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada != NULL){
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].info_expr)->codigo);
                        (yyval.nombre) = strdup(buf);
                    } else (yyval.nombre) = strdup("");
                    free((yyvsp[-2].nombre)); free((yyvsp[0].info_expr));
                }
#line 1872 "parser.tab.c"
    break;

  case 54: /* expresion: ID  */
#line 353 "parser.y"
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
#line 1892 "parser.tab.c"
    break;

  case 55: /* expresion: ID accesos_array  */
#line 369 "parser.y"
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
#line 1912 "parser.tab.c"
    break;

  case 56: /* expresion: llamada_funcion_expr  */
#line 385 "parser.y"
                                 {
                (yyval.info_expr) = (yyvsp[0].info_expr);
          }
#line 1920 "parser.tab.c"
    break;

  case 57: /* expresion: NUMERO  */
#line 388 "parser.y"
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
#line 1937 "parser.tab.c"
    break;

  case 58: /* expresion: expresion '+' expresion  */
#line 400 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s + %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                /* --- NUEVO PUNTO 2: Promoción de tipos automática --- */
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato); 
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 1951 "parser.tab.c"
    break;

  case 59: /* expresion: expresion '-' expresion  */
#line 409 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s - %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 1964 "parser.tab.c"
    break;

  case 60: /* expresion: expresion '*' expresion  */
#line 417 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s * %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 1977 "parser.tab.c"
    break;

  case 61: /* expresion: expresion '/' expresion  */
#line 426 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s / %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = max_tipo((yyvsp[-2].info_expr)->tipo_dato, (yyvsp[0].info_expr)->tipo_dato);
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 1990 "parser.tab.c"
    break;

  case 62: /* expresion: expresion '%' expresion  */
#line 434 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s %% %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2003 "parser.tab.c"
    break;

  case 63: /* expresion: expresion AND expresion  */
#line 442 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s and %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); // Traduccion a python "and"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2016 "parser.tab.c"
    break;

  case 64: /* expresion: expresion OR expresion  */
#line 450 "parser.y"
                                   {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "%s or %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); // Traduccion a python "or"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2029 "parser.tab.c"
    break;

  case 65: /* expresion: '!' expresion  */
#line 458 "parser.y"
                          {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "not %s", (yyvsp[0].info_expr)->codigo); // Traduccion a python "not"
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2042 "parser.tab.c"
    break;

  case 66: /* expresion: expresion '>' expresion  */
#line 466 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s > %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2052 "parser.tab.c"
    break;

  case 67: /* expresion: expresion '<' expresion  */
#line 471 "parser.y"
                                    {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s < %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2062 "parser.tab.c"
    break;

  case 68: /* expresion: expresion IGUAL_IGUAL expresion  */
#line 476 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s == %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2072 "parser.tab.c"
    break;

  case 69: /* expresion: expresion NO_IGUAL expresion  */
#line 481 "parser.y"
                                         {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s != %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2082 "parser.tab.c"
    break;

  case 70: /* expresion: expresion MAYOR_IGUAL expresion  */
#line 486 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s >= %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2092 "parser.tab.c"
    break;

  case 71: /* expresion: expresion MENOR_IGUAL expresion  */
#line 491 "parser.y"
                                            {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion)); char buf[256];
                sprintf(buf, "%s <= %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo); (yyval.info_expr)->codigo = strdup(buf); (yyval.info_expr)->tipo_dato = T_INT;
                free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
          }
#line 2102 "parser.tab.c"
    break;

  case 72: /* expresion: '(' expresion ')'  */
#line 496 "parser.y"
                              {
                (yyval.info_expr) = malloc(sizeof(struct InfoExpresion));
                char buf[256];
                sprintf(buf, "(%s)", (yyvsp[-1].info_expr)->codigo);
                (yyval.info_expr)->codigo = strdup(buf);
                (yyval.info_expr)->tipo_dato = (yyvsp[-1].info_expr)->tipo_dato; 
                free((yyvsp[-1].info_expr)->codigo); free((yyvsp[-1].info_expr));
          }
#line 2115 "parser.tab.c"
    break;

  case 73: /* $@3: %empty  */
#line 506 "parser.y"
                          {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        }
#line 2124 "parser.tab.c"
    break;

  case 74: /* $@4: %empty  */
#line 509 "parser.y"
                           {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        }
#line 2133 "parser.tab.c"
    break;

  case 75: /* $@5: %empty  */
#line 512 "parser.y"
                                { 
            nivel_indentacion--;
        }
#line 2141 "parser.tab.c"
    break;

  case 77: /* $@6: %empty  */
#line 515 "parser.y"
                                   {
            
        }
#line 2149 "parser.tab.c"
    break;

  case 78: /* $@7: %empty  */
#line 517 "parser.y"
             {
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", (yyvsp[-3].info_expr)->codigo);
            nivel_indentacion++;
            free((yyvsp[-3].info_expr));
        }
#line 2160 "parser.tab.c"
    break;

  case 79: /* condicionales: SWITCH '(' expresion ')' $@6 '{' $@7 switch_cases '}'  */
#line 522 "parser.y"
                           {
            nivel_indentacion--;
        }
#line 2168 "parser.tab.c"
    break;

  case 80: /* $@8: %empty  */
#line 527 "parser.y"
                             { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           }
#line 2177 "parser.tab.c"
    break;

  case 81: /* $@9: %empty  */
#line 531 "parser.y"
                            { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           }
#line 2186 "parser.tab.c"
    break;

  case 82: /* $@10: %empty  */
#line 535 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2194 "parser.tab.c"
    break;

  case 84: /* $@11: %empty  */
#line 539 "parser.y"
                { 
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           }
#line 2204 "parser.tab.c"
    break;

  case 85: /* bloque_else: ELSE $@11 '{' instrucciones '}'  */
#line 544 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2212 "parser.tab.c"
    break;

  case 87: /* $@12: %empty  */
#line 551 "parser.y"
                                    {
                    if (strchr((yyvsp[-1].info_expr)->codigo, '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, (yyvsp[-1].info_expr)->codigo);
                    }
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", (yyvsp[-1].info_expr)->codigo);
                    nivel_indentacion++; 
                    free((yyvsp[-1].info_expr));
    }
#line 2226 "parser.tab.c"
    break;

  case 88: /* $@13: %empty  */
#line 559 "parser.y"
                              {
        nivel_indentacion--;
    }
#line 2234 "parser.tab.c"
    break;

  case 90: /* $@14: %empty  */
#line 562 "parser.y"
                              {
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
#line 2244 "parser.tab.c"
    break;

  case 91: /* switch_cases: DEFAULT ':' $@14 instrucciones  */
#line 567 "parser.y"
                            {
                    nivel_indentacion--;
              }
#line 2252 "parser.tab.c"
    break;

  case 92: /* switch_cases: error switch_cases  */
#line 570 "parser.y"
                                     { 
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; 
              }
#line 2261 "parser.tab.c"
    break;

  case 94: /* condicion_IF: expresion '=' expresion  */
#line 577 "parser.y"
                                          {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace.\n");
                    fprintf(yyout_py, "%s = %s", (yyvsp[-2].info_expr)->codigo, (yyvsp[0].info_expr)->codigo);
                    free((yyvsp[-2].info_expr)->codigo); free((yyvsp[-2].info_expr)); free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 2271 "parser.tab.c"
    break;

  case 95: /* condicion_IF: expresion  */
#line 582 "parser.y"
                           {
                    fprintf(yyout_py, "%s", (yyvsp[0].info_expr)->codigo);
                    free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
            }
#line 2280 "parser.tab.c"
    break;

  case 99: /* $@15: %empty  */
#line 593 "parser.y"
                                        { fprintf(yyout_py, ", "); }
#line 2286 "parser.tab.c"
    break;

  case 101: /* parametro_void: tipo ID  */
#line 596 "parser.y"
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
#line 2307 "parser.tab.c"
    break;

  case 102: /* $@16: %empty  */
#line 614 "parser.y"
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
#line 2330 "parser.tab.c"
    break;

  case 103: /* $@17: %empty  */
#line 631 "parser.y"
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
                    printf("Función '%s' declarada con %d parámetro(s) y tipo de retorno 'void'.\n", (yyvsp[-4].nombre), contador_parametros);
                    contador_parametros = 0;
                    free((yyvsp[-4].nombre));
                }
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2354 "parser.tab.c"
    break;

  case 104: /* funcion_void: VOID ID '(' $@16 declaracion_variables_funcion ')' $@17 '{' instrucciones '}'  */
#line 649 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2365 "parser.tab.c"
    break;

  case 105: /* $@18: %empty  */
#line 657 "parser.y"
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
#line 2388 "parser.tab.c"
    break;

  case 106: /* $@19: %empty  */
#line 674 "parser.y"
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
                    printf("Función '%s' declarada con %d parámetro(s) y tipo de retorno '%s'.\n",
                           (yyvsp[-4].nombre), contador_parametros, nombre_tipo(entrada->tipo_base));
                }
                contador_parametros = 0;
                free((yyvsp[-4].nombre));
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2411 "parser.tab.c"
    break;

  case 107: /* funcion_NO_void: prefijo_declaracion ID '(' $@18 declaracion_variables_funcion ')' $@19 '{' instrucciones '}'  */
#line 691 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2422 "parser.tab.c"
    break;

  case 108: /* $@20: %empty  */
#line 698 "parser.y"
                                   {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-1].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: la función '%s' no existe.\n", (yyvsp[-1].nombre));
                }
                imprimir_indentacion();
                fprintf(yyout_py, "%s(", (yyvsp[-1].nombre));
            }
#line 2435 "parser.tab.c"
    break;

  case 109: /* $@21: %empty  */
#line 705 "parser.y"
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
#line 2468 "parser.tab.c"
    break;

  case 114: /* $@22: %empty  */
#line 740 "parser.y"
                                                       { fprintf(yyout_py, ", "); }
#line 2474 "parser.tab.c"
    break;

  case 116: /* parametro_llamar_funcion: expresion  */
#line 743 "parser.y"
                                         { 
        fprintf(yyout_py, "%s", (yyvsp[0].info_expr)->codigo);
        // Guardar el tipo del argumento en el buffer de llamadas
        if (contador_parametros < MAX_PARAMS)
            tipos_args_actuales[contador_parametros] = (yyvsp[0].info_expr)->tipo_dato;
        contador_parametros++;
        free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr));
    }
#line 2487 "parser.tab.c"
    break;

  case 117: /* llamada_funcion_expr: ID '(' usar_variables_funcion_expr ')'  */
#line 754 "parser.y"
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
#line 2525 "parser.tab.c"
    break;

  case 118: /* usar_variables_funcion_expr: lista_parametros_llamar_funcion_expr  */
#line 789 "parser.y"
                                                                       { (yyval.nombre) = (yyvsp[0].nombre); }
#line 2531 "parser.tab.c"
    break;

  case 119: /* usar_variables_funcion_expr: %empty  */
#line 790 "parser.y"
                                               { (yyval.nombre) = strdup(""); }
#line 2537 "parser.tab.c"
    break;

  case 120: /* lista_parametros_llamar_funcion_expr: expresion  */
#line 793 "parser.y"
                                                     { 
            (yyval.nombre) = strdup((yyvsp[0].info_expr)->codigo);
            // Guardar el tipo del argumento en el buffer de llamadas
            if (contador_parametros < MAX_PARAMS)
                tipos_args_actuales[contador_parametros] = (yyvsp[0].info_expr)->tipo_dato;
            contador_parametros++;
            free((yyvsp[0].info_expr)->codigo); free((yyvsp[0].info_expr)); 
        }
#line 2550 "parser.tab.c"
    break;

  case 121: /* lista_parametros_llamar_funcion_expr: lista_parametros_llamar_funcion_expr ',' expresion  */
#line 801 "parser.y"
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
#line 2565 "parser.tab.c"
    break;

  case 126: /* arrays: prefijo_declaracion ID '[' volumen_array ']' dimension_array asignacion_array ';'  */
#line 817 "parser.y"
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
#line 2589 "parser.tab.c"
    break;

  case 127: /* asignacion_array: '=' inicializador_array  */
#line 838 "parser.y"
                                              { (yyval.nombre) = strdup((yyvsp[0].nombre)); free((yyvsp[0].nombre)); }
#line 2595 "parser.tab.c"
    break;

  case 128: /* asignacion_array: %empty  */
#line 839 "parser.y"
                                   { (yyval.nombre) = NULL; }
#line 2601 "parser.tab.c"
    break;

  case 129: /* inicializador_array: '{' lista_inicializadores '}'  */
#line 844 "parser.y"
    {
        (yyval.nombre) = malloc(strlen((yyvsp[-1].nombre)) + 3);
        sprintf((yyval.nombre), "[%s]", (yyvsp[-1].nombre));
        free((yyvsp[-1].nombre));
    }
#line 2611 "parser.tab.c"
    break;

  case 130: /* lista_inicializadores: valor_o_anidado  */
#line 853 "parser.y"
    {
        (yyval.nombre) = strdup((yyvsp[0].nombre));
        free((yyvsp[0].nombre));
    }
#line 2620 "parser.tab.c"
    break;

  case 131: /* lista_inicializadores: lista_inicializadores ',' valor_o_anidado  */
#line 858 "parser.y"
    {
        (yyval.nombre) = malloc(strlen((yyvsp[-2].nombre)) + strlen((yyvsp[0].nombre)) + 3);
        sprintf((yyval.nombre), "%s, %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
        free((yyvsp[-2].nombre));
        free((yyvsp[0].nombre));
    }
#line 2631 "parser.tab.c"
    break;

  case 132: /* valor_o_anidado: expresion  */
#line 867 "parser.y"
              {
        (yyval.nombre) = strdup((yyvsp[0].info_expr)->codigo);
        free((yyvsp[0].info_expr));
    }
#line 2640 "parser.tab.c"
    break;

  case 133: /* valor_o_anidado: inicializador_array  */
#line 871 "parser.y"
                          {
        (yyval.nombre) = strdup((yyvsp[0].nombre)); 
        free((yyvsp[0].nombre));
    }
#line 2649 "parser.tab.c"
    break;


#line 2653 "parser.tab.c"

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

#line 877 "parser.y"


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
