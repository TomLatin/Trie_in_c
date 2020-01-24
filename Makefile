CC=gcc
FLAGS=-Wall -g

all: frequency

frequency: main.o Trie.o
	$(CC) $(FLAGS) main.o Trie.o -o frequency

Trie.o: Trie.c
	$(CC) $(FLAGS) -c Trie.c -o Trie.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o

.PHONY:clean all

clean:
	rm -f *.o frequency