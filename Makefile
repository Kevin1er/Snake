
all: vecteur.o main.o
	gcc -o Main vecteur.o main.o -lm -lglut -lGLU -lGL

cube.o: cube.c cube.h
	gcc -c cube.c -o cube.o

vecteur.o: vecteur.c vecteur.h
	gcc -c vecteur.c -o vecteur.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -rf Main vecteur.o main.o
