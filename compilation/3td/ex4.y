%{
#include <stdio.h>
#include "y.tab.h"
%}

%token ID N
%%

S
: E
;
;
E
: T '+' E 
| T '-' E 
| T
;
T
: F '*' T 
| F
;
F
: N       
| '(' E ')'
;
%%
int main (int argc, char *argv[]) {
    yyparse ();
    return 0;
}
