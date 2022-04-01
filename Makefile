all: morpion clean exe

morpion: main.o morpion.o ia.o
	gcc -Wall -Wextra -pedantic -lm main.o morpion.o ia.o -o morpion

main.o: main.c
	gcc -Wall -Wextra -pedantic -lm -c main.c

morpion.o: morpion.c
	gcc -Wall -Wextra -pedantic -lm -c morpion.c

ia.o: ia.c
	gcc -Wall -Wextra -pedantic -lm -c ia.c

clean:
	rm -rf *.o

exe: morpion
	./morpion