#include <stdlib.h>

#include "common.h"
#include "memory.h"


void* reallocate(void* previous, size_t oldSize, size_t newSize) {
	// Realloc will try to take the pointer previous and extend it to the size
	// given by newSize.
	return realloc(previous, newSize);
}

