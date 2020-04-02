/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOT = 258,
     LINE = 259,
     FALSE = 260,
     NONE = 261,
     TRUE = 262,
     LAND = 263,
     BREAK = 264,
     CONTINUE = 265,
     ELIF = 266,
     DEL = 267,
     ELSE = 268,
     FOR = 269,
     IF = 270,
     IN = 271,
     NOT = 272,
     LOR = 273,
     WHILE = 274,
     INPUT = 275,
     PRINT = 276,
     INT = 277,
     FLOAT = 278,
     STR = 279,
     LIST = 280,
     SPLIT = 281,
     MAP = 282,
     APPEND = 283,
     POP = 284,
     INSERT = 285,
     LEN = 286,
     ID = 287,
     CINT = 288,
     CFLOAT = 289,
     SEMI = 290,
     COMMA = 291,
     CSTR = 292,
     EPOP = 293,
     MUL = 294,
     DIV = 295,
     FDIV = 296,
     MOD = 297,
     ADD = 298,
     SUB = 299,
     ASOP = 300,
     G = 301,
     L = 302,
     GE = 303,
     LE = 304,
     EOP = 305,
     NEOP = 306,
     XOR = 307,
     BAND = 308,
     BOR = 309,
     LBRACE = 310,
     RBRACE = 311,
     LPAREN = 312,
     RPAREN = 313,
     LBRACKET = 314,
     RBRACKET = 315,
     RANGE = 316,
     COLON = 317
   };
#endif
/* Tokens.  */
#define DOT 258
#define LINE 259
#define FALSE 260
#define NONE 261
#define TRUE 262
#define LAND 263
#define BREAK 264
#define CONTINUE 265
#define ELIF 266
#define DEL 267
#define ELSE 268
#define FOR 269
#define IF 270
#define IN 271
#define NOT 272
#define LOR 273
#define WHILE 274
#define INPUT 275
#define PRINT 276
#define INT 277
#define FLOAT 278
#define STR 279
#define LIST 280
#define SPLIT 281
#define MAP 282
#define APPEND 283
#define POP 284
#define INSERT 285
#define LEN 286
#define ID 287
#define CINT 288
#define CFLOAT 289
#define SEMI 290
#define COMMA 291
#define CSTR 292
#define EPOP 293
#define MUL 294
#define DIV 295
#define FDIV 296
#define MOD 297
#define ADD 298
#define SUB 299
#define ASOP 300
#define G 301
#define L 302
#define GE 303
#define LE 304
#define EOP 305
#define NEOP 306
#define XOR 307
#define BAND 308
#define BOR 309
#define LBRACE 310
#define RBRACE 311
#define LPAREN 312
#define RPAREN 313
#define LBRACKET 314
#define RBRACKET 315
#define RANGE 316
#define COLON 317




/* Copy the first part of user declarations.  */
#line 1 "python.y"
 
#include<stdio.h> 
#include<stdlib.h> 
#include "y.tab.h"
#include<string.h>


typedef struct Node
{
  struct Node *parent;
  struct Node *sibling;
  struct Node *child;
  char *token;
  int leaf;
}Node;

typedef struct tree
{
  Node *node;
}tree;

typedef struct Quad
{
  char *R;
  char *A1;
  char *A2;
  char *Op;
  
} Quad;

tree *tree_init();
Node* create_node(Node *parent, char *token, int leaf);
void push(Node* node);
void printTree(tree* T);
void print(Node* node);


tree *tree_init()
{
  tree *temp= (tree*)malloc(sizeof(tree));
  temp->node = NULL;
  return(temp);
}

Quad *quad_init()
{
  Quad *temp= (Quad*)malloc(sizeof(Quad));
  temp->R = (char*)malloc(1024);
  temp->A1 = (char*)malloc(1024);
  temp->A2 = (char*)malloc(1024);
  temp->Op = (char*)malloc(1024);
  return(temp);
}


