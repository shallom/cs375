// Name: Kevin Fu
// UTEID: ktf326
// Program: Lexical Analyzer
// Due Date: February 10, 2015

/* lex1.c         14 Feb 01; 31 May 12       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2001 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "token.h"
#include "lexan.h"

/* Arrays that contain the operators, delimiters, and reserved words. */
static char* opprnt[]  = { " ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=",
                           ">=", ">",  "^", ".", "and", "or", "not", "div",
                           "mod", "in", "if", "goto", "progn", "label",
                           "funcall", "aref", "program", "float"};
static char *delprnt[] = { "  ", ",", ";", ":", "(", ")", "[", "]",
                           ".."} ;
static char *resprnt[] = { " ", "array", "begin", "case", "const", "do",
                           "downto", "else", "end", "file", "for",
                           "function", "goto", "if", "label", "nil",
                           "of", "packed", "procedure", "program", "record",
                           "repeat", "set", "then", "to", "type",
                           "until", "var", "while", "with" };

/* Buffer to hold strings of characters as needed. */
char inString[MAXCHARCLASS];

/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

/* Calls getchar twice. */
void get2chars()
{
  getchar();
  getchar();
}

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
{
  int c, d;
  while ((c = peekchar()) != EOF
         && (c == ' ' || c == '\n' || c == '\t') 
         || c == '{' 
         || (c == '(' && (d = peek2char()) != EOF && d == '*'))
  {
    // Skips all characters that are part of a comment of the form { comment }
    if (c == '{')
    {
      getchar();
      while ((c = peekchar()) != EOF && c != '}')
      {
        getchar();
      }
      getchar();
    }
    // Skips all characters that are part of a comment of the form (* comment *)
    else if (c == '(' 
      && (d = peek2char()) != EOF 
      && d == '*')
    {
      get2chars();
      while ((c = peekchar()) != EOF 
        && (d = peek2char()) != EOF 
        && (c != '*' || d != ')'))
      {
        getchar();
      }
      get2chars();
    }
    // Skips blanks and whitespaces
    else 
    {
      getchar();
    }
  }
}

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
{
  int c, i;
  int ptr = 0;
  // Puts all characters that are part of the identifier into the buffer
  while ( (c = peekchar()) != EOF
          && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC))
  { 
      c = getchar();
      inString[ptr] = c;
      ptr++;
  }
  // Null terminates the string at the end or truncates the string if too long
  if (ptr >= 16)
    inString[15] = '\0';
  else
    inString[ptr] = '\0';
  // Compares the string with the reserved words. If matches, returns the correct token
  for (i = 1; i < 30; i++)
  {
    if (!strcmp(inString, resprnt[i]))
    {
      return(returnReserved(i, tok));
    }
  }
  // Compares the string with the operators. If matches, returns the correct token
  for (i = 14; i < 20 ; i++)
  {
    if (!strcmp(inString, opprnt[i]))
    {
      return(returnOperator(i, tok));
    }
  }
  // Returns the identifier if it is neither a reserved word nor an operator
  return(returnIdentifier(tok));
}

/* Returns the token for reserved words */
TOKEN returnReserved(int i, TOKEN tok)
{
  tok->tokentype = RESERVED;
  tok->whichval = i;
  return(tok);
}

/* Returns the token for reserved words */
TOKEN returnOperator(int i, TOKEN tok)
{
  tok->tokentype = OPERATOR;
  tok->whichval = i;
  return (tok);  
}

/* Returns the token for identifiers */
TOKEN returnIdentifier(TOKEN tok)
{
  tok->tokentype = IDENTIFIERTOK;
  strcpy(tok->stringval, inString);
  return (tok);    
}

/* Returns the token for delimiters */
TOKEN returnDelimiter(int i, TOKEN tok)
{
  tok->tokentype = DELIMITER;
  tok->whichval = i; 
  return(tok);
}

/* Gets the string and returns its token */
TOKEN getstring (TOKEN tok)
{
  int c, d, e;
  int ptr = 0;
  int quoteptr = 0;
  // Skips the first quotation mark
  getchar();
  // Copies the contents of the string into the buffer
  while ( (c = peekchar()) != EOF 
    && !(c == '\n' || c == '\t'))
  { 
    d = getchar();
    e = peekchar();
    // Places a quotation inside the string if a double quote is found
    if (d == '\'' && e == '\'')
    {
      getchar();
      inString[ptr] = d;
    }
    // Ends the string creation if the end quotation mark is found
    else if (d == '\'')
    {
      quoteptr = ptr;
      break;
    }
    // Adds a character to the string normally if not a quotation
    else 
    {
      inString[ptr] = d;
    }
    ptr++; 
  }
  // Truncates the string through the use of null termination
  if (quoteptr > 15)
  {
    quoteptr = 15;
  }
  inString[quoteptr] = '\0';
  // Returns the token that contains the string
  tok->tokentype = STRINGTOK;
  strcpy(tok->stringval, inString);
  return (tok);
}

