#include "Chaine.hpp"
#include <cstdio>
#include <cstring>

static char vide = '\0';
Chaine::Chaine(){

  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
  _taille = 0;
  //_donnees = &vide;
  _donnees = new char[1];
  strcpy(_donnees, "\0");
}

Chaine::~Chaine(){ //delete

  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
  
  delete[] _donnees;
}
Chaine::Chaine(const char *s){
  _taille = strlen(s);
  _donnees = new char[_taille + 1];
  strcpy(_donnees,s);
}

unsigned int Chaine::taille(){
  return _taille;
}
char Chaine::get(unsigned int i){
  if(i >= _taille){
    printf("Erreur");
    return vide;
  }
  
  else
    return _donnees[i];

}
