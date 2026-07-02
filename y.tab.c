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


extern int yylineno; //contador de lineas

extern FILE *yyin; // Variable que usa Lex para leer la entrada         
FILE *yyout_py;    // Nuestra variable para escribir la salida Python 
int nivel_indentacion = 0; 
void imprimir_indentacion() {
    for (int i = 0; i < nivel_indentacion; i++) {
        fprintf(yyout_py, "    "); // Imprime 4 espacios por nivel
    }
}


#line 99 "y.tab.c"

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
    BREAK = 274,                   /* BREAK  */
    DEFAULT = 275,                 /* DEFAULT  */
    ID = 276,                      /* ID  */
    NUMERO = 277                   /* NUMERO  */
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
#define BREAK 274
#define DEFAULT 275
#define ID 276
#define NUMERO 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

    char *nombre;     
    double val_num;   

#line 198 "y.tab.c"

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
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 20,                   /* DEFAULT  */
  YYSYMBOL_ID = 21,                        /* ID  */
  YYSYMBOL_NUMERO = 22,                    /* NUMERO  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* ':'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_bloque = 41,                    /* bloque  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_instrucciones = 43,             /* instrucciones  */
  YYSYMBOL_instruccion = 44,               /* instruccion  */
  YYSYMBOL_declaracion = 45,               /* declaracion  */
  YYSYMBOL_for_init = 46,                  /* for_init  */
  YYSYMBOL_asignacion = 47,                /* asignacion  */
  YYSYMBOL_prefijo_declaracion = 48,       /* prefijo_declaracion  */
  YYSYMBOL_tipo = 49,                      /* tipo  */
  YYSYMBOL_declarar_lista_ids = 50,        /* declarar_lista_ids  */
  YYSYMBOL_lista_asignaciones = 51,        /* lista_asignaciones  */
  YYSYMBOL_asignacion_unitaria = 52,       /* asignacion_unitaria  */
  YYSYMBOL_loop = 53,                      /* loop  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_condicion_loop = 55,            /* condicion_loop  */
  YYSYMBOL_loop_consecuencia = 56,         /* loop_consecuencia  */
  YYSYMBOL_expresion = 57,                 /* expresion  */
  YYSYMBOL_condicionales = 58,             /* condicionales  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_bloque_else = 64,               /* bloque_else  */
  YYSYMBOL_65_8 = 65,                      /* $@8  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_switch_cases = 69,              /* switch_cases  */
  YYSYMBOL_70_12 = 70,                     /* $@12  */
  YYSYMBOL_71_13 = 71,                     /* $@13  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_condicion_IF = 73,              /* condicion_IF  */
  YYSYMBOL_declaracion_variables_funcion = 74, /* declaracion_variables_funcion  */
  YYSYMBOL_lista_parametros = 75,          /* lista_parametros  */
  YYSYMBOL_76_15 = 76,                     /* $@15  */
  YYSYMBOL_parametro_void = 77,            /* parametro_void  */
  YYSYMBOL_funcion_void = 78,              /* funcion_void  */
  YYSYMBOL_79_16 = 79,                     /* $@16  */
  YYSYMBOL_80_17 = 80,                     /* $@17  */
  YYSYMBOL_funcion_NO_void = 81,           /* funcion_NO_void  */
  YYSYMBOL_82_18 = 82,                     /* $@18  */
  YYSYMBOL_83_19 = 83,                     /* $@19  */
  YYSYMBOL_llamar_funcion = 84,            /* llamar_funcion  */
  YYSYMBOL_85_20 = 85,                     /* $@20  */
  YYSYMBOL_86_21 = 86,                     /* $@21  */
  YYSYMBOL_usar_variables_funcion = 87,    /* usar_variables_funcion  */
  YYSYMBOL_lista_parametros_llamar_funcion = 88, /* lista_parametros_llamar_funcion  */
  YYSYMBOL_89_22 = 89,                     /* $@22  */
  YYSYMBOL_parametro_llamar_funcion = 90,  /* parametro_llamar_funcion  */
  YYSYMBOL_volumen_array = 91,             /* volumen_array  */
  YYSYMBOL_dimension_array = 92,           /* dimension_array  */
  YYSYMBOL_arrays = 93,                    /* arrays  */
  YYSYMBOL_asignacion_array = 94,          /* asignacion_array  */
  YYSYMBOL_inicializador_array = 95,       /* inicializador_array  */
  YYSYMBOL_lista_inicializadores = 96,     /* lista_inicializadores  */
  YYSYMBOL_valor_o_anidado = 97            /* valor_o_anidado  */
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
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    25,    23,    30,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    29,
      35,    31,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    53,    53,    72,    73,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    87,    88,    91,    94,
      95,    98,   100,   101,   104,   105,   106,   107,   110,   126,
     142,   159,   178,   179,   182,   192,   202,   212,   222,   232,
     244,   244,   264,   270,   277,   283,   289,   295,   301,   307,
     315,   324,   335,   346,   360,   373,   378,   384,   390,   396,
     404,   407,   410,   404,   413,   415,   413,   428,   433,   437,
     428,   441,   441,   451,   454,   462,   454,   465,   465,   474,
     481,   484,   489,   493,   497,   501,   505,   509,   515,   516,
     519,   520,   520,   527,   544,   555,   544,   565,   585,   565,
     598,   606,   598,   611,   612,   615,   616,   616,   623,   629,
     630,   633,   634,   637,   659,   663,   670,   682,   687,   700,
     705
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
  "CASE", "VOID", "MAYOR_IGUAL", "IGUAL_IGUAL", "MENOR_IGUAL", "BREAK",
  "DEFAULT", "ID", "NUMERO", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'",
  "';'", "','", "'='", "'('", "')'", "'>'", "'<'", "':'", "'['", "']'",
  "$accept", "programa", "bloque", "$@1", "instrucciones", "instruccion",
  "declaracion", "for_init", "asignacion", "prefijo_declaracion", "tipo",
  "declarar_lista_ids", "lista_asignaciones", "asignacion_unitaria",
  "loop", "$@2", "condicion_loop", "loop_consecuencia", "expresion",
  "condicionales", "$@3", "$@4", "$@5", "$@6", "$@7", "bloque_else", "$@8",
  "$@9", "$@10", "$@11", "switch_cases", "$@12", "$@13", "$@14",
  "condicion_IF", "declaracion_variables_funcion", "lista_parametros",
  "$@15", "parametro_void", "funcion_void", "$@16", "$@17",
  "funcion_NO_void", "$@18", "$@19", "llamar_funcion", "$@20", "$@21",
  "usar_variables_funcion", "lista_parametros_llamar_funcion", "$@22",
  "parametro_llamar_funcion", "volumen_array", "dimension_array", "arrays",
  "asignacion_array", "inicializador_array", "lista_inicializadores",
  "valor_o_anidado", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-81)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -170,     7,   376,  -170,   -16,     2,  -170,  -170,  -170,     1,
    -170,  -170,    21,    43,    66,    36,     0,  -170,  -170,  -170,
    -170,  -170,  -170,    44,  -170,    -1,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,    35,    74,  -170,    62,    84,    35,
      87,    95,    98,    35,  -170,   103,   104,  -170,   -12,    78,
    -170,    12,    35,  -170,  -170,    35,    97,    86,    35,  -170,
     121,    31,    90,  -170,  -170,  -170,   188,    35,  -170,  -170,
      72,  -170,   124,  -170,   125,  -170,   110,   117,   114,   126,
      35,    35,    35,    35,    35,    35,    35,    35,    35,   188,
     120,  -170,    35,  -170,   133,  -170,   179,   188,   128,   127,
    -170,  -170,   179,  -170,   130,    35,    35,    35,    35,    35,
      35,  -170,  -170,  -170,   188,   188,   188,   137,   137,  -170,
     188,   188,   188,    35,   136,   139,   149,   141,   152,  -170,
    -170,  -170,   160,   157,   188,   188,   188,   188,   188,   188,
     172,   168,   188,   -10,  -170,  -170,  -170,  -170,   180,    35,
    -170,   124,   170,  -170,  -170,   -18,   190,   182,     3,   193,
     179,  -170,  -170,   194,   198,   199,   209,   195,   205,    35,
     196,   212,     3,    35,   204,   213,  -170,  -170,  -170,   157,
       5,  -170,  -170,  -170,  -170,   188,  -170,  -170,  -170,    38,
    -170,  -170,   222,   249,  -170,   188,  -170,    48,  -170,   238,
     272,  -170,  -170,  -170,    35,  -170,     5,   241,  -170,  -170,
    -170,   376,   135,  -170,   215,   221,   299,   225,  -170,  -170,
     234,  -170,    35,   322,  -170,   232,  -170,     3,  -170,  -170,
     239,  -170,   349,  -170,   238,  -170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,    24,    25,    26,     0,
      27,    40,     0,     0,    39,     0,     0,     3,    18,     9,
       5,     7,     8,     0,    22,     0,    32,    10,    11,    12,
      13,    14,    15,    60,     0,    28,    23,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     6,    28,     0,
      21,     0,     0,    54,    55,     0,     0,    49,     0,    17,
       0,     0,     0,    94,    35,    36,    34,   104,    37,    38,
       0,    97,   110,    16,    39,    33,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      29,    19,     0,    20,     0,    64,    89,   108,     0,   103,
     105,     4,    89,   109,     0,     0,     0,     0,     0,     0,
       0,    61,    59,     6,    46,    48,    47,    56,    57,    58,
      43,    44,    45,     0,     0,     0,     0,     0,    88,    90,
     101,   106,     0,   112,    84,    86,    85,    81,    82,    83,
       0,     0,    31,     0,    65,    93,    95,    91,     0,     0,
      98,   110,   115,     6,    42,    50,     0,     0,     0,     0,
       0,   102,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    92,     6,   112,
       0,   114,   113,    62,    51,    53,    52,     6,    79,     0,
      77,    66,     0,     0,   111,   119,   120,     0,   117,    73,
       0,    74,     6,    96,     0,   116,     0,    71,    63,    41,
       6,    78,     0,   118,     0,     0,     0,     0,    67,     6,
       0,    99,     0,     0,    75,     0,    72,     0,    68,    76,
       0,     6,     0,    69,    73,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,  -170,  -170,   -47,  -170,   206,  -170,   207,   208,
      -8,   262,  -170,   223,  -170,  -170,   197,  -170,   -37,  -170,
    -170,  -170,  -170,  -170,  -170,    52,  -170,  -170,  -170,  -170,
    -169,  -170,  -170,  -170,    68,   186,  -170,  -170,   131,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,   143,   146,   115,  -170,  -170,   138,  -170,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    47,     2,    20,    21,    92,    22,    23,
      24,    49,    25,    26,    27,    38,    56,   157,    57,    28,
      52,   140,   199,   125,   158,   208,   222,   230,   234,   215,
     175,   210,   227,   202,    77,   127,   128,   160,   129,    29,
      96,   159,    30,   102,   163,    31,    67,   148,    98,    99,
     149,   100,   104,   152,    32,   166,   196,   197,   198
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    36,    62,   188,   172,   168,    66,     3,     6,     7,
       8,   155,    10,   169,   156,    76,    33,   173,    78,    58,
      71,    89,    35,   174,    46,    72,    53,    54,    50,    51,
      97,   -80,   180,    74,    34,    15,    16,    55,     6,     7,
       8,     9,    10,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    74,    39,    15,    16,    53,    54,   229,    45,
      18,    83,    84,    85,    40,    48,   141,    55,   134,   135,
     136,   137,   138,   139,   201,     4,   205,     5,   206,     6,
       7,     8,     9,    10,    11,    12,   142,    13,   126,    41,
      42,    59,    60,    14,   126,    15,    16,    43,    44,    17,
     101,    18,    80,    81,    82,    58,   167,    73,    60,    83,
      84,    85,    97,    83,    84,    85,    61,    86,    64,    63,
      87,    88,    65,    95,    68,    69,   105,   106,   107,   192,
      79,   193,   185,    83,    84,    85,   189,    83,    84,    85,
     200,   108,    90,   195,   109,   110,   103,   112,    41,    42,
     111,   123,   126,   113,    35,   211,    43,   131,    83,    84,
      85,   130,    85,   216,   217,   143,   144,   212,   133,   195,
     145,     4,   223,     5,   146,     6,     7,     8,     9,    10,
      11,    12,   147,    13,   232,    76,     6,     7,     8,    14,
      10,    15,    16,   150,   151,    17,   154,    18,     4,   153,
       5,   165,     6,     7,     8,     9,    10,    11,    12,   161,
      13,    83,    84,    85,   170,   171,    14,   186,    15,    16,
     176,   178,    17,   183,    18,     4,   180,     5,   184,     6,
       7,     8,     9,    10,    11,    12,   179,    13,   182,   187,
     190,   191,   207,    14,   214,    15,    16,   218,   219,    17,
     203,    18,     4,   221,     5,   204,     6,     7,     8,     9,
      10,    11,    12,   224,    13,   228,   231,    91,    93,    94,
      14,    37,    15,    16,    75,     4,    17,     5,    18,     6,
       7,     8,     9,    10,    11,    12,   235,    13,   132,   124,
     225,   177,   162,    14,   194,    15,    16,   164,   213,    17,
     209,    18,     4,   181,     5,     0,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,     0,   220,     0,
      14,     0,    15,    16,     0,     4,    17,     5,    18,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
       0,     0,     0,    14,     0,    15,    16,     0,     0,    17,
     226,    18,     4,     0,     5,     0,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,     0,     0,     0,
      14,     0,    15,    16,     0,     0,    17,   233,    18,     4,
       0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,     0,     0,     0,    14,     0,    15,
      16,     0,     0,    17,     0,    18
};

