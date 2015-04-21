%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

  program    : PROGRAM IDENTIFIER LPAREN IDENTIFIER RPAREN SEMICOLON prebegin statement DOT { parseresult = makeprogram($2, $4, $8); }
             ;

  prebegin   : variables                       { $$ = NULL;  }
             | constants prebegin              { $$ = NULL;  }
             | labels prebegin                 { $$ = NULL;  }
             | types prebegin                  { $$ = NULL;  }
             ;

  labels     : LABEL label                     { $$ = NULL; }
             ;

  label      : labelinst COMMA label           { $$ = NULL; }
             | labelinst SEMICOLON             { $$ = NULL; }
             ;

  labelinst  : NUMBER                          { $$ = NULL; dbugprinttok($1);  }

  types      : TYPE typelist                   { $$ = NULL; }
             ;

  typelist   : typeItem SEMICOLON typelist     { $$ = NULL; }
             | typeItem SEMICOLON              { $$ = NULL; }
             ;

  typeItem   : IDENTIFIER EQ type              { insttype($1, $3); printf("TYPE ITEM WORKED\n"); }
             ;

  type       : RECORD recordSet END            { $$ = instrec($1, $2); printf("TYPE : RECORDSET\n"); }
             | LPAREN idlist RPAREN            { $$ = instenum($2); printf("ENUM\n"); } // instenum($2)
             | POINT IDENTIFIER                { $$ = instpoint($1, $2); }
             ;

  idlist    : IDENTIFIER COMMA idlist                 { $$ = cons($1, $3); }
            | IDENTIFIER                              { $$ = $1; }
            ;

  recordSet  : recordLine                      { $$ = $1; printf("ONE CASE RECORD WORKING\n"); } 
             | recordLine SEMICOLON recordSet  { $$ = cons($1, $3); }
             ;

  recordLine : recordNames COLON recordType    { instfields($1, findtype($3));}      
             ;
  recordNames: IDENTIFIER COMMA recordNames    { $$ = cons($1, $3); }   
             | IDENTIFIER                      {  $$ = ($1); }
             ;
  recordType : IDENTIFIER                      {  $$ = ($1);  }
             ;

  constants  : CONST constant                  { $$ = NULL; }
             ;
  constant   : constinst SEMICOLON constant    { $$ = NULL; }
             | constinst SEMICOLON             { $$ = NULL; }
             ;

  constinst  : IDENTIFIER EQ NUMBER            { instconst($1, $3);}
             ;
  equalsNum  : IDENTIFIER EQ NUMBER            { $$ = binop($2, $1, $3);  }
             ;
  variables  : VAR varSet                      { $$ = NULL; }
             ;

  varSet     : varLine SEMICOLON               { $$ = NULL; } 
             | varLine SEMICOLON varSet        { $$ = NULL; }
             ;

  varLine    : varNames COLON varType          { instvars($1, findtype($3)); }
             | varNames COLON ARRAY LBRACKET btwbrackets RBRACKET OF IDENTIFIER
                                               { instvars($1, instarray($5, findtype($8))); printf("ARRAY WORKS\n"); }
             ;
  btwbrackets: NUMBER DOTDOT NUMBER COMMA IDENTIFIER 
                                               { $$ = cons(findtype($5), instdotdot($1, $2, $3)); }
             | NUMBER DOTDOT NUMBER            { $$ = instdotdot($1, $2, $3); }
             ;
  varNames   : IDENTIFIER COMMA varNames       { $$ = cons($1, $3); }
             | IDENTIFIER                      { $$ = ($1); }
             ;
  varType    : IDENTIFIER                      { $$ = $1; }
             ;

  var       : IDENTIFIER                              { $$ = findid($1); }
            | var DOT IDENTIFIER                      { $$ = reducedot($1, $2, $3); } //
            // | mergebracks
            | var POINT                               { $$ = dopoint($1, $2); } // 
            ;

  statement  :  BEGINBEGIN statement endpart   {  $$ = makeprogn($1,nconc($2, $3));  }
             |  stateLine SEMICOLON statement  {  $$ = cons($1, $3); }
             |  stateLine                      {  $$ = $1;  }
             ;

  stateLine  :  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  forLoop                        { $$ = $1;  }
             |  funcCall                       { $$ = $1; }
             |  assignment                     { $$ = $1;  }
             |  repeatuntil                    { $$ = $1; }
             |  NUMBER COLON statement         { $$ = dolabel($1, $2, $3); }
             ;
  repeatuntil:  REPEAT statement UNTIL equalsNum { $$ = makerepeat((TOKEN) talloc(), $2, (TOKEN) talloc(), $4); }
             ;

  funcCall   : IDENTIFIER LPAREN expr RPAREN   { $$ = makefuncall((TOKEN) talloc(), findid($1), $3); }
             ; 
  forLoop    :  FOR assignment TO IDENTIFIER DO statement { $$ = makefor(1, (TOKEN) talloc(), $2, findid($4), NULL, NULL, $6); }
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;
  assignment :  factor ASSIGN expr         { $$ = binop($2, $1, $3); }
             ;

  expr       :  MINUS term                     { $$ = unaryop($1, $2); }
             |  expr MINUS term                { $$ = binop($2, $1, $3); }
             |  expr PLUS term                 { $$ = binop($2, $1, $3); }
             |  term                           { $$ = $1; }
             ;
  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  factor                         { $$ = $1; }
             ;

  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             | var                             { $$ = $1; }
             |  NUMBER                         { $$ = $1; }                          
             |  STRING                         { $$ = $1; }
             |  funcCall                       { $$ = $1; }           
             ;

  // printDebug : IDENTIFIER   {printf("%s\n", yylval->stringval);}
  //            ;
