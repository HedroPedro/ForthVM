#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_
typedef enum {
    OP_RETURN,
    OP_CALL,
    OP_JFALSE,
    OP_JTRUE,
    OP_JUMP,
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
    OP_NOT,
    OP_NEG,
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

#endif