static const yytype_int16 yycheck[] =
{
      47,     9,    39,   172,     1,    23,    43,     0,     7,     8,
       9,    21,    11,    31,    24,    52,    32,    14,    55,    31,
      32,    58,    21,    20,    24,    37,    21,    22,    29,    30,
      67,    28,    27,    21,    32,    23,    24,    32,     7,     8,
       9,    10,    11,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    21,    32,    23,    24,    21,    22,   227,    23,
      29,    23,    24,    25,    21,    21,   113,    32,   105,   106,
     107,   108,   109,   110,    36,     3,    28,     5,    30,     7,
       8,     9,    10,    11,    12,    13,   123,    15,    96,    23,
      24,    29,    30,    21,   102,    23,    24,    31,    32,    27,
      28,    29,    16,    17,    18,    31,   153,    29,    30,    23,
      24,    25,   149,    23,    24,    25,    32,    31,    23,    32,
      34,    35,    24,    33,    21,    21,    16,    17,    18,   176,
      33,   178,   169,    23,    24,    25,   173,    23,    24,    25,
     187,    31,    21,   180,    34,    35,    22,    33,    23,    24,
      33,    31,   160,    27,    21,   202,    31,    30,    23,    24,
      25,    33,    25,   210,    29,    29,    27,   204,    38,   206,
      21,     3,   219,     5,    33,     7,     8,     9,    10,    11,
      12,    13,    30,    15,   231,   222,     7,     8,     9,    21,
      11,    23,    24,    33,    37,    27,    28,    29,     3,    27,
       5,    31,     7,     8,     9,    10,    11,    12,    13,    29,
      15,    23,    24,    25,    24,    33,    21,    21,    23,    24,
      27,    27,    27,    28,    29,     3,    27,     5,    23,     7,
       8,     9,    10,    11,    12,    13,    38,    15,    29,    27,
      36,    28,     4,    21,     3,    23,    24,    32,    27,    27,
      28,    29,     3,    28,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    29,    15,    33,    27,    61,    61,    61,
      21,     9,    23,    24,    51,     3,    27,     5,    29,     7,
       8,     9,    10,    11,    12,    13,   234,    15,   102,    92,
     222,   160,   149,    21,   179,    23,    24,   151,   206,    27,
      28,    29,     3,   165,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    19,    -1,
      21,    -1,    23,    24,    -1,     3,    27,     5,    29,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,    27,
      28,    29,     3,    -1,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    23,    24,    -1,    -1,    27,    28,    29,     3,
      -1,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,    -1,    -1,    27,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    43,     0,     3,     5,     7,     8,     9,    10,
      11,    12,    13,    15,    21,    23,    24,    27,    29,    41,
      44,    45,    47,    48,    49,    51,    52,    53,    58,    78,
      81,    84,    93,    32,    32,    21,    49,    50,    54,    32,
      21,    23,    24,    31,    32,    23,    24,    42,    21,    50,
      29,    30,    59,    21,    22,    32,    55,    57,    31,    29,
      30,    32,    57,    32,    23,    24,    57,    85,    21,    21,
      43,    32,    37,    29,    21,    52,    57,    73,    57,    33,
      16,    17,    18,    23,    24,    25,    31,    34,    35,    57,
      21,    45,    46,    47,    48,    33,    79,    57,    87,    88,
      90,    28,    82,    22,    91,    16,    17,    18,    31,    34,
      35,    33,    33,    27,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    31,    55,    62,    49,    74,    75,    77,
      33,    30,    74,    38,    57,    57,    57,    57,    57,    57,
      60,    43,    57,    29,    27,    21,    33,    30,    86,    89,
      33,    37,    92,    27,    28,    21,    24,    56,    63,    80,
      76,    29,    90,    83,    91,    31,    94,    43,    23,    31,
      24,    33,     1,    14,    20,    69,    27,    77,    27,    38,
      27,    95,    29,    28,    23,    57,    21,    27,    69,    57,
      36,    28,    43,    43,    92,    57,    95,    96,    97,    61,
      43,    36,    72,    28,     6,    28,    30,     4,    64,    28,
      70,    43,    57,    97,     3,    68,    43,    29,    32,    27,
      19,    28,    65,    43,    29,    73,    28,    71,    33,    69,
      66,    27,    43,    28,    67,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    42,    41,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    45,    46,
      46,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      54,    53,    53,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      59,    60,    61,    58,    62,    63,    58,    65,    66,    67,
      64,    68,    64,    64,    70,    71,    69,    72,    69,    69,
      69,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    76,    75,    77,    79,    80,    78,    82,    83,    81,
      85,    86,    84,    87,    87,    88,    89,    88,    90,    91,
      91,    92,    92,    93,    94,    94,    95,    96,    96,    97,
      97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     4,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     5,     1,     3,     3,     3,     3,     3,     3,     1,
       0,    11,     7,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       0,     0,     0,    11,     0,     0,     9,     0,     0,     0,
      12,     0,     5,     0,     0,     0,     9,     0,     4,     2,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     0,
       1,     0,     4,     2,     0,     0,    10,     0,     0,    13,
       0,     0,     7,     1,     0,     1,     0,     4,     1,     1,
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
  case 3: /* $@1: %empty  */
#line 53 "parser.y"
               {
                /* Acción intermedia: Al abrir '{', creamos entorno local */
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
            }
#line 1482 "y.tab.c"
    break;

  case 4: /* bloque: '{' $@1 instrucciones '}'  */
#line 63 "parser.y"
                          {
                /* Acción final: Al cerrar '}', regresamos de nivel al padre */
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                
                /* Opcional: Podés liberar la memoria de 'viejo' aquí si querés */
            }
#line 1494 "y.tab.c"
    break;

  case 16: /* declaracion: prefijo_declaracion declarar_lista_ids ';'  */
#line 87 "parser.y"
                                                         { es_constante_actual = 0; }
#line 1500 "y.tab.c"
    break;

  case 17: /* declaracion: CONST declarar_lista_ids ';'  */
#line 88 "parser.y"
                                           {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
#line 1508 "y.tab.c"
    break;

  case 22: /* prefijo_declaracion: tipo  */
#line 100 "parser.y"
                                       { es_constante_actual = 0; }
#line 1514 "y.tab.c"
    break;

  case 23: /* prefijo_declaracion: CONST tipo  */
#line 101 "parser.y"
                                       { es_constante_actual = 1; }
#line 1520 "y.tab.c"
    break;

  case 24: /* tipo: INT  */
#line 104 "parser.y"
              { tipo_actual = T_INT; }
#line 1526 "y.tab.c"
    break;

  case 25: /* tipo: FLOAT  */
#line 105 "parser.y"
             { tipo_actual = T_FLOAT; }
#line 1532 "y.tab.c"
    break;

  case 26: /* tipo: CHAR  */
#line 106 "parser.y"
             { tipo_actual = T_CHAR; }
#line 1538 "y.tab.c"
    break;

  case 27: /* tipo: DOUBLE  */
#line 107 "parser.y"
             { tipo_actual = T_DOUBLE; }
#line 1544 "y.tab.c"
    break;

  case 28: /* declarar_lista_ids: ID  */
#line 110 "parser.y"
                        {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Cada uno imprime su espacio al inicio
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1565 "y.tab.c"
    break;

  case 29: /* declarar_lista_ids: declarar_lista_ids ',' ID  */
#line 126 "parser.y"
                                     {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1586 "y.tab.c"
    break;

  case 30: /* declarar_lista_ids: ID '=' expresion  */
#line 142 "parser.y"
                            {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    // ¡OJO! Te faltaba esta línea fundamental para que el while sepa su ID real:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno; 

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].nombre));
                }
                free((yyvsp[-2].nombre));
         }
