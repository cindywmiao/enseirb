all:

	gcc -o client client.c
	gcc -o serveur serveur.c

ser:
	./serveur versclient1 versclient2 versclient3

c1:
	./client versclient1

c2:
	./client versclient2

c3:
	./client versclient3

clear:
	rm -rf serveur client
	rm -rf FIFO/*
	rm -rf *~