Node* create_node(Node *parent, char *token, int leaf) 
{
  Node *newnode = (Node*)malloc(sizeof(Node));
  newnode->token = (char*)malloc(strlen(token)*sizeof(char));
  strcpy(newnode->token, token);
  newnode->parent = parent;
  newnode->sibling = NULL;
  newnode->child = NULL;
  newnode->leaf=leaf;
  return(newnode);
}

  



void print(Node* node) 
{ 
    if(node == NULL) 
        return; 

    printf("%s ",node->token);
    print(node->child);  
    print(node->sibling); 
}

void printTree(tree* T)
{
  print(T->node);
  printf("\n");
}

void first_val(char *first, char *temp)
{
    int i=0;int n=strlen(first);
    while(i<n && first[i]!=',')
    {
      temp[i]=first[i];i++;
    }
}

void expand(char *str, char *temp)
{
  char *pt;int a=0,b=0,c=0,i=0; char buffer[1024]="";
  pt = strtok(str,",");
  if(pt==NULL)
  {
    if(strlen(str)==0)
    {
    strcat(temp,"");
    return;
    }
  }
  a=atoi(pt);
  pt = strtok(NULL,",");
  if(pt==NULL)
  {
    i=0;
    while(i<a-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }
  b=atoi(pt);
  pt = strtok (NULL,",");
  if(pt==NULL)
  {
    i=a;
    while(i<b-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }  
  c=atoi(pt);
  i=a;
  if(c>0)
  {
  while(i<b-c)
  {
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);strcat(temp,",");
    i+=c;
  }
  sprintf(buffer,"%d",i);
  strcat(temp,buffer);
  return;
  }
  else 
  {

    while(i>b-c)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i+=c;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return; 
  }

}

void len(char *val,char *temp)
{
  int t=strlen(val);
  t=t-t/2;
  sprintf(temp,"%d",t);
}

tree *head = NULL;

void add_child(Node* parent, Node* child)
{
  if(parent==NULL)
    return;
  
  if(parent->child==NULL)
  {
    parent->child = child;
  }
  else
  {
    Node *n = parent->child;
    while(n->sibling!=NULL)
    {
      n=n->sibling;
    }
    n->sibling = child;
  }
  child->parent = parent;
}

void add_sibling(Node* left, Node* new)
{
  if(left==NULL)
  {
    left = new;
    return;
  }
  
  if(left->sibling==NULL)
  {
    left->sibling = new;
  }
  else
  {
    Node *n = left;
    while(n->sibling!=NULL)
    {
      n=n->sibling;
    }
    n->sibling = new;
  }
}

Node* end_node(Node* left)
{
  if(left==NULL)
    return NULL;
  
  if(left->sibling==NULL)
  {
    return left;
  }
  else
  {
    Node *n = left;
    while(n->sibling!=NULL)
    {
      n=n->sibling;
    }
    return n;
  }
}


Quad *allQ = NULL;

int tempno = -1, ln = 0; //temp variable no, label no
int exprno = -1; //expr no



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 250 "python.y"
typedef union YYSTYPE { struct{char value[1024]; int type;struct Node *node;char lhs[1024]  ;char code[1024]}ctype; char val[1024]; } YYSTYPE;
/* Line 196 of yacc.c.  */
#line 460 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 472 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  30
/* YYNRULES -- Number of rules. */
#define YYNRULES  77
/* YYNRULES -- Number of states. */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    18,    22,
      24,    26,    28,    30,    32,    34,    36,    38,    43,    47,
      49,    58,    66,    67,    73,    74,    81,    90,    94,    99,
     101,   103,   105,   107,   109,   111,   113,   115,   119,   121,
     123,   127,   129,   134,   139,   144,   149,   152,   155,   158,
     160,   162,   166,   168,   172,   176,   180,   184,   186,   190,
     194,   196,   200,   204,   208,   210,   214,   218,   222,   226,
     228,   232,   236,   238,   242,   244,   248,   250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      64,     0,    -1,    65,    -1,    66,    65,    -1,    66,    -1,
      68,    35,    -1,    69,    -1,    67,    35,    -1,    32,    45,
      80,    -1,    79,    -1,    71,    -1,    70,    -1,    73,    -1,
      76,    -1,    77,    -1,     9,    -1,    10,    -1,    21,    57,
      72,    58,    -1,    72,    36,    80,    -1,    80,    -1,    15,
      80,    62,    55,    65,    56,    74,    75,    -1,    11,    80,
      62,    55,    65,    56,    74,    -1,    -1,    13,    62,    55,
      65,    56,    -1,    -1,    19,    80,    62,    55,    65,    56,
      -1,    14,    32,    16,    78,    62,    55,    65,    56,    -1,
      59,    72,    60,    -1,    61,    57,    72,    58,    -1,    80,
      -1,    92,    -1,    33,    -1,    34,    -1,    37,    -1,     7,
      -1,     5,    -1,     6,    -1,    20,    57,    58,    -1,    32,
      -1,    81,    -1,    58,    80,    57,    -1,    78,    -1,    31,
      57,    78,    58,    -1,    22,    57,    80,    58,    -1,    23,
      57,    80,    58,    -1,    24,    57,    80,    58,    -1,    44,
      82,    -1,    43,    82,    -1,    17,    82,    -1,    82,    -1,
      83,    -1,    84,    38,    83,    -1,    84,    -1,    85,    39,
      84,    -1,    85,    40,    84,    -1,    85,    41,    84,    -1,
      85,    42,    84,    -1,    85,    -1,    86,    43,    85,    -1,
      86,    44,    85,    -1,    86,    -1,    87,    52,    86,    -1,
      87,    53,    86,    -1,    87,    54,    86,    -1,    87,    -1,
      88,    46,    87,    -1,    88,    48,    87,    -1,    88,    47,
      87,    -1,    88,    49,    87,    -1,    88,    -1,    89,    50,
      88,    -1,    89,    51,    88,    -1,    89,    -1,    89,    16,
      90,    -1,    90,    -1,    90,     8,    91,    -1,    91,    -1,
      91,    18,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   255,   255,   261,   268,   274,   280,   285,   292,   334,
     335,   336,   338,   339,   340,   342,   343,   345,   353,   363,
     371,   387,   400,   402,   411,   413,   425,   445,   453,   465,
     474,   483,   497,   506,   515,   522,   529,   536,   546,   558,
     566,   574,   580,   592,   602,   612,   623,   633,   640,   650,
     658,   663,   674,   681,   689,   697,   705,   714,   721,   734,
     743,   750,   758,   766,   775,   782,   790,   798,   806,   815,
     822,   830,   839,   846,   855,   862,   873,   881
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "LINE", "FALSE", "NONE", "TRUE",
  "LAND", "BREAK", "CONTINUE", "ELIF", "DEL", "ELSE", "FOR", "IF", "IN",
  "NOT", "LOR", "WHILE", "INPUT", "PRINT", "INT", "FLOAT", "STR", "LIST",
  "SPLIT", "MAP", "APPEND", "POP", "INSERT", "LEN", "ID", "CINT", "CFLOAT",
  "SEMI", "COMMA", "CSTR", "EPOP", "MUL", "DIV", "FDIV", "MOD", "ADD",
  "SUB", "ASOP", "G", "L", "GE", "LE", "EOP", "NEOP", "XOR", "BAND", "BOR",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "RANGE",
  "COLON", "$accept", "Start", "Translation_unit", "Stmt",
  "Assignment_stmt", "Simple_stmt", "Compound_stmt", "Jump_stmt",
  "Print_stmt", "Param_list", "If_stmt", "Elif_stmt", "Else_stmt",
  "While_stmt", "For_stmt", "Iterable", "Expression_stmt", "Exp", "Const",
  "Primary_Exp", "Unary_Exp", "Pow_Exp", "Mul_Exp", "Add_Exp", "Bit_Exp",
  "Rel_Exp", "Eq_Exp", "In_Exp", "And_Exp", "Or_Exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    68,
      68,    68,    69,    69,    69,    70,    70,    71,    72,    72,
      73,    74,    74,    75,    75,    76,    77,    78,    78,    79,
      80,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       8,     7,     0,     5,     0,     6,     8,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     1,     4,     4,     4,     4,     2,     2,     2,     1,
       1,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,    35,    36,    34,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    31,    32,    33,
       0,     0,     0,     0,     0,     0,     2,     4,     0,     0,
       6,    11,    10,    12,    13,    14,    41,     9,    29,    39,
      49,    50,    52,    57,    60,    64,    69,    72,    74,    76,
      30,     0,    38,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    46,     0,     0,    19,     0,     1,
       3,     7,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     8,    40,     0,    27,     0,    51,    53,    54,    55,
      56,    58,    59,    61,    62,    63,    65,    67,    66,    68,
      73,    70,    71,    75,    77,     0,     0,     0,    17,    43,
      44,    45,    42,    18,    28,     0,     0,     0,     0,    22,
      25,     0,     0,    24,    26,     0,     0,    20,     0,     0,
       0,     0,     0,     0,    22,    23,    21
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    66,
      33,   143,   147,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const short int yypact[] =
{
       4,   -59,   -59,   -59,   -59,   -59,   -28,    61,   108,    61,
     -49,   -45,   -40,   -25,    -8,    -3,    15,   -59,   -59,   -59,
     108,   108,    61,    61,     7,    69,   -59,     4,    44,    62,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,    78,    17,     2,    54,    24,   -11,    91,    99,
     -59,   102,   -59,    59,   -59,    64,    65,    61,    61,    61,
      61,    21,    61,   -59,   -59,    70,   -30,   -59,    61,   -59,
     -59,   -59,   -59,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    21,    74,    79,   -59,   -29,    75,    80,    85,
      86,   -59,   -59,    61,   -59,   -16,   -59,    78,    78,    78,
      78,    17,    17,     2,     2,     2,    54,    54,    54,    54,
     -59,    24,    24,   -59,   -59,    84,     4,     4,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,    81,    92,    93,     4,   126,
     -59,    94,    61,   134,   -59,    89,    90,   -59,    98,   100,
       4,     4,   101,   103,   126,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -59,   -59,   -26,   -59,   -59,   -59,   -59,   -59,   -59,   -35,
     -59,     6,   -59,   -59,   -59,   -58,   -59,    -7,   -59,    23,
      83,     0,    12,    29,     3,    14,   -59,    67,    68,    71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      53,    70,    55,   100,    51,    87,   103,   103,    56,     1,
       2,     3,    57,     4,     5,    65,    67,    58,     6,     7,
     103,     8,    96,     9,    10,    11,    12,    13,    14,   128,
     104,    54,    59,   105,   125,    15,    16,    17,    18,    88,
      89,    19,   134,    63,    64,    78,    79,    20,    21,    60,
      67,    97,    98,    99,    61,   101,    74,    75,    76,    77,
      62,    67,    22,    23,    68,    24,     1,     2,     3,    69,
      83,    84,    85,    86,   107,   108,   109,   110,     8,    71,
      23,    10,    24,    12,    13,    14,   116,   117,   118,   119,
     111,   112,    15,    52,    17,    18,   133,    72,    19,    90,
     136,   137,   121,   122,    20,    21,    80,    81,    82,   113,
     114,   115,   141,     1,     2,     3,    73,    91,    92,    22,
      23,    93,    24,    95,   152,   153,    94,   102,    10,   126,
      12,    13,    14,   129,   127,   145,   138,   142,   130,    15,
      52,    17,    18,   131,   132,    19,   135,   146,   139,   140,
     144,   148,   149,   150,   120,   151,   106,   154,   123,   155,
     156,     0,   124,     0,     0,     0,    22,    23,     0,    24
};

static const short int yycheck[] =
{
       7,    27,     9,    61,    32,    16,    36,    36,    57,     5,
       6,     7,    57,     9,    10,    22,    23,    57,    14,    15,
      36,    17,    57,    19,    20,    21,    22,    23,    24,    58,
      60,     8,    57,    68,    92,    31,    32,    33,    34,    50,
      51,    37,    58,    20,    21,    43,    44,    43,    44,    57,
      57,    58,    59,    60,    57,    62,    39,    40,    41,    42,
      45,    68,    58,    59,    57,    61,     5,     6,     7,     0,
      46,    47,    48,    49,    74,    75,    76,    77,    17,    35,
      59,    20,    61,    22,    23,    24,    83,    84,    85,    86,
      78,    79,    31,    32,    33,    34,   103,    35,    37,     8,
     126,   127,    88,    89,    43,    44,    52,    53,    54,    80,
      81,    82,   138,     5,     6,     7,    38,    18,    16,    58,
      59,    62,    61,    58,   150,   151,    62,    57,    20,    55,
      22,    23,    24,    58,    55,   142,    55,    11,    58,    31,
      32,    33,    34,    58,    58,    37,    62,    13,    56,    56,
      56,    62,    62,    55,    87,    55,    73,    56,    90,    56,
     154,    -1,    91,    -1,    -1,    -1,    58,    59,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,     6,     7,     9,    10,    14,    15,    17,    19,
      20,    21,    22,    23,    24,    31,    32,    33,    34,    37,
      43,    44,    58,    59,    61,    64,    65,    66,    67,    68,
      69,    70,    71,    73,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    32,    32,    80,    82,    80,    57,    57,    57,    57,
      57,    57,    45,    82,    82,    80,    72,    80,    57,     0,
      65,    35,    35,    38,    39,    40,    41,    42,    43,    44,
      52,    53,    54,    46,    47,    48,    49,    16,    50,    51,
       8,    18,    16,    62,    62,    58,    72,    80,    80,    80,
      78,    80,    57,    36,    60,    72,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      90,    88,    88,    91,    92,    78,    55,    55,    58,    58,
      58,    58,    58,    80,    58,    62,    65,    65,    55,    56,
      56,    65,    11,    74,    56,    80,    13,    75,    62,    62,
      55,    55,    65,    65,    56,    56,    74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 256 "python.y"
    {
  add_child(head->node,create_node(NULL,"Translation_unit",0));
  add_child(head->node->child,(yyvsp[0].ctype).node);
}
    break;

  case 3:
#line 262 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Stmt",0);
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 4:
#line 269 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Stmt",0);
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 5:
#line 275 "python.y"
    {
  (yyval.ctype).node=create_node(NULL,"Simple_stmt",0);
  add_child((yyval.ctype).node,(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,";",0));
}
    break;

  case 6:
#line 281 "python.y"
    {
  (yyval.ctype).node=create_node(NULL,"Compound_stmt",0);
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);
}
    break;

  case 7:
#line 286 "python.y"
    {
  (yyval.ctype).node=create_node(NULL,"Assignment_stmt",0);
  add_child((yyval.ctype).node,(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,";",0));
}
    break;

  case 8:
#line 293 "python.y"
    {
  char buff[3]="";
  sprintf(buff,"%d",(yyvsp[0].ctype).type);
  insert("ID",(yyvsp[-2].ctype).value,buff,(yyvsp[0].ctype).value,-1);
  (yyval.ctype).node=create_node(NULL,"ID",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyvsp[-2].ctype).value,0));
  add_sibling((yyval.ctype).node,create_node(NULL,"=",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);



  if (exprno==0)
  {
    printf("op \t\t arg1 \t\t arg2 \t\t res \n");
    printf("-----------------------------------------------------\n");
    printf("= \t\t %s \t\t   \t\t%s\n",(yyvsp[0].ctype).code,(yyvsp[-2].ctype).value);

    sprintf((yyval.ctype).code,"%s = %s",(yyvsp[-2].ctype).value,(yyvsp[0].ctype).code);
    printf("0code is %s",(yyval.ctype).code);
  }
  else if(exprno==1)
  {

  printf("op \t\t arg1 \t\t arg2 \t\t res \n");
  printf("-----------------------------------------------------\n");
  
  // temporarily printing here, will insert into quad later

  printf("= \t\t t%d \t\t   \t\t%s\n",tempno,(yyvsp[-2].ctype).value);
  sprintf((yyval.ctype).code,"%s",(yyvsp[0].ctype).code);
  printf("1code is %s\n",(yyval.ctype).code);

  }

 




}
    break;

  case 9:
