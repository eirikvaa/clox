#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// This controls what kind of operation we're dealing with.
typedef enum {
	OP_CONSTANT,
	OP_NIL,
	OP_TRUE,
	OP_FALSE,
	OP_EQUAL,
	OP_GREATER,
	OP_LESS,
	OP_NEGATE,
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_NOT,
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
	int* lines;
	ValueArray constants; // Constants pool - where all constants will live.
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
