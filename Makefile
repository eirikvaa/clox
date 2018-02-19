CC = cc
CFLAGS = -std=c99 -Wall -g

all: clox

clox: main.o memory.o chunk.o
	$(CC) $(CFLAGS) -o clox main.o memory.o chunk.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c memory.h

chunk.o: chunk.c chunk.h
	$(CC) $(CFLAGS) -c chunk.c chunk.h

clean:
	rm -f clox *.o *.h.gch
