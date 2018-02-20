//
// Created by Eirik Vale Aase on 20.02.2018.
//

#include <stdio.h>

#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    // We'll let disassembleInstruction increment i because
    // instructions can have different sizes, so we can't make
    // any assumptions.
    for (int i = 0; i < chunk->count;) {
        i = disassembleInstruction(chunk, i);
    }
}

// A constant instruction is a bit more involved than a return statement.
// We must advance two bytes since the instruction has an opcode (1 byte)
// and an operand (1 byte).
static int constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

// A return statement is pretty simple.
// Return offset + 1 because we must advance 1 byte, which is the opcode.
static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);

    // If the next instruction is on the same line as the previous one, print a '|'.
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        printf("    | ");
    } else {
        printf("%04d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            // We don't recognize this opcode, so return the next byte.
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
