#ifndef CHUNK_H_
#define CHUNK_H_
#include "common.h"
#include "memory.h"

typedef enum {
    OP_RETURN,
    OP_CALL,
    OP_JZERO,
    OP_JTRUE,
    OP_PUSH,
    OP_ADD,
    OP_SUB,
    OP_DIV,
    OP_MUL,
    OP_MOD,
    OP_AND,
    OP_OR,
    OP_XOR,
    OP_DUP,
    OP_SWAP,
    OP_ROT,
    OP_READ,
    OP_WRITE,
} opcode_e;

typedef struct {
    int count;
    int capacity;
    uint8_t *codes;
} chunk_t;

void chunk_init(chunk_t *chunk);
void chunk_write(chunk_t *chunk, uint8_t byte);
void chunk_free(chunk_t *chunk);
#endif