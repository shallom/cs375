LEX README:

Name: Kevin Fu
UTEID: ktf326
Course: CS375
Programming Assignment: Lexical Analyzer in Lex

Explanation: 

I used regex expressions for the numbers in order to ensure that all number values were covered. I had a different case for scientific notation and integer values. I also used regular expressions for strings as well to ensure that all tokens that were strings were covered as well. The regex expressions help differentiate between pure integers and floating point values. 

I added the rest of the delimiters, operators, and reserved words, so that each individual token would be recognized. This was very simple and involved copying and pasting and then changing the contents of each line.

I created several functions:

The first helps to deal with strings by checking for the existence of quotation marks and dealing with them appropriately.

The second function deals with pure integers that are originally given without a decimal or an exponent. I then use a similar function to install_fnum, but modified for integers.

The third function is more of a modification that checks for the existence of a decimal or scientific notation to output the correct floating point number.