%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG          1             /* set bits here for debugging, 0 = off  */
#define DB_CONS        1             /* bit to trace cons */
#define DB_NCONC       1             /* bit to trace nconc */
#define DB_COPYTOK     1             /* bit to trace copytok */
#define DB_BINOP       1             /* bit to trace binop */
#define DB_MAKEFOR     1             /* bit to trace makefor */
#define DB_MAKEFUNCALL 1             /* bit to trace makefuncall */
#define DB_MAKEGOTO    1             /* bit to trace makegoto */
#define DB_MAKEIF      1             /* bit to trace makeif */
#define DB_MAKEINTC    1             /* bit to trace makeintc */
#define DB_MAKELABEL   1             /* bit to trace makelabel */
#define DB_MAKEOP      1             /* bit to trace makeop */
#define DB_MAKEPROGN   1             /* bit to trace makeprogn */
#define DB_MAKEPROGRAM 1             /* bit to trace makeprogram */
#define DB_PARSERES    1             /* bit to trace parseresult */
#define DB_UNARYOP     1             /* bit to trace unaryop */
#define DB_MAKEREPEAT  1             /* bit to trace makerepeat */
#define DB_INSTVARS    1             /* bit to trace makerepeat */
#define DB_INSTTYPE    1             /* bit to trace makerepeat */
#define DB_INSTREC     1            
#define DB_INSTFIELDS  1            
#define DB_MAKESUBRNG  1
#define DB_INSTPOINT   1
#define DB_INSTARRAY   1
#define DB_INSTDOTDOT  1
#define DB_INSTARRAY   1
#define DB_DOPOINT     1
#define DB_REDUCEDOT   1
#define DB_MAKEAREF    1
#define DB_DOLABEL    1



 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labels[100];
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb) 
    { 
      TOKEN current = lista;
      while(current->link != NULL) {
        current = current->link;
      }
      current->link = listb;
    if (DEBUG & DB_NCONC)
       { printf("nconc\n");
         dbugprinttok(lista);
         dbugprinttok(listb);
       };
    return lista;
  }


/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
    op->operands = lhs;          /* link operands to operator       */
    lhs->link = NULL;
    if (DEBUG & DB_UNARYOP)
       { printf("unaryop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
       };
    return op;
}