#line 334 "python.y"
    {(yyval.ctype).node=create_node(NULL,"Expression_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 10:
#line 335 "python.y"
    {(yyval.ctype).node=create_node(NULL,"Print_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 11:
#line 336 "python.y"
    {(yyval.ctype).node=create_node(NULL,"Jump_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 12:
#line 338 "python.y"
    {(yyval.ctype).node=create_node(NULL,"If_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 13:
#line 339 "python.y"
    {(yyval.ctype).node=create_node(NULL,"While_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 14:
#line 340 "python.y"
    {(yyval.ctype).node=create_node(NULL,"For_stmt",0);add_child((yyval.ctype).node,(yyvsp[0].ctype).node);}
    break;

  case 15:
#line 342 "python.y"
    {(yyval.ctype).node=create_node(NULL,"BREAK",0);}
    break;

  case 16:
#line 343 "python.y"
    {(yyval.ctype).node=create_node(NULL,"CONTINUE",0);}
    break;

  case 17:
#line 346 "python.y"
    {
  (yyval.ctype).node=create_node(NULL,"PRINT",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 18:
#line 354 "python.y"
    {
  (yyval.ctype).type=50+(yyvsp[-2].ctype).type;strcat((yyval.ctype).value,",");
  strcat((yyval.ctype).value,(yyvsp[0].ctype).value);
  (yyval.ctype).node = create_node(NULL,"Param_list",0);
  add_child(end_node((yyval.ctype).node),(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,",",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 19:
#line 364 "python.y"
    {  
  (yyval.ctype).node = create_node(NULL,"EXP",0);
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);


}
    break;

  case 20:
#line 372 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"IF",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-6].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,":",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"{",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-3].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"}",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Elif_stmt",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"Else_stmt",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 21:
#line 388 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"ELIF",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-5].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,":",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"{",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"}",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Elif_stmt",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 22:
#line 400 "python.y"
    {}
    break;

  case 23:
#line 403 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"ELSE",0);
  add_sibling((yyval.ctype).node,create_node(NULL,":",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"{",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"}",0));
}
    break;

  case 24:
#line 411 "python.y"
    {}
    break;

  case 25:
#line 414 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"WHILE",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-4].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,":",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"{",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"}",0));
}
    break;

  case 26:
#line 426 "python.y"
    {
  char temp[1024]="";
  first_val((yyvsp[-4].ctype).value,temp);
  char buff[3]="";
  sprintf(buff,"%d",(yyvsp[-4].ctype).type%10);
  insert("ID",(yyvsp[-6].ctype).value,buff,temp,-1);
  (yyval.ctype).node = create_node(NULL,"FOR",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"ID",0));
  add_child(end_node((yyval.ctype).node),create_node(NULL,(yyvsp[-6].ctype).value,0));
  add_sibling((yyval.ctype).node,create_node(NULL,"in",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Iterable",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-4].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,":",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"{",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Translation_unit",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"}",0));
}
    break;

  case 27:
#line 446 "python.y"
    {
  (yyval.ctype)=(yyvsp[-1].ctype);
  (yyval.ctype).node = create_node(NULL,"[",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"Param_list",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"]",0));
}
    break;

  case 28:
#line 454 "python.y"
    {
  (yyval.ctype).type=51;
  char temp[1024]="";
  expand((yyvsp[-1].ctype).value,temp);strcpy((yyval.ctype).value,temp);
  (yyval.ctype).node = create_node(NULL,"RANGE",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Param_list",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 29:
#line 466 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Exp",0);
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);


}
    break;

  case 30:
#line 475 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Or_Exp",0);
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);

  
}
    break;

  case 31:
#line 484 "python.y"
    {
  (yyval.ctype).type=1;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"CINT",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));

  printf("in const cint %s\n",(yyvsp[0].val));
  strcpy((yyval.ctype).code,(yyvsp[0].val));
  sprintf((yyval.ctype).lhs,"%s",(yyvsp[0].val));
  exprno=0;

  tempno++;
}
    break;

  case 32:
#line 498 "python.y"
    {
  (yyval.ctype).type=2;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"CFLOAT",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));

  strcpy((yyval.ctype).code,(yyvsp[0].val));
}
    break;

  case 33:
#line 507 "python.y"
    {
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"CSTR",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));

  strcpy((yyval.ctype).code,(yyvsp[0].val));
}
    break;

  case 34:
#line 516 "python.y"
    {
  (yyval.ctype).type=4;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"TRUE",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));
}
    break;

  case 35:
#line 523 "python.y"
    {
  (yyval.ctype).type=4;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"FALSE",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));
}
    break;

  case 36:
