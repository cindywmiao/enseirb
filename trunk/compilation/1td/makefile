all:
	lex exo1.l
	gcc -W lex.yy.c -ll -o count

	lex exo1_2.l
	gcc -W lex.yy.c -ll -o flottant

	lex exo1_3.l
	gcc -W lex.yy.c -ll -o section

count:
	lex exo1.l
	gcc -W lex.yy.c -ll -o count
	./count < Rapport.tex

flottant:
	lex exo1_2.l
	gcc -W lex.yy.c -ll -o flottant
	./flottant < Rappport.tex

section:
	lex exo1_3.l
	gcc -W lex.yy.c -ll -o section
	./section < Rapport.tex

ex21:
	yacc exo2.y -d
	lex exo2_1.l
	gcc -W lex.yy.c -ll -o ex21

ex23:
	yacc exo2_3.y -d
	lex exo2_3.l
	gcc -W lex.yy.c -ll -o ex23

ex24:
	yacc exo2_4.y -d
	lex exo2_4.l
	gcc -W lex.yy.c -ll -o ex24

clear:
	rm -rf *~