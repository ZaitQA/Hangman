CC = gcc
CFLAGS = -Wextra -Wall -pedantic -std=c99 -g -lcurl
SRC = src/*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o hangman

clean:
	rm hangman
