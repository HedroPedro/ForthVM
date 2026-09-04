#include "chunk.h"

void chunk_init(chunk_t *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->codes = NULL;
}

void chunk_write(chunk_t *chunk, value_t *byte) {
    switch (byte->type) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }
}

void chunk_free(chunk_t *chunk) {
    FREE_ARRAY(uint8_t, chunk->capacity, chunk->codes);
    chunk_init(chunk);
}
