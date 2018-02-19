#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// This controls what kind of operation we're dealing with.
typedef enum {
	OP_RETURN,
} OpCode;

// This is data we store along with instructions. This will be dynamic
// since we don't know how much data will be stored along the instructions.
//	count: how many elements are actually in use.
//	capacity: how much storage we've allocated.
typedef struct {
    int count;
	int capacity;
	uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif
