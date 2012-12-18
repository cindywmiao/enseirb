CC=g++
CPPFLAGS=-Wall -Wextra -std=c++0x

prog: Chaine.o Personne.o Programme.o 
	$(CC) $^ -o $@

Programme.o: Chaine.hpp Personne.hpp

Chaine.o: Chaine.hpp

Personne.o: Personne.hpp

clean:
	rm -f *.o prog