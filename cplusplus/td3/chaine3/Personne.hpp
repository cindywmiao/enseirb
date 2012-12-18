#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include "Chaine.hpp"

namespace enseirb{
  class Personne{ 
  private :
    Chaine _nom;
    
  public:
    Personne(const Chaine &nom);
    Personne(const char*);
    Chaine nom();
    Chaine &nom2();
    ~Personne();
  };

}
#endif