#line 530 "python.y"
    {
  (yyval.ctype).type=5;
  strcpy((yyval.ctype).value,(yyvsp[0].val));
  (yyval.ctype).node = create_node(NULL,"NONE",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));
}
    break;

  case 37:
#line 537 "python.y"
    {
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,"");
  (yyval.ctype).node = create_node(NULL,"INPUT",0);
  add_child((yyval.ctype).node,create_node(NULL,(yyval.ctype).value,0));
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 38:
#line 547 "python.y"
    {
  strcpy((yyval.ctype).code,(yyvsp[0].ctype).value);
  printf("in id %s\n",(yyvsp[0].ctype).value);
  //$$=$1; 
  //$$.node = create_node(NULL,"ID",0); 
  //add_child($$.node,create_node(NULL,$1.value,0));




}
    break;

  case 39:
#line 559 "python.y"
    {
  (yyval.ctype)=(yyvsp[0].ctype);  
  (yyval.ctype).node = create_node(NULL,"Const",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  
}
    break;

  case 40:
#line 567 "python.y"
    {
  (yyval.ctype)=(yyvsp[-1].ctype);
  (yyval.ctype).node = create_node(NULL,"(",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),create_node(NULL,(yyvsp[-1].ctype).node,0));
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 41:
#line 575 "python.y"
    {
  (yyval.ctype)=(yyvsp[0].ctype);
  (yyval.ctype).node = create_node(NULL,"Iterable",0);
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);
}
    break;

  case 42:
