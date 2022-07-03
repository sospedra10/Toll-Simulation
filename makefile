all: simPeaje
	./simPeaje
simPeaje: simPeaje.c controles.o ruleta.o reloj.o 
	gcc simPeaje.c controles.o ruleta.o reloj.o peajes.o cabinas.o colaDeTElems.o -lm -o simPeaje -g
controles.o: controles.c peajes.o ruleta.o
	gcc -c controles.c
peajes.o: peajes.c reloj.o cabinas.o
	gcc -c peajes.c
cabinas.o: cabinas.c ruleta.o reloj.o colaDeTElems.o
	gcc -c cabinas.c
ruleta.o: ruleta.c
	gcc -c ruleta.c
reloj.o: reloj.c
	gcc -c reloj.c
colaDeTElems.o: colaDeTElems.c
	gcc -c colaDeTElems.c
clean:
	 rm *.o