int isReal(TOKEN tok) {
  // printf("IS REAL: \n");
  SYMBOL sym = searchst(tok->stringval);
  // dbugprinttok(tok);
  if (sym->basicdt == REAL) {
    // printf("TRUE\n");
    return 1;
  }
    // printf("FALSE\n");

  return 0;
}

int isInteger(TOKEN tok) {
  // printf("IS INTEGER: \n");
  // dbugprinttok(tok);
  SYMBOL sym = searchst(tok->stringval);
  if (sym->basicdt == INTEGER) {
    // printf("TRUE\n");
    return 1;
  }
    // printf("FALSE\n");
    return 0;
}

int isIdentifier(TOKEN tok) {
  if (tok->tokentype == IDENTIFIERTOK) {
    return 1;
  }
  return 0;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    
    if (isIdentifier(lhs)) {
      if (isIdentifier(rhs)) {
        if (isReal(lhs) && isReal(rhs)) {
          op->datatype = REAL;
        } else if (isReal(lhs) && isInteger(rhs)) {
          op->datatype = REAL;
          TOKEN float_tok = makeop(FLOATOP);
          float_tok->operands = rhs;
          lhs->link = float_tok;
        } else if (isInteger(lhs) && isReal(rhs)) {
          if (op->whichval == ASSIGNOP) {
            TOKEN fix_tok = makeop(FIXOP);
            fix_tok->operands =rhs;
            lhs->link = fix_tok;
          }
          else {
            op->datatype = REAL;
            TOKEN float_tok = makeop(FLOATOP);
            float_tok->operands = lhs;
            float_tok->link = rhs;            
          }

        }
      }
      else {
        if (isReal(lhs) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
        } else if (isReal(lhs) && (rhs->datatype == INTEGER)) {
          op->datatype = REAL;
          rhs->datatype = REAL;
          rhs->realval = (double) rhs->intval;
        } else if (isInteger(lhs) && (rhs->datatype == REAL)) {
          if (op->whichval == ASSIGNOP) {
            if (rhs->tokentype == OPERATOR || rhs->tokentype == IDENTIFIERTOK) {
              TOKEN fix_tok = makeop(FIXOP);
              fix_tok->operands =rhs;
              lhs->link = fix_tok;           
            } else if (rhs->tokentype == NUMBERTOK) {
              rhs->datatype = INTEGER;
              rhs->intval = (int) rhs->realval;
            }

          }else {
            op->datatype = REAL;
            TOKEN float_tok = makeop(FLOATOP);
            float_tok->operands = lhs;
            float_tok->link = rhs;
          }

        }
      }
    }
    else {
      if (isIdentifier(rhs)) {
        if ((lhs->datatype == REAL) && isReal(rhs)) {
          op->datatype = REAL;
        } else if ((lhs->datatype == REAL) && isInteger(rhs)) {
          op->datatype = REAL;
          TOKEN float_tok = makeop(FLOATOP);
          float_tok->operands = rhs;
          lhs->link = float_tok;
        } else if ((lhs->datatype == INTEGER) && isReal(rhs)) {
          op->datatype = REAL;
          lhs->datatype = REAL;
          lhs->realval = (double) lhs->intval;
        }
      }
      else {
        if ((lhs->datatype == REAL) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
        } else if ((lhs->datatype == REAL) && (rhs->datatype == INTEGER)) {
          op->datatype = REAL;
          rhs->datatype = REAL;
          rhs->realval = (double) rhs->intval;
        } else if ((lhs->datatype == INTEGER) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
          lhs->datatype = REAL;
          lhs->realval = (double) lhs->intval;
        }        
      }
    }

    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
  int num_to_go_to = labelnumber;
  TOKEN labeltok = makelabel();
  tok = makeprogn(tok, labeltok);

  TOKEN progn_statements = makeprogn(tokb, statements);
  labeltok->link = progn_statements;
  TOKEN go_to_tok = makegoto(num_to_go_to);
  TOKEN empty_progn = makeprogn((TOKEN) talloc(), NULL);
  empty_progn->link = go_to_tok;

  TOKEN if_token = talloc();
  if_token = makeif(if_token, expr, empty_progn, go_to_tok);
  progn_statements->link = if_token;
 if (DEBUG & DB_MAKEREPEAT)
    { printf("makerepeat\n");
      dbugprinttok(tok);
      dbugprinttok(labeltok);
      dbugprinttok(progn_statements);
      dbugprinttok(if_token);
      dbugprinttok(expr);
      dbugprinttok(empty_progn);
      dbugprinttok(go_to_tok);
    };
 return tok;  
}

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {
  TOKEN copy = talloc();
  copy->tokentype = origtok->tokentype;
  copy->datatype = origtok->datatype;
  copy->symtype = origtok->symtype;
  copy->symentry = origtok->symentry;
  copy->link = origtok->link;
  copy->whichval = origtok->whichval;
  copy->intval = origtok->intval;
  copy->realval = origtok->realval;
  if (DEBUG & DB_COPYTOK) {
    printf("copytok\n");
    dbugprinttok(copy);
  }
  return copy;
}

