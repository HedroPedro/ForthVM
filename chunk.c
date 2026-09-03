#include "chunk.h"

void chunk_init(chunk_t *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->codes = NULL;
}

void chunk_write(chunk_t *chunk, uint8_t byte) {
    if (chunk->count+1 > chunk->capacity) {
        int capacity = GROW_CAPACITY(chunk->capacity);
        chunk->codes = GROW_ARRAY(uint8_t, capacity, chunk->capacity, chunk->codes);
        chunk->capacity = capacity;
    }

    chunk->codes[chunk->count] = byte;
    chunk->count++;
}

void chunk_free(chunk_t *chunk) {
    FREE_ARRAY(uint8_t, chunk->capacity, chunk->codes);
    chunk_init(chunk);
}
