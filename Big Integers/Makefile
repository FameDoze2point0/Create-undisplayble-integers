main: main.o listeLib.o entierLib.o arbreLib.o hachageLib.o chargement.o
	gcc main.o listeLib.o entierLib.o arbreLib.o hachageLib.o chargement.o -o main 
	#
	#Pour lancer le programme, faites "./main"

main.o: main.c listeLib.h entierLib.h arbreLib.h hachageLib.h chargement.h
	gcc	-c main.c

chargement.o: chargement.c chargement.h
	gcc	-c chargement.c

hachage.o: hachageLib.c hachageLib.h
	gcc	-c hachageLib.c

arbre.o: arbreLib.c arbreLib.h
	gcc	-c arbreLib.c

entier.o: entierLib.c entierLib.h
	gcc	-c entierLib.c

liste.o: listeLib.c listeLib.h
	gcc	-c listeLib.c

clean:
	rm -f *.o