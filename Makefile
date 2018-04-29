
all: vecteur.o transform.o objet.o serpent.o main.o
	gcc -o Main vecteur.o transform.o objet.o serpent.o main.o -lm -lglut -lGLU -lGL

vecteur.o: vecteur.c vecteur.h
	gcc -c vecteur.c -o vecteur.o

transform.o: transform.c transform.h
	gcc -c transform.c -o transform.o

objet.o: objet.c objet.h
	gcc -c objet.c -o objet.o

serpent.o: serpent.c serpent.h
	gcc -c serpent.c -o serpent.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -rf Main vecteur.o transform.o objet.o serpent.o main.o