/* makeintc makes a new token with num as its value */
TOKEN makeintc(int num) {
  TOKEN intMade = talloc();
  intMade->tokentype = NUMBERTOK;
  intMade->datatype = INTEGER;
  intMade->intval = num;
  if (DEBUG & DB_MAKEINTC) {
    dbugprinttok(intMade);
  }
  return intMade;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
  TOKEN program = talloc();
  TOKEN nameToArgs = talloc();
  program->tokentype = OPERATOR;
  program->whichval = PROGRAMOP;
  program->operands = name;
  // args->tokentype = IDENTIFIER;
  // name->tokentype = IDENTIFIER;
  nameToArgs = makeprogn(nameToArgs, args);
  name->link = nameToArgs;
  nameToArgs->link = statements;
  if (DEBUG & DB_MAKEPROGRAM)
  { printf("makeprogram\n");
    dbugprinttok(program);
    dbugprinttok(name);
    dbugprinttok(nameToArgs);
    dbugprinttok(args);
  };
  return program;
}

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args){
  tok->operands = fn;
  tok->whichval = FUNCALLOP;
  tok->datatype = fn->datatype;
  fn->link = args;
  if (DEBUG & DB_MAKEPROGN)
  { printf("makefuncall\n");
    dbugprinttok(tok);
    dbugprinttok(fn);
    dbugprinttok(args);
  };
  return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement) {
  tok = makeprogn(tok, asg);
  tok->operands = asg;
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN compare_op;
  TOKEN inc_or_dec_op;
  // Increment for loop
  if (sign == 1) {
    compare_op = makeop(LEOP);
    inc_or_dec_op = makeop(PLUSOP);
  }
  // Decrementing For Loop
  else if (sign == -1) {
    compare_op = makeop(GEOP);
    inc_or_dec_op = makeop(MINUSOP);
  }

  TOKEN ifStatement =  talloc();
  TOKEN statementProgn = talloc();
  statementProgn = makeprogn(statementProgn, statement);

  ifStatement = makeif(ifStatement, compare_op, statementProgn, NULL);
  TOKEN varA = copytok(asg->operands);

  ifStatement->operands = compare_op;
  compare_op->operands = varA;
  varA->link = tokb;
  
  TOKEN assign = makeop(ASSIGNOP);
  TOKEN secondVarA = copytok(varA);
  assign->operands = secondVarA;
  secondVarA->link = inc_or_dec_op;
  TOKEN thirdVarA = copytok(varA);
  inc_or_dec_op->operands = thirdVarA;
  thirdVarA->link = makeintc(1);

  statement->link = assign;
  assign->link = makegoto(labelnumber - 1);
  label->link = ifStatement;

  if (DEBUG & DB_MAKEFOR) {
    printf("makefor\n");
    dbugprinttok(tok);
    dbugprinttok(asg);
    dbugprinttok(tokb);
    dbugprinttok(endexpr);
    dbugprinttok(tokc);
    dbugprinttok(compare_op);
    dbugprinttok(inc_or_dec_op);
    dbugprinttok(varA);
    dbugprinttok(secondVarA);
    dbugprinttok(thirdVarA);
  }
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label) {
  TOKEN gotoTok = talloc();
  gotoTok->tokentype = OPERATOR;
  gotoTok->whichval = GOTOOP;
  gotoTok->operands = makeintc(labelnumber - 1);
  if (DEBUG & DB_MAKEGOTO) {
    printf("makegoto\n");
    dbugprinttok(gotoTok);
  }
  return gotoTok;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {
  TOKEN newLabel = talloc();
  newLabel->tokentype = OPERATOR;
  newLabel->whichval = LABELOP;
  newLabel->operands = makeintc(labelnumber);
  labelnumber++;
  if (DEBUG & DB_MAKELABEL) {
    printf("makelabel\n");
    dbugprinttok(newLabel);
  }
  return newLabel;
}

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum){
  TOKEN makeopTok = talloc();
  makeopTok->tokentype = OPERATOR;
  makeopTok->whichval = opnum;
  if (DEBUG & DB_MAKEOP) {
    printf("makeop\n");
    dbugprinttok(makeopTok);
  }
  return makeopTok;


}
/* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok) { /* the ID token */
  SYMBOL sym, typ;

  sym = searchst(tok->stringval);
  tok->symentry = sym;
  typ = sym->datatype;
  tok->symtype = typ;
  tok->datatype = typ->basicdt;

  if (sym->kind == CONSTSYM)
  {
    if (sym->basicdt == REAL) {
      tok->tokentype = NUMBERTOK;
      tok->datatype = REAL;
      tok->realval = sym->constval.realnum;
    }
    else if (sym->basicdt == INTEGER) {
      tok->tokentype = NUMBERTOK;
      tok->datatype = INTEGER;
      tok->intval = sym->constval.intnum;
    }
  }
  return tok;

}

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
  tok->symtype = searchst(tok->stringval);
  
  // if(sym->basicdt == INTEGER) {
  //   printf("FOUND TYPE TO BE INTEGER\n");
  //   tok->symtype = searchst("integer");
  // }
  // else if(type == REAL) {
  //   printf("FOUND TYPE TO BE REAL\n");
  //   tok->symtype = searchst("real");
  // }
  // else if(type == BOOLETYPE) {
  //   printf("FOUND TYPE TO BE BOOLEAN\n");
  //   tok->symtype = searchst("boolean");
  // }
  // else{
  //   printf("FOUND TYPE TO BE STRING\n");
  //   tok->symtype = searchst(tok->stringval);
  // }
  // printf("FIND TYPE\n");
  // dbugprinttok(tok);
  return tok;
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok){
  TOKEN output = makesubrange(dottok, lowtok->intval, hightok->intval);
  if (DEBUG && DB_INSTDOTDOT) {
    printf("instdotdot\n");
    dbugprinttok(lowtok);
    dbugprinttok(dottok);
    dbugprinttok(hightok);
  }

  return output;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {
  // bounds->symtype->[low/highbound]

  TOKEN curr_bound = bounds;
  SYMBOL prev_sym = NULL;

  SYMBOL typesym = searchst(typetok->stringval);
  int low, high;

  while (curr_bound) {
    SYMBOL arrsym = symalloc();
    arrsym->kind = ARRAYSYM;

    if (typesym) {
      arrsym->datatype = typesym;
    }
//     else {
// //      arrsym->basicdt = typetok->datatype;
//     }

    low = curr_bound->symtype->lowbound;
    high = curr_bound->symtype->highbound;

    if (!prev_sym) {
      arrsym->size = (high - low + 1) * typesym->size;
      printf("CURRENT_SIZE %d\n", arrsym->size);
      printf("CURRENT SIZE %d\n", high-low+1);

    }
    else {
      arrsym->datatype = typetok->symtype;
      printf("ARRAY SYM SIZE %d\n", arrsym->size);

      arrsym->size = (high - low + 1) * prev_sym->size;
      printf("PREVIOUS SIZE %d\n", prev_sym->size);
      printf("CURRENT SIZE %d\n", high-low+1);
      dbugprinttok(curr_bound);
      printf("TYPESYM SIZE %d\n", typesym->size);
    }

    typetok->symtype = arrsym;
    prev_sym = arrsym;

    arrsym->lowbound = low;
    arrsym->highbound = high;

    curr_bound = curr_bound->link;
  }

  if (DEBUG && DB_INSTARRAY) {
    printf("instdotdot\n");
    dbugprinttok(bounds);
    dbugprinttok(typetok);
  } 
  return typetok;

}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {

  int next = 0;
  int offset = 0;

  SYMBOL recsym, typesym;

  TOKEN temp = idlist;

  while (temp) {
    typesym = searchst(typetok->stringval);
    recsym = makesym(temp->stringval);
    recsym->datatype = typesym;

    // offset = next; next = next + n;
    offset = next;
    next = next + typesym->size;

    recsym->offset = offset;
    recsym->size = typesym->size;
    recsym->datatype = typesym;

    if (typesym->kind == BASICTYPE) {
      recsym->basicdt = typesym->basicdt;
    }

    temp->symtype = recsym;

    temp = temp->link;
  }

  if (DEBUG && DB_INSTFIELDS) {
    printf("instfields\n");
    dbugprinttok(idlist);
    dbugprinttok(typetok);
    dbugprinttok(temp);
  }
  return idlist;
}


/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  int total_size, offset;

  SYMBOL recsym = symalloc();
  recsym->kind = RECORDSYM;
  rectok->symtype = recsym;
  recsym->datatype = argstok->symtype;
  offset = wordaddress(argstok->symtype->size, 8);  // TODO: test this w/ something size 8
  total_size = offset;

  TOKEN curr = argstok;
  TOKEN next = argstok->link;
  while (next) {

    curr->symtype->link = next->symtype;
    offset = wordaddress(next->symtype->size, 8);   
    next->symtype->offset = total_size;
    total_size += offset;

    curr = next;
    next = next->link;
  }

  recsym->size = total_size;


  if (DEBUG && DB_INSTREC) {
    printf("instrec\n");
    dbugprinttok(rectok);
    dbugprinttok(argstok);
  }
  return rectok;
}

