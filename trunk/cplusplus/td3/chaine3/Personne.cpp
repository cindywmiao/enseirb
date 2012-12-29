#include <cstring>
#include "Personne.hpp"

namespace enseirb{
  static Chaine el("Eleve :");
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

  Etudiant::Etudiant(Chaine & nom, Chaine &filiere)
    :Personne(nom),_filiere(filiere),_eleveNom(el + nom){
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }

  Etudiant::Etudiant(const char * nom, Chaine & filiere)
    :Personne::_nom(nom),_filiere(filiere){
    _eleveNom(el + _nom);
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }

  Etudiant::~Etudiant(){
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }

  Chaine Etudiant::filiere() const{
    return _filiere;
  }

  void Etudiant::setEnseignement(Chaine & enseignement){
  
    _enseignement = enseignement;
  }


  Chaine Etudiant::nom() const{ // valeur
    return el + Personne::nom();
  }

  const Chaine & Etudiant::nom2() const{ // reference
    return  _eleveNom;
  }
}