#line 1608 "y.tab.c"
    break;

  case 31: /* declarar_lista_ids: declarar_lista_ids ',' ID '=' expresion  */
#line 159 "parser.y"
                                                   {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    // ¡OJO! Aquí también te faltaba:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    
                    imprimir_indentacion(); // Indentamos
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].nombre));
                }
                free((yyvsp[-2].nombre));
         }
#line 1630 "y.tab.c"
    break;

  case 34: /* asignacion_unitaria: ID '=' expresion  */
#line 182 "parser.y"
                                       {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].nombre));
                        }
                        free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
                    }
#line 1645 "y.tab.c"
    break;

  case 35: /* asignacion_unitaria: ID '+' '+'  */
#line 192 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[-2].nombre));
                    }
#line 1660 "y.tab.c"
    break;

  case 36: /* asignacion_unitaria: ID '-' '-'  */
#line 202 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[-2].nombre));
                    }
#line 1675 "y.tab.c"
    break;

  case 37: /* asignacion_unitaria: '+' '+' ID  */
#line 212 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1690 "y.tab.c"
    break;

  case 38: /* asignacion_unitaria: '-' '-' ID  */
#line 222 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1705 "y.tab.c"
    break;

  case 39: /* asignacion_unitaria: ID  */
#line 232 "parser.y"
                         {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1720 "y.tab.c"
    break;

  case 40: /* $@2: %empty  */
#line 244 "parser.y"
           {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}
#line 1732 "y.tab.c"
    break;

  case 41: /* loop: FOR $@2 '(' for_init condicion_loop ';' loop_consecuencia ')' '{' instrucciones '}'  */
#line 250 "parser.y"
                                                                         {
            if ((yyvsp[-4].nombre) && strlen((yyvsp[-4].nombre)) > 0) {
                imprimir_indentacion();
                fprintf(yyout_py, "%s", (yyvsp[-4].nombre));
                free((yyvsp[-4].nombre));
            }

            nivel_indentacion--; // Bajamos la indentación de Python

            /* 2. Destruimos el entorno local del loop */
            struct Entorno *viejo = entorno_actual;
            entorno_actual = entorno_actual->padre;
            free(viejo);
    }
#line 1751 "y.tab.c"
    break;

  case 42: /* loop: WHILE '(' condicion_loop ')' '{' instrucciones '}'  */
#line 264 "parser.y"
                                                        {    
        nivel_indentacion--;
    }
#line 1759 "y.tab.c"
    break;

  case 43: /* condicion_loop: expresion '=' expresion  */
#line 270 "parser.y"
                                         {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1771 "y.tab.c"
    break;

  case 44: /* condicion_loop: expresion '>' expresion  */
#line 277 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s > %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1782 "y.tab.c"
    break;

  case 45: /* condicion_loop: expresion '<' expresion  */
#line 283 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s < %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1793 "y.tab.c"
    break;

  case 46: /* condicion_loop: expresion MAYOR_IGUAL expresion  */
#line 289 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s >= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1804 "y.tab.c"
    break;

  case 47: /* condicion_loop: expresion MENOR_IGUAL expresion  */
#line 295 "parser.y"
                                                 { // NUMERO '<=' ID
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s <= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1815 "y.tab.c"
    break;

  case 48: /* condicion_loop: expresion IGUAL_IGUAL expresion  */
#line 301 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s == %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1826 "y.tab.c"
    break;

  case 49: /* condicion_loop: expresion  */
#line 307 "parser.y"
                        {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[0].nombre));
            }
#line 1837 "y.tab.c"
    break;

  case 50: /* loop_consecuencia: ID  */
#line 315 "parser.y"
                      {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    (yyval.nombre) = strdup("");
                }
            }
#line 1851 "y.tab.c"
    break;

  case 51: /* loop_consecuencia: ID '+' '+'  */
#line 324 "parser.y"
                           {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[-2].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                }
#line 1867 "y.tab.c"
    break;

  case 52: /* loop_consecuencia: '-' '-' ID  */
#line 335 "parser.y"
                            {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                }
#line 1883 "y.tab.c"
    break;

  case 53: /* loop_consecuencia: ID '=' expresion  */
#line 346 "parser.y"
                                   {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada == NULL){
                        printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[-2].nombre));
                        (yyval.nombre) = strdup("");
                    } else {
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].nombre));
                        (yyval.nombre) = strdup(buf);
                    }
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
                }
#line 1900 "y.tab.c"
    break;

  case 54: /* expresion: ID  */
#line 360 "parser.y"
               {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup((yyvsp[0].nombre)); 
                } else {
                    // Si existe, generamos su nombre real de Python con su entorno: ej "i_1"
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                free((yyvsp[0].nombre));
          }
#line 1918 "y.tab.c"
    break;

  case 55: /* expresion: NUMERO  */
#line 373 "parser.y"
                   {
                char buf[50];
                sprintf(buf, "%g", (yyvsp[0].val_num));
                (yyval.nombre) = strdup(buf);
          }
