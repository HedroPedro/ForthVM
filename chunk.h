#ifndef CHUNK_H_
#define CHUNK_H_
#include "common.h"
#include "memory.h"

typedef enum {
    OP_RETURN,
    OP_CALL,
    OP_JFALSE,
    OP_JTRUE,
    OP_PUSH,
    OP_POP,
    OP_ADD,
    OP_SUB,
    OP_DIV,
    OP_MUL,
    OP_MOD,
    OP_SHL,
    OP_SHR,
    OP_AND,
    OP_OR,
    OP_XOR,
    OP_EQ,
    OP_NEQ,
    OP_GE,
    OP_GEQ,
    OP_LE,
    OP_LEQ,
    OP_DUP,
    OP_OVER,
    OP_SWAP,
    OP_ROT,
    OP_READ,
    OP_WRITE,
    AMOUNT_OF_OP
} opcode_e;

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