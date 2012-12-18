#ifndef _Chaine_h_
#define _Chaine_h_

class Chaine{
  
private:
  unsigned int _taille;
  char * _donnees;

public :
  Chaine();
  ~Chaine();
  Chaine(const char *s);
  unsigned int taille();
  char get(unsigned i);
  
};

#endif