#line 1928 "y.tab.c"
    break;

  case 56: /* expresion: expresion '+' expresion  */
#line 378 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s + %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre)); // Limpiamos memoria de los hijos
          }
#line 1939 "y.tab.c"
    break;

  case 57: /* expresion: expresion '-' expresion  */
#line 384 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s - %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1950 "y.tab.c"
    break;

  case 58: /* expresion: expresion '*' expresion  */
#line 390 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s * %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1961 "y.tab.c"
    break;

  case 59: /* expresion: '(' expresion ')'  */
#line 396 "parser.y"
                              {
                char buf[256];
                sprintf(buf, "(%s)", (yyvsp[-1].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-1].nombre));
          }
#line 1972 "y.tab.c"
    break;

  case 60: /* $@3: %empty  */
#line 404 "parser.y"
                          {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        }
#line 1981 "y.tab.c"
    break;

  case 61: /* $@4: %empty  */
#line 407 "parser.y"
                           {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        }
#line 1990 "y.tab.c"
    break;

  case 62: /* $@5: %empty  */
#line 410 "parser.y"
                                { 
            nivel_indentacion--;
        }
#line 1998 "y.tab.c"
    break;

  case 64: /* $@6: %empty  */
#line 413 "parser.y"
                                   {
            
        }
#line 2006 "y.tab.c"
    break;

  case 65: /* $@7: %empty  */
