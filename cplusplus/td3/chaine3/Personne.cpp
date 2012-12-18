#include <cstring>
#include "Personne.hpp"

namespace enseirb{

  Personne::Personne(const Chaine &nom){
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    _nom = nom;
  }

  Personne::Personne(const char * s):_nom(s){
      std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }
  Chaine Personne::nom(){
    return _nom;
  }

  Chaine& Personne::nom2(){
    return (_nom);
  }

  Personne::~Personne(){
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }

}