/* Get special characters, other delimiters, and other operators and returns their token */
TOKEN special (TOKEN tok)
{
  int c, i, d;
  int ptr = 0;
  // Finds the special character
  while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == SPECIAL)
  { 
    // Grabs two characters that may form the special characters
    c = getchar();
    inString[ptr] = c;  
    ptr++;
    d = peekchar();
    inString[ptr] = d;
    ptr++;
    inString[ptr] = '\0';
    // Compares the characters to the operators. If matches, returns token
    for (i = 1; i < 20; i++)
    {
      if (!strcmp(inString, opprnt[i]))
      {
        getchar();
        return (returnOperator(i, tok));
      }
    }
    // Compares the characters to the delimiters. If matches, returns token
    for (i = 1; i < 9; i++)
    {
      if (!strcmp(inString, delprnt[i]))
      {
        getchar();
        return (returnDelimiter(i, tok));
      }
    }
    // Tests only the first character
    ptr--;
    inString[ptr] = '\0';

    // Compares the character to the operators. If matches, returns token
    for (i = 1; i < 20; i++)
    {
      if (!strcmp(inString, opprnt[i]))
      {
        return (returnOperator(i, tok));
      }
    }
    // Compares the character to the delimiters. If matches, returns token
    for (i = 1; i < 9; i++)
    {
      if (!strcmp(inString, delprnt[i]))
      {
        return (returnDelimiter(i, tok));
      }
    }
  }
}

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{ 
  // Variables for calculating the number
  long num, oldnum, truncatednum;
  double afterDec, realNum, decCnt;
  int  i, c, d, charval, exponent, afterE, expCnt, intOORFlag, fltOORFlag;
  intOORFlag = 0;
  fltOORFlag = 0;
  decCnt = 1.0;
  num = 0;
  afterDec = 0;
  exponent = 0;
  oldnum = 0;
  // Grabs the digits before the decimal point
  while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
  {   
    c = getchar();
    charval = (c - '0');
    oldnum = truncatednum;
    // If value overflows the long data type, uses an exponent variable 
    if (num > MAXLONGVAL)
    {
      exponent++;
    }
    else
    {
      num = num * 10 + charval;
    }
    // If integer value overflows an integer, truncates the number error
    if (num > MAXINTVAL)
    {
      truncatednum = oldnum;
      intOORFlag = 1;
    }
    else
    {
      truncatednum = num;
    }
  }
  // Deals with the digits after the decimal point
  if ( (c = peekchar()) == '.' 
    && c != EOF 
    && (d = peek2char()) != EOF 
    && CHARCLASS[d] == NUMERIC)
  {
    intOORFlag = 0;
    c = getchar();
    // Calculates the decimal that is after the decimal point
    while ( (c = peekchar()) != EOF
            && CHARCLASS[c] == NUMERIC)
    {   
      c = getchar();
      charval = (c - '0');
      decCnt*= 10.0;
      afterDec = afterDec +  ((double) charval) / decCnt;
    }
    // Sums the whole number and decimal portions
    realNum = (double) num + afterDec;
    // Deals with the exponent after the 'e' character
    if ( (c = peekchar()) == 'e' 
      && c != EOF 
      && (d = peek2char()) != EOF 
      && (CHARCLASS[d] == NUMERIC || d == '+' || d == '-'))
    {
      c = getchar();
      // Gets the exponent from the input characters
      if (exponent == 0)
        afterE = getExponent();
      else
        afterE = getExponent() + exponent;
      exponent = 0;
      // If exponent is too large sets floating point out of range error
      if (afterE >= 80)
      {
        for (i = 0; i < afterE; i++)
        {
          realNum *= 10.0;
          if (realNum > FLT_MAX)
          {
            return(returnFloatError(tok));
          }
        }
      }
      else if (afterE <= -80)
      {
        afterE *= -1;
        for (i = 0; i < afterE; i++)
        {
          realNum /= 10.0;
          if (realNum < FLT_MIN)
          {
            return(returnFloatError(tok));
          }
        }
      }
      else
      {
        // If exponent is negative, divides the real number
        if (afterE < 0)
        {
          afterE *= -1;
          realNum /= dblpow[afterE];
        }
        // If the exponent is positive, multiplies the real number
        else
        {
          realNum *= dblpow[afterE];
        }
      }
    }
    if (!fltOORFlag)
    {
      // If overflow of long, multiplies float with prestored exponent
      if (exponent >= 80)
      {
        for (i = 0; i < exponent; i++)
        {
          realNum *= 10.0;
          if (realNum > FLT_MAX)
          {
            return(returnFloatError(tok));
          }
        }
      }
      realNum *= dblpow[exponent];      
    }
    // If number exceeds the maximum float or is less than the minimum float, outputs an error
    if (realNum > FLT_MAX || realNum < FLT_MIN || fltOORFlag)
    {
      return(returnFloatError(tok));
    }
    else
    {
      // Returns the token containing the real number
      return(returnReal(realNum, tok));
    }
  }
  // Deals with the case in which the digits before the 'e' do not contain a decimal
  else if ( (c = peekchar()) == 'e' && 
    c != EOF &&
    (d = peek2char()) != EOF &&
    (CHARCLASS[d] == NUMERIC ||
    d == '+' ||
    d == '-'))
  {
    intOORFlag = 0;
    c = getchar();
    // Gets the exponent from the input characters
    exponent += getExponent();
    // If exponent is negative, divides the real number
    if (exponent < 0)
    {
      exponent *= -1;
      realNum = (double) num;
      // If exponent is too large, returns token and outputs floating error
      if (exponent >= 80)
      {
        for (i = 0; i < exponent; i++)
        {
          realNum /= 10.0;
          if (realNum < FLT_MIN)
          {
            return(returnFloatError(tok));
          }
        }
        return(returnReal(realNum, tok));
      }
      // if exponent not too large, calculates and returns
      // if greater than the float max or less than the float min outputs float error
      else 
      {
        realNum = (double) num;
        realNum /= dblpow[exponent];
        if (realNum > FLT_MAX || realNum < FLT_MIN)
        {
          return(returnFloatError(tok));
        }
        else
          return(returnReal(realNum, tok));
      }
    }
    // If the exponent is positive, multiplies the real number
    else
    {
      // If exponent is too large, returns token and outputs floating error
      if (exponent >= 80)
      {
        realNum = (double) num;

        for (i = 0; i < exponent; i++)
        {
          realNum *= 10.0;
          if (realNum > FLT_MAX)
          {
            return(returnFloatError(tok));
          }
        }
        return(returnReal(realNum, tok));
      }
      // if exponent not too large, calculates and returns
      // if greater than the float max or less than the float min outputs float error
      else
      {
        realNum = (double) num;
        realNum *= dblpow[exponent];
        if (realNum > FLT_MAX || realNum < FLT_MIN)
        {
          return(returnFloatError(tok));
        }
        else
          return(returnReal(realNum, tok));
      }
    }
    // Returns the token containing the real number
    return(returnReal(num, tok));
  }
  // If the number is an integer returns the token and/or outputs an error
  else
  {
    if (intOORFlag == 1)
    {
      intOutOfRangeError();
      tok->intval = truncatednum;
      return(returnInt(truncatednum, tok));
    }
    else
    {
      return(returnInt(num, tok));
    }
  }
}

