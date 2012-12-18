#include<cstring>
#include<iostream>
#include "Chaine.hpp"

#include <memory>


namespace enseirb {

  static char* copie(const char* src, unsigned int taille) {
    char *tmp = new char[taille + 1];
    std::strcpy(tmp, src);
    return tmp;
  } 

  Chaine::Chaine():_taille(0) {
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    _donnees    = copie("",0);
  }

  Chaine::Chaine(const char *s) {
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    // Cas s==NULL a gerer plus tard.
    _taille = strlen(s);
    _donnees = copie(s, _taille);
  }

  Chaine::~Chaine() {
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    delete[] _donnees;
    _donnees=NULL;
  }


  Chaine::Chaine(const Chaine &c):_taille(c._taille){
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    _donnees = copie(c._donnees, c._taille);
  }

  const Chaine &Chaine::operator=(const Chaine &c){
    std::cerr << __func__ << std::endl;
    if (this == &c) 
      return *this;

    delete [] _donnees;
    _taille = c._taille;
    _donnees = copie(c._donnees, c._taille);
    return *this;
  }

  unsigned int Chaine::taille() const {
    return _taille;
  }

  char Chaine::operator[](unsigned int i) const{
    if (i>_taille) 
      return '\0';
    return _donnees[i];
  }

  Chaine Chaine::operator+(const Chaine &c) const {
    int tailleTmp = _taille + c._taille;
    
    if (this==&c) return *this;

    if (0 == tailleTmp)
      return *this;
  
    char *donneesTmp = new char[tailleTmp + 1];
    //    std::unique_ptr<char []> autoDelete(donneesTmp);

    if (_taille != 0)
      std::strcpy(donneesTmp, _donnees);

    if (c._taille !=0)
      std::strcpy(donneesTmp + _taille, c._donnees);
  
    return Chaine(donneesTmp); // variable locale
  }

  std::ostream &operator << (std::ostream &stream, const Chaine &c){
    
    return stream<< c._donnees;

  } 
}
