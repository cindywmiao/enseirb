#include<cstdio>

class F{
  Mere * _f[42]; // pointeur 
  int _nb;
public:
  void ajouter(Mere *m){  //pointeur
    _f[_nb] = m;
  }
  void ajouter(Mere &m){  //reference
    _f[_nb] = &m;
  }
}
class Mere {
public:
  virtual void message(){
    std::printf("je suis la classe Mere\n");
  }
  ~Mere(){
    std::cerr << _func << std::endl;
  }
};


class Fille : public Mere {
public:
  virtual void message(){
    std::printf("je suis la classe Fille\n");
  }
   ~Fille(){
    std::cerr << _func << std::endl;
  }
};


// Ex1

// int main(){
//   Fille *fille= new Fille;
//   fille->message();
//   Mere *mere=fille;
//   mere->message();
//   std::printf("Mere: %d\n",sizeof(Mere));
//   std::printf("Fille: %d\n",sizeof(Fille));
//   delete mere;
// }

// int main(){
//   Mere *mere=NULL;
//   mere->message();
// }

// Ex2
int main(){
  Fille *f = new Fille();
  Mere &m= *f;
  m.message();
  delete f;
  // delete &m;
}

/*
sans virtual: liasion statique
je suis la classe Fille
je suis la classe Mere
Mere: 1
Fille: 1


mere virtual
je suis la classe Fille
je suis la classe Fille
Mere: 4
Fille: 4

mere virtual et fille virtual = seulement mere virtual
je suis la classe Fille
je suis la classe Fille
Mere: 4
Fille: 4

seulement fille virtual, jamais utiliser
je suis la classe Fille
je suis la classe Mere
Mere: 1
Fille: 4

dans le 2éme main
sans virtual => statique 
je suis la classe Mere

avec virtual => dynamique
erreur de segmentation



*/