void  instconst(TOKEN idtok, TOKEN consttok) {
    SYMBOL sym, typesym;
    int align = alignsize(typesym);

    sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = consttok->datatype;
    if(sym->basicdt == REAL) //real
    {
        sym->constval.realnum = consttok->realval;
    }
    if(sym->basicdt == INTEGER) //int
    {
        sym->constval.intnum = consttok->intval;
    }
    
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  SYMBOL ptrsym, sym;
  ptrsym = symalloc();
  ptrsym->kind = POINTERSYM;
  ptrsym->basicdt = POINTER;
  ptrsym->size = basicsizes[POINTER];
  tok->symtype = ptrsym;
  sym = searchins(typename->stringval);
  sym->kind = TYPESYM;
  ptrsym->datatype = sym;

  if (DEBUG & DB_INSTPOINT) {
    printf("instpoint\n");
    dbugprinttok(tok);
    dbugprinttok(typename);
  }
  tok->datatype = POINTER;

  return tok;

}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) {

    SYMBOL sym, typesym;
    typesym = typetok->symtype;

    sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    if (DEBUG && DB_INSTTYPE) {
      printf("insttype\n");
      dbugprinttok(typename);
      dbugprinttok(typetok);
    }
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
   labels[labelnumber++] = num->intval;
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int whole_size = 0;
  TOKEN temp = idlist;
  while(temp) {
    instconst(temp, makeintc(whole_size));
    whole_size ++;
    temp = temp->link;
  }
  TOKEN subrange = makesubrange(idlist, 0, whole_size - 1); 
  return subrange;
}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) {
  // if (low > high) {
  //   printf(" Error: low bound cannot be greater than high bound\n\n");
  //   return NULL;
  // }

  TOKEN out = copytok(tok);
  SYMBOL subrange = symalloc();
  subrange->kind = SUBRANGE;
  subrange->basicdt = INTEGER;
  subrange->lowbound = low;
  subrange->highbound = high;
  subrange->size = basicsizes[INTEGER];
  out->symtype = subrange;
  
  if (DEBUG & DB_MAKESUBRNG) {
    printf("makesubrng\n");
    dbugprinttok(tok);
    dbugprinttok(out);
    printf(" low bound: %d\n high bound: %d\n\n", low, high);
  }

  return out;
}

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok)
  {  

    SYMBOL sym, typesym; int align;
     typesym = typetok->symtype;
     align = alignsize(typesym);
      if (DEBUG && DB_INSTVARS) {
        printf("instvars\n");
        dbugprinttok(typetok);
      }
     while ( idlist != NULL )   /* for each id */
       {  sym = insertsym(idlist->stringval);
          sym->kind = VARSYM;
          sym->offset = wordaddress(blockoffs[blocknumber], align);
          sym->size = typesym->size;
          blockoffs[blocknumber] =
                         sym->offset + sym->size;
          sym->datatype = typesym;
          sym->basicdt = typesym->basicdt;

          if (DEBUG && DB_INSTVARS) {

            dbugprinttok(idlist);
            dbugprinttok(typetok);
          }
          idlist = idlist->link;
        };
    if (DEBUG && DB_INSTVARS)
      printstlevel(1);
  }

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) {
  if (DEBUG & DB_MAKEAREF) {
    printf("makearef\n");
    dbugprinttok(var);
    dbugprinttok(off);
    dbugprinttok(tok);
  }

  TOKEN aref = makeop(AREFOP);
  aref->operands = var;
  var->link = off;

  if (DEBUG & DB_MAKEAREF) {
    printf("makearef().\n");
    dbugprinttok(aref);
  } 
  
  return aref;
}

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
// TOKEN makepnb(TOKEN tok, TOKEN statements) {

