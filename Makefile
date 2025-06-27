.PHONY: test clean game

game: main.c
	gcc main.c -o game

test: game
	./game

clean:
	rm game