#ifndef CHUNK_H_
#define CHUNK_H_
#include "common.h"
#include "memory.h"
#include "instruction.h"

typedef enum {
    CODE,
    WORD,
    ADDRESS,
} value_e;

typedef struct {
    int count;
    int capacity;
    uint8_t *codes;
} chunk_t;

typedef struct {
    union {
        uint8_t code;
        address a;
        word w;
    };
    uint8_t type;
} value_t;

void chunk_init(chunk_t *chunk);
void chunk_write(chunk_t *chunk, value_t *byte);
void chunk_free(chunk_t *chunk);
#endif