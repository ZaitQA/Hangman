CC = gcc
CFLAGS = -pedantic -std=c99 -lcurl
SRC = src/*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o hangman

clean:
	rm hangman
