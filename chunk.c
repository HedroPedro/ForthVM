#include "chunk.h"

void chunk_init(chunk_t *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->codes = NULL;
}

void chunk_write(chunk_t *chunk, value_t *byte) {
    #define WRITE(value, total, code, index) do {\
        if (index + sizeof(value) >= total) { \
            int old_capacity = total; \
            total = GROW_CAPACITY(old_capacity); \
            code = GROW_ARRAY(uint8_t, total, old_capacity, code); \
        } \
        memcpy((code + index), &value, sizeof(value)); \
        index += sizeof(value); \
    } while(false)
    switch (byte->type) {
    case CODE:
        WRITE(byte->code, chunk->capacity, chunk->codes, chunk->count);
        break;
    case WORD:
        WRITE(byte->w, chunk->capacity, chunk->codes, chunk->count);
        break;
    case ADDRESS:
        WRITE(byte->a, chunk->capacity, chunk->codes, chunk->count);
        break;
    default:
        fputs("Unknown value type\n", stderr);
        exit(1);
    }
    #undef WRITE
}

void chunk_free(chunk_t *chunk) {
    FREE_ARRAY(uint8_t, chunk->capacity, chunk->codes);
    chunk_init(chunk);
}
