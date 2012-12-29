#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include "Chaine.hpp"

namespace enseirb{
  class Personne{ 
  protected :
    Chaine _nom;
    
  public:
    Personne(const Chaine &nom);
    Personne(const char*);
    Chaine nom();
    Chaine &nom2();
    ~Personne();
  };

  class Etudiant: public Personne{
  private:
    Chaine _filiere;
    Chaine _enseignement; // ==> valeur
    Chaine _eleveNom;
  
  public:
    Etudiant(Chaine &, Chaine &);
    Etudiant(const char *, Chaine &);
    ~Etudiant();

    virtual Chaine nom() const;
    virtual const Chaine& nom2() const;

    Chaine filiere() const;
    void setEnseignement(Chaine&);
    
  };

}
#endif
