#include<cstdio>


class Mere {
public:
  void message(){
    printf("je suis la classe Mere\n");
  }
};


class Fille : public Mere {
public:
   void message(){
    printf("je suis la classe Fille\n");
  }
};




int main(){
  Fille *fille= new Fille;

  fille->message();

  Mere *mere=fille;
  mere->message();

  printf("Mere: %d\n",sizeof(Mere));
  printf("Fille: %d\n",sizeof(Fille));


  delete mere;
}




/*
int main(){
Mere *mere=NULL;

mere->message();
}
*/
