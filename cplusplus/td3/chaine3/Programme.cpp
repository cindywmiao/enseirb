#include <iostream>

#include "Chaine.hpp"
#include "Personne.hpp"

using enseirb::Chaine;
using enseirb::Personne;

Chaine annexe(Chaine u, Chaine t) {
  return u + t;
}


void affiche(const Chaine &s){
  std::cout << "AFFICHE <";
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}

void afficheNom(Personne &p){
  affiche(p.nom());
  affiche(p.nom2());
  //std::cout << p.nom() << "," << p.nom2() << std::endl;
}

void afficheNom2(Personne &p){
  std::cout << p.nom() << "," << p.nom2() << std::endl;
}

int main(){
  Chaine s("un texte long");
  //Chaine p("test");
  
  //Chaine r = annexe(s, p);
  //Chaine r(annexe(s, p));

  Personne pr(s);
  afficheNom(pr);
  afficheNom2(pr);

  //  Chaine nom = p.nom();

  //affiche(r);
}
