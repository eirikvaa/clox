#ifndef clox_memory_h
#define clox_memory_h

#include <stddef.h>

#define GROW_CAPACITY(capacity) \
		((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(previous, type, oldCount, count) \
		(type*)reallocate(previous, sizeof(type) * (oldCount), \
		sizeof(type) * (count))

// Resize the memory down to zero bytes.
#define FREE_ARRAY(type, pointer, oldCount) \
		reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* previous, size_t oldSize, size_t newSize);

#endif
