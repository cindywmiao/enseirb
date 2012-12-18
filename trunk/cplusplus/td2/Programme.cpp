#include <cstdio>

#include "Chaine.hpp"
// Ex1
// void annexe(Chaine *s) {
//   std::printf("Taille chaine  %d\n", s->taille());
// }

// int main() {
//   Chaine *c = new Chaine("Une petite");

//   delete(c);
//   annexe(c);
// }

// Ex2
void annexe(const Chaine &s) {
  std::printf("Taille chaine  %d\n", s.taille());
}

// int main() {
//   Chaine c("Une petite");
//   annexe(c);
//   annexe(Chaine("yyy"));//temporaire
//   return 0;
// }

// Ex3
// int main(){
//   Chaine s1("une_chaine");
//   Chaine s2(s1);
//   Chaine s3 = s1;
//   s1.debug();
//   s2.debug();
//   s3.debug();
//   return 0;
// }

// Ex5 // constructeur 3 fois
Chaine &print(Chaine &s){
  Chaine t(s);
  t.debug();
  return s;
}

// int main(){
//   Chaine c("message");
//   print(c);
//   return 0;
// }

// Ex6
// int main(){
//   Chaine s1("une_chaine");
//   Chaine s2("Coucou");
//   s2 = s1;
//   s2.debug();
//   return 0;
// }

//Ex7
int main(){
  Chaine s("une chaine"); 
  for (unsigned int i = 0; i < s.taille(); i++)
    printf("%c\n",s[i]);
}

//Ex8
// int main(){
//   Chaine s("une chaine");
//   printf("%s\n", (const char*)s);
// }
