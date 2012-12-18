%{
#include <stdio.h>
#include "y.tab.h"
%}

%token ID N

%%

S
: I S
| I
;
I
: ID '=' E ';'
;
E
: T '+' E {n++; printf("%%x%d = add i32 %%x%d, %%x%d\n", n, $1,$3);}
| T '-' E {n++; printf("%%x%d = sub i32 %%x%d, %%x%d\n", n, $1,$3);}
| T
;
T
: F '*' T {n++; printf("%%x%d = mul i32 %%x%d, %%x%d\n", n, $1,$3);}
| F
;
F
: N {n++; printf("%%x%d = add i32 %%x%d, 0\n",n,$1);}
| ID
| '(' E ')'
;
%%
int main (int argc, char *argv[]) {
    yyparse ();
    return 0;
}
