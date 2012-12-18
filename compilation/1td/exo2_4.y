%{
#include <stdio.h>
#include "y.tab.h"
  int hash_table[101];
  int hash(char * c){
    int n = 0;
    while (*c != '\0') n = n + 8 * *c++;
    return n % 101;
  }
%}
%union{
  int n;
  char *s;
 }
%token <n>N  
%token <s>ID
%type <n> E T F

%%

S
: I S
| I
;
I
: ID '=' E ';' {hash_table[hash($1)] = $3; printf("%s = %d\n", $1, $3);}
;
E
: T '+' E {$$ = $1 + $3;}
| T '-' E {$$ = $1 - $3;}
| T {$$ = $1;}
;
T
: F '*' T {$$ = $1 * $3;}
| F {$$ = $1;}
;
F
: N {$$ = $1;}
| ID {$$ = hash_table[hash($1)]; free($1);}
| '(' E ')'
;
%%
int main (int argc, char *argv[]) {
    yyparse ();
    return 0;
}
