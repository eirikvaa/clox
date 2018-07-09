//
// Created by Eirik Vale Aase on 19.05.2018.
//

#ifndef clox_compiler_h
#define clox_compiler_h

#include "chunk.h"

bool compile(const char *source, Chunk *chunk);

#endif //clox_compiler_h