//   if (statements->whichval == PROGNOP && ELIM_NESTED_PROGN) {
//     if (DEBUG & DB_MAKEPNB) {
//       printf("In makepnb()\n\n");
//       dbugprint2args(tok, statements);
//       printf(" Finished makepnb().\n");
//       dbugprint1tok(statements);
//     }
//     return statements;
//   }
//   if (DEBUG & DB_MAKEPNB) {
//     printf("In makepnb(); transferring to makeprogn()...\n");
//   }
//   return (makeprogn(tok, statements));
// }

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
// TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {

//   if (DEBUG & DB_MAKEWHILE) {
//     printf("In makewhile()\n");
//     dbugprint4args(tok, expr, tokb, statement);
//   }

//   if (expr->operands->link && expr->operands->link->whichval == (NIL - RESERVED_BIAS)) {
//     expr->operands->link->tokentype = NUMBERTOK;
//     expr->operands->link->datatype = INTEGER;
//     expr->operands->link->whichval = 0;
//   }

//   TOKEN label_tok = makelabel();
//   TOKEN goto_tok = makegoto(label_tok->operands->intval);
//   TOKEN while_progn_tok = makepnb(talloc(), label_tok); // operand label_tok to while_progn_tok
//   TOKEN do_progn_tok = makepnb(talloc(), statement);    // operand statement to do_progn_tok
//   TOKEN ifop_tok = makeif(makeop(IFOP), expr, do_progn_tok, NULL);