#line 415 "parser.y"
             {
            /*if($1 == float){
                printf("Error, prohibida sintaxis para switch, la expresion debe ser entera, arreglar linea %d\n", yylineno);
             } TODO cambiar esto cuando ya tengamos un verificador de tipos*/ 
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", (yyvsp[-3].nombre));
            nivel_indentacion++;
            free((yyvsp[-3].nombre));
        }
#line 2020 "y.tab.c"
    break;

  case 66: /* condicionales: SWITCH '(' expresion ')' $@6 '{' $@7 switch_cases '}'  */
#line 423 "parser.y"
                           {
            nivel_indentacion--;
        }
#line 2028 "y.tab.c"
    break;

  case 67: /* $@8: %empty  */
#line 428 "parser.y"
                             { 
                // Traducimos el 'else if' de C al 'elif' de Python
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           }
#line 2038 "y.tab.c"
    break;

  case 68: /* $@9: %empty  */
#line 433 "parser.y"
                            { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           }
#line 2047 "y.tab.c"
    break;

  case 69: /* $@10: %empty  */
#line 437 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2055 "y.tab.c"
    break;

  case 71: /* $@11: %empty  */
#line 441 "parser.y"
                { 
                // El caso base de cierre: un 'else:' simple
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           }
#line 2066 "y.tab.c"
    break;

  case 72: /* bloque_else: ELSE $@11 '{' instrucciones '}'  */
