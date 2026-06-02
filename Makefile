CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = $(wildcard src/*.c)

OUT = flashcards

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)