#line 581 "python.y"
    {
  (yyval.ctype).type=1;
  char buffer[10]="";
  len((yyvsp[-1].ctype).value,buffer) ;
  strcpy((yyval.ctype).value,buffer);
  (yyval.ctype).node = create_node(NULL,"LEN",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Iterable",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[-1].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 43:
#line 593 "python.y"
    {
  (yyval.ctype).type=1;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  (yyval.ctype).node = create_node(NULL,"INT",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),create_node(NULL,(yyvsp[-1].ctype).node,0));
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 44:
#line 603 "python.y"
    {
  (yyval.ctype).type=2;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  (yyval.ctype).node = create_node(NULL,"FLOAT",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),create_node(NULL,(yyvsp[-1].ctype).node,0));
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 45:
#line 613 "python.y"
    {
  (yyval.ctype).type=3;
  strcpy((yyval.ctype).value,(yyvsp[-1].ctype).value);
  (yyval.ctype).node = create_node(NULL,"STR",0);
  add_sibling((yyval.ctype).node,create_node(NULL,"(",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"EXP",0));
  add_child(end_node((yyval.ctype).node),create_node(NULL,(yyvsp[-1].ctype).node,0));
  add_sibling((yyval.ctype).node,create_node(NULL,")",0));
}
    break;

  case 46:
#line 624 "python.y"
    {
  (yyval.ctype).type=(yyvsp[0].ctype).type;
  char buffer[1024]="-";
  strcat(buffer,(yyvsp[0].ctype).value);
  strcpy((yyval.ctype).value,buffer);
  (yyval.ctype).node = create_node(NULL,"-",0); 
  add_sibling((yyval.ctype).node,create_node(NULL,"Primary_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 47:
#line 634 "python.y"
    {
  (yyval.ctype)=(yyvsp[0].ctype);
  (yyval.ctype).node = create_node(NULL,"+",0); 
  add_sibling((yyval.ctype).node,create_node(NULL,"Primary_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 48:
#line 641 "python.y"
    {
  (yyval.ctype).type=(yyvsp[0].ctype).type;
  char buffer[1024]="-";
  strcat(buffer,(yyvsp[0].ctype).value);
  strcpy((yyval.ctype).value,buffer);
  (yyval.ctype).node = create_node(NULL,"!",0); 
  add_sibling((yyval.ctype).node,create_node(NULL,"Primary_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyval.ctype).node);
}
    break;

  case 49:
#line 651 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Primary_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 50:
#line 659 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Unary_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);
}
    break;

  case 51:
#line 664 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Pow_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"**",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Unary_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[-2].ctype).code);
}
    break;

  case 52:
#line 675 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Pow_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 53:
#line 682 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Mul_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"*",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Pow_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 54:
#line 690 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Mul_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"/",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Pow_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 55:
#line 698 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Mul_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"//",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Pow_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 56:
#line 706 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Mul_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"%",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Pow_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 57:
#line 715 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Mul_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 58:
#line 722 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Add_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"+",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Mul_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
  sprintf((yyval.ctype).lhs,"t%d",tempno);
  sprintf((yyval.ctype).code,"t%d = %s + %s",tempno,(yyvsp[-2].ctype).lhs,(yyvsp[0].ctype).code);
  printf("\n in add_exp add mul_exp, code is %s\n",(yyval.ctype).code);

  exprno=1;
}
    break;

  case 59:
#line 735 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Add_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"-",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Mul_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 60:
#line 744 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Add_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 61:
#line 751 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Bit_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"^",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Add_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 62:
#line 759 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Bit_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"&",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Add_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 63:
#line 767 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Bit_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"|",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Add_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 64:
#line 776 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Bit_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 65:
#line 783 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Rel_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,">",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Bit_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 66:
#line 791 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Rel_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,">=",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Bit_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 67:
#line 799 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Rel_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"<",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Bit_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 68:
#line 807 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Rel_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"<=",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Bit_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 69:
#line 816 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Rel_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 70:
#line 823 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Eq_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"==",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Rel_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 71:
#line 831 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Eq_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"!=",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Rel_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 72:
#line 840 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Eq_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 73:
#line 847 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"Eq_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"in",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"In_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;

  case 74:
#line 856 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"In_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 75:
#line 863 "python.y"
    {
  (yyval.ctype).node = create_node(NULL,"In_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"and",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"And_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);


}
    break;

  case 76:
#line 874 "python.y"
    {
  (yyval.ctype)=(yyvsp[0].ctype);  
  (yyval.ctype).node = create_node(NULL,"And_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[0].ctype).node);

  strcpy((yyval.ctype).code,(yyvsp[0].ctype).code);
}
    break;

  case 77:
#line 882 "python.y"
    {
  (yyval.ctype)=(yyvsp[-2].ctype);  
  (yyval.ctype).node = create_node(NULL,"And_Exp",0); 
  add_child((yyval.ctype).node,(yyvsp[-2].ctype).node);
  add_sibling((yyval.ctype).node,create_node(NULL,"or",0));
  add_sibling((yyval.ctype).node,create_node(NULL,"Or_Exp",0));
  add_child(end_node((yyval.ctype).node),(yyvsp[0].ctype).node);
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2448 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 892 "python.y"
 
int yyerror(char *msg) 
{ 
  printf("Syntax Error\n"); 
  return 1;
} 
 
int main() 
{ 
  head = tree_init();
  head->node = create_node(NULL,"Start",0);
  yyparse(); 
  display_symbol();
  printf("\n\nAbstract Syntax Tree\n\n");
  printTree(head);
  return 1;
}