//   if (!label_tok || !goto_tok || !while_progn_tok ||
//     !do_progn_tok ||!ifop_tok) {
//     printf(" Failed to alloc TOKEN(s), makewhile().\n");
//     return NULL;
//   }

//   label_tok->link = ifop_tok;

//   /* Handle elimination of nested progns */
//   if (do_progn_tok->whichval != PROGNOP) {
//     do_progn_tok->operands = statement;
//     statement->link = goto_tok;
//   }
//   else {  // do_progn_tok == statement
//     get_last_link(do_progn_tok->operands)->link = goto_tok;
//   }

//   if (DEBUG & DB_MAKEWHILE) {
//     printf(" Finished makewhile().\n");
//     dbugprint1tok(while_progn_tok);
//   }

//   return while_progn_tok;
// }

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
// TOKEN dogoto(TOKEN tok, TOKEN labeltok) {

//   // THIS METHOD SHOULD ONLY BE CALLED FOR A USER LABEL

//   if (DEBUG & DB_DOGOTO) {
//     printf("In dogoto()\n");
//     dbugprint2args(tok, labeltok);    
//   }

//   if (labeltok->intval < 0) {
//     printf(" Warning: label number is negative, dogoto().\n");
//   }

//   int internal_label_num = get_internal_label_num(labeltok->intval);
//   if (internal_label_num == -1) {
//     printf(" Error: could not find internal label number corresponding to user label number %d\n", labeltok->intval);
//     return NULL;
//   }
  
