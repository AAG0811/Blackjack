game: main.o cards.o game.o
	gcc main.o cards.o game.o -o game

main.o: main.c cards.h game.h
	gcc -c main.c

cards.o: cards.c cards.h
	gcc -c cards.c

game.o: game.c game.h
	gcc -c game.c

.PHONY: clean
clean:
	rm game *.o