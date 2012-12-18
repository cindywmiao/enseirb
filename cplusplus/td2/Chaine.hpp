#ifndef _Chaine_h_
#define _Chaine_h_

class Chaine{
  
private:
  unsigned int _taille;
  char * _donnees;

public :
  Chaine();
  Chaine(const char *s);
  explicit Chaine(const Chaine &);
  ~Chaine();
  
  
  unsigned int taille() const;
  void debug() const;
  const Chaine & operator = (const Chaine &);
  char operator[](unsigned int indice)const ;
private:
  void copie_Chaine(const char *donnees, int taille); 
  
};

#endif
