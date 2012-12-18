%{
#include <stdio.h>
int num_lines = 0, num_chars = 0;
%}   
DIGIT [0-9]  
%%
{DIGIT}*\.{DIGIT}+ {printf("%s\n",yytext);}
\n     {  ++num_lines; ++num_chars; }
.      { ++num_chars; }

%%

int main() {
  yylex();
  printf( "# of lines = %d, # of chars = %d\n",
	num_lines, num_chars );
}