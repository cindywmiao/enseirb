#include<cstdio>
#include<cstring>
#include<iostream>
#include "Chaine.hpp"

Chaine::Chaine():_taille(0) {
  _donnees=new char[1];
  _donnees[0]='\0';
}

Chaine::Chaine(const char *s) {
  // Cas s==NULL a gerer plus tard.
  // _taille = std::strlen(s);
  //_donnees = new char[_taille + 1];
  //std::strcpy(_donnees, s);
  copie_Chaine(s,std::strlen(s));
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::Chaine(const Chaine &c){
  //_taille = c.taille();
  //_donnees = new char[_taille + 1];
  //std::strcpy(_donnees,c._donnees);
  copie_Chaine(c._donnees,c._taille);
  std::printf("%s(%d): %s\n", __FILE__,__LINE__,__func__);

}
Chaine::~Chaine() {
  delete[] _donnees;
  _donnees=NULL;
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

unsigned int Chaine::taille() const {
    return _taille;
}

void Chaine::debug() const{
  std::cout << _donnees << std::endl;
}

void Chaine::copie_Chaine(const char *donnees, int taille){
  _taille = taille;
  _donnees = new char[_taille + 1];
  std::strcpy(_donnees,donnees);
  
}
const Chaine& Chaine::operator= (const Chaine &c){
  delete[] _donnees;
  copie_Chaine(c._donnees,c._taille);
  return *this;
}

char Chaine::operator[](unsigned int indice) const {
  if(indice < _taille)
    return _donnees[indice];
  return '\0';
}

// char & Chaine::operator[](unsigned int indice){
// if (indice < _taille)
// return _donnees[indice];
// Exception
// }
