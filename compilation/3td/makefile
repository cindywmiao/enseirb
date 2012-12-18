all:
	llvm-as fichier.ll -f -o fichier.bc
	llvm-ld -o=fichier -native fichier.bc

ex1: 
	llvm-as ex1.ll -f -o ex1.bc
	llvm-ld -o=ex1 -native ex1.bc
	yacc exo1.y -d
	lex exo2_1.l
	gcc lex.yy.c -ll -o exo1

ex2:
	llvm-as ex2.ll -f -o ex2.bc
	llvm-ld -o=ex2 -native ex2.bc

clear: 
	rm -rf *~
	rm -rf \#*
	rm -rf ex1.bc
	rm -rf ex1
	rm -rf ex2.bc
	rm -rf ex2