CC = cc
CFLAGS = -std=c99 -Wall -g

all: clox

clox: main.o memory.o chunk.o debug.o value.o
	$(CC) $(CFLAGS) -o clox main.o memory.o chunk.o debug.o value.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c memory.h

chunk.o: chunk.c chunk.h
	$(CC) $(CFLAGS) -c chunk.c chunk.h

debug.o: debug.c debug.h
	$(CC) $(CFLAGS) -c debug.c debug.h

value.o: value.c value.h
	$(CC) $(CFLAGS) -c value.c value.h

clean:
	rm -f clox *.o *.h.gch