#line 447 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2074 "y.tab.c"
    break;

  case 74: /* $@12: %empty  */
#line 454 "parser.y"
                                    {
                    if (strchr((yyvsp[-1].nombre), '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, (yyvsp[-1].nombre));
                    } //si expresion trae un _ en su nombre, significa que es una variable, algo prohbido en c
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", (yyvsp[-1].nombre));
                    nivel_indentacion++; //subimos la indentación para las instrucciones de este case específico
                    free((yyvsp[-1].nombre));
    }
#line 2088 "y.tab.c"
    break;

  case 75: /* $@13: %empty  */
#line 462 "parser.y"
                              {
        nivel_indentacion--;
    }
#line 2096 "y.tab.c"
    break;

  case 77: /* $@14: %empty  */
#line 465 "parser.y"
                              {
                    // Opcional: Agregamos soporte para el 'default:' de C -> 'case _:' de Python
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
#line 2107 "y.tab.c"
    break;

  case 78: /* switch_cases: DEFAULT ':' $@14 instrucciones  */
#line 471 "parser.y"
                            {
                    nivel_indentacion--;
              }
#line 2115 "y.tab.c"
    break;

  case 79: /* switch_cases: error switch_cases  */
#line 474 "parser.y"
                                     { 
                    // Si algo falla dentro de un case, Bison limpia la pila 
                    // hasta encontrar el inicio del Siguiente CASE o el cierre '}'
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; // Indica a Bison que ya retomamos el control
              }
#line 2126 "y.tab.c"
    break;

  case 81: /* condicion_IF: expresion '=' expresion  */
#line 484 "parser.y"
                                          {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace, por favor, corregir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "%s = %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2136 "y.tab.c"
    break;

  case 82: /* condicion_IF: expresion '>' expresion  */
#line 489 "parser.y"
                                         {
                    fprintf(yyout_py, "%s > %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2145 "y.tab.c"
    break;

  case 83: /* condicion_IF: expresion '<' expresion  */
#line 493 "parser.y"
                                         {
                    fprintf(yyout_py, "%s < %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2154 "y.tab.c"
    break;

  case 84: /* condicion_IF: expresion MAYOR_IGUAL expresion  */
#line 497 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s >= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2163 "y.tab.c"
    break;

  case 85: /* condicion_IF: expresion MENOR_IGUAL expresion  */
#line 501 "parser.y"
                                                 { // NUMERO '<=' ID
                    fprintf(yyout_py, "%s <= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2172 "y.tab.c"
    break;

  case 86: /* condicion_IF: expresion IGUAL_IGUAL expresion  */
#line 505 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s == %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2181 "y.tab.c"
    break;

  case 87: /* condicion_IF: expresion  */
#line 509 "parser.y"
                        {
                    fprintf(yyout_py, "%s", (yyvsp[0].nombre));
                    free((yyvsp[0].nombre));
            }
#line 2190 "y.tab.c"
    break;

  case 91: /* $@15: %empty  */
#line 520 "parser.y"
                                        { 
                        // TRUCO: Imprimimos la coma y un espacio justo cuando Bison detecta el token ','
                        fprintf(yyout_py, ", "); 
                   }
#line 2199 "y.tab.c"
    break;

  case 93: /* parametro_void: tipo ID  */
#line 527 "parser.y"
                         { //realmente es malo este nombre parametro_void, porque las funciones que no son void tambien usan esta gramatica, pero no se me ocurre un nombre bueno y que no sea largo, y tampoco importa tanto
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // Imprimimos el nombre limpio directamente en Python, sin indentación extra
                    fprintf(yyout_py, "%s_%d", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
          }
#line 2219 "y.tab.c"
    break;

  case 94: /* $@16: %empty  */
#line 544 "parser.y"
                                      {
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
                free((yyvsp[-1].nombre));
            }
#line 2236 "y.tab.c"
    break;

  case 95: /* $@17: %empty  */
#line 555 "parser.y"
                                                {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2245 "y.tab.c"
    break;

  case 96: /* funcion_void: VOID ID '(' $@16 declaracion_variables_funcion ')' $@17 '{' instrucciones '}'  */
#line 558 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2256 "y.tab.c"
    break;

  case 97: /* $@18: %empty  */
#line 565 "parser.y"
                                                        { //estaba 'tipo' en vez de prefijo_declaracion, quilombo era
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-1].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-1].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                }
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
                free((yyvsp[-1].nombre));
            }
#line 2282 "y.tab.c"
    break;

  case 98: /* $@19: %empty  */
#line 585 "parser.y"
                                                {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2291 "y.tab.c"
    break;

  case 99: /* funcion_NO_void: prefijo_declaracion ID '(' $@18 declaracion_variables_funcion ')' $@19 '{' instrucciones RETURN expresion ';' '}'  */
#line 588 "parser.y"
                                                         { //debilidad, no puede haber más de 1 return, y encima el bloque de la funcion debe terminar sí o sí con un return
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2302 "y.tab.c"
    break;

  case 100: /* $@20: %empty  */
#line 598 "parser.y"
                                   {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[-1].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-1].nombre));
                        }
                imprimir_indentacion();
                fprintf(yyout_py, "%s(", (yyvsp[-1].nombre));
                free((yyvsp[-1].nombre));
            }
#line 2316 "y.tab.c"
    break;

  case 101: /* $@21: %empty  */
#line 606 "parser.y"
                                         {
                fprintf(yyout_py, ")\n");
            }
#line 2324 "y.tab.c"
    break;

  case 106: /* $@22: %empty  */
#line 616 "parser.y"
                                                       { 
                        // TRUCO: Imprimimos la coma y un espacio justo cuando Bison detecta el token ','
                        fprintf(yyout_py, ", "); 
                   }
#line 2333 "y.tab.c"
    break;

  case 108: /* parametro_llamar_funcion: expresion  */
#line 623 "parser.y"
                                         { 
        fprintf(yyout_py, "%s", (yyvsp[0].nombre)); 
        free((yyvsp[0].nombre)); 
    }
#line 2342 "y.tab.c"
    break;

  case 113: /* arrays: prefijo_declaracion ID '[' volumen_array ']' dimension_array asignacion_array ';'  */
#line 637 "parser.y"
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
#line 2367 "y.tab.c"
    break;

  case 114: /* asignacion_array: '=' inicializador_array  */
#line 659 "parser.y"
                                              {
                        (yyval.nombre) = strdup((yyvsp[0].nombre));
                        free((yyvsp[0].nombre));
                    }
#line 2376 "y.tab.c"
    break;

  case 115: /* asignacion_array: %empty  */
#line 663 "parser.y"
                                   {
                        (yyval.nombre) = NULL;
                    }
#line 2384 "y.tab.c"
    break;

  case 116: /* inicializador_array: '{' lista_inicializadores '}'  */
#line 671 "parser.y"
    {
        // Acá ocurre la magia de la traducción:
        // En C entraron { y }, pero para Python armamos el string con [ y ]
        (yyval.nombre) = malloc(strlen((yyvsp[-1].nombre)) + 3);
        sprintf((yyval.nombre), "[%s]", (yyvsp[-1].nombre));
        free((yyvsp[-1].nombre));
    }
#line 2396 "y.tab.c"
    break;

  case 117: /* lista_inicializadores: valor_o_anidado  */
#line 683 "parser.y"
    {
        (yyval.nombre) = strdup((yyvsp[0].nombre));
        free((yyvsp[0].nombre));
    }
#line 2405 "y.tab.c"
    break;

  case 118: /* lista_inicializadores: lista_inicializadores ',' valor_o_anidado  */
#line 688 "parser.y"
    {
        // Concatenamos lo que ya teníamos con el nuevo valor
        (yyval.nombre) = malloc(strlen((yyvsp[-2].nombre)) + strlen((yyvsp[0].nombre)) + 3);
        sprintf((yyval.nombre), "%s, %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
        free((yyvsp[-2].nombre));
        free((yyvsp[0].nombre));
    }
#line 2417 "y.tab.c"
    break;

  case 119: /* valor_o_anidado: expresion  */
#line 701 "parser.y"
    {
        (yyval.nombre) = strdup((yyvsp[0].nombre));
        free((yyvsp[0].nombre));
    }
#line 2426 "y.tab.c"
    break;

  case 120: /* valor_o_anidado: inicializador_array  */
#line 706 "parser.y"
    {
        (yyval.nombre) = strdup((yyvsp[0].nombre)); 
        free((yyvsp[0].nombre));
        // Ya viene con los corchetes [] armados desde inicializador_array
    }
#line 2436 "y.tab.c"
    break;


#line 2440 "y.tab.c"

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

#line 713 "parser.y"


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