/* Returns the token for a real number */
TOKEN returnReal(double realNum, TOKEN tok)
{
  tok->realval = realNum;
  tok->tokentype = NUMBERTOK;
  tok->datatype = REAL;
  return(tok);
}

/* Returns the token for an integer */
TOKEN returnInt(int num, TOKEN tok)
{
  tok->intval = num;  
  tok->tokentype = NUMBERTOK;
  tok->datatype = INTEGER;
  return(tok);
}

/* Returns the exponent found from grabbing the characters */
int getExponent()
{
  int c, charval;
  int d = peekchar();
  int exponent = 0;
  // If - character exists, returns negative exponent
  if (d == '-')
  {
    c = getchar();
    while ( (c = peekchar()) != EOF
        && CHARCLASS[c] == NUMERIC)
    {
      c = getchar();
      charval = (c - '0');
      exponent = exponent * 10 + charval;
    }
    exponent *= -1;
  }
  // If + character exists, returns positive exponent
  else if (d == '+')
  {
    c = getchar();
    while ( (c = peekchar()) != EOF
        && CHARCLASS[c] == NUMERIC)
    {
      c = getchar();
      charval = (c - '0');
      exponent = exponent * 10 + charval;
    }
  }
  // In the absence of +/-, returns positive exponent
  else 
  {
    while ( (c = peekchar()) != EOF
        && CHARCLASS[c] == NUMERIC)
    {
      c = getchar();
      charval = (c - '0');
      exponent = exponent * 10 + charval;
    } 
  }
  return exponent;
}

/* Returns the token for overflow */
TOKEN returnFloatError(TOKEN tok)
{
  tok->realval = 0.0;
  floatOutOfRangeError();
  tok->tokentype = NUMBERTOK;
  tok->datatype = REAL;
  return(tok);
}

/* Prints the integer out of range error message. */
void intOutOfRangeError()
{
  printf("Integer number out of range\n");
}

/* Prints the float out of range error message. */
void floatOutOfRangeError()
{
  printf("Floating number out of range\n");
}