//   if (DEBUG & DB_DOGOTO) {
//     printf(" Finished dogoto().\n");
//     printf("  Found internal label number %d corresponding to user label number %d\n", internal_label_num, labeltok->intval);
//     printf("  Transferring to makegoto()...\n\n");
//   }

//   return (makegoto(internal_label_num));
// }

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedotn");
    dbugprinttok(var);
    dbugprinttok(dot);
    dbugprinttok(field);
  }

  TOKEN aref;
  TOKEN offset = get_offset(var, field);

  if (var->whichval == AREFOP) {
    /* Avoid adding multiple copies to the tree. */

    if (offset->whichval >= 0) {
      var->operands->link = offset;
    }
    aref = var;
  }
  else {
    aref = makearef(var, offset, NULL);
  }

  /* Change aref's datatype to REAL to avoid incorrect
     fixes/floats in binop(). NULL out the dummy link. */
  // if (offset->link && offset->link->datatype == REAL &&
  //   offset->link->realval == -DBL_MAX) {

  //   aref->datatype = REAL;
  //   offset->link = NULL;
  // }
  
  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
    dbugprinttok(aref);
    // ppexpr(aref);
    // printf("\n");
  }

  return aref;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(var);
    dbugprinttok(tok);   
  }

  tok->operands = var;

  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(tok);
  }

  return tok;  
}

int get_internal_label_num(int external_label_num) {
  int i;
  for (i = 0; i < 100; i++) {
    if (labels[i] == external_label_num)
      return i;
  }
  return -1;
}
/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {

  if (DEBUG & DB_DOLABEL) {
    printf("dolabel()\n");
    dbugprinttok(labeltok);
    dbugprinttok(tok);
    dbugprinttok(statement);   
  }
  
  int internal_label_num = get_internal_label_num(labeltok->intval);
  if (internal_label_num == -1) {
    printf(" Error: label %d not found in label table\n", labeltok->intval);
    return NULL;
  }

  TOKEN do_progn_tok = makeop(PROGNOP);
  TOKEN label_tok = makeop(LABELOP);
//  TOKEN do_progn_tok = makeprogn(makeop(PROGNOP), makeop(LABELOP)); // second arg will never be progn, so skip makepnb()
  TOKEN label_num_tok = makeintc(internal_label_num);

  if (!do_progn_tok || !label_tok || !label_num_tok) {
    printf(" Failed to alloc label TOKEN(s), dolabel().\n");
    return NULL;
  }

  do_progn_tok->operands = label_tok;
  label_tok->operands = label_num_tok;
  label_tok->link = statement;

  if (DEBUG & DB_DOLABEL) {
    printf(" Finished dolabel().\n");
    dbugprinttok(do_progn_tok);
  }

  return do_progn_tok;
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(s)
  char * s;
  { 
  fputs(s,stderr); putc('\n',stderr);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
  }
