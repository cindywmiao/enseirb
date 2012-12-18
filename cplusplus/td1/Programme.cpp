#include "Chaine.hpp"
#include <iostream>
#include <cstring>
void annexe (Chaine s){
  
}

int main(void){
  Chaine c1;
  Chaine *c2 = new Chaine("hello");

  std::cout << c1.taille() << std::endl;
  std::cout << c2->taille() << std::endl;

  Chaine c3("helloagain");
  annexe(c3);
  
  std::cout << c3.taille() << std::endl;

  for(int i = 0; i < c2->taille() ; i++)
    std::cout << c2->get(i) << std::endl; 
  delete(c2);
  return 1;
}
