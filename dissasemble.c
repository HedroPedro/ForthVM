#include "dissasemble.h"

static int simple_instruction(const char *name, int offset) {
    printf("%s\n", name);
    return offset+1;
}

static int constant_instruction(const char *name, int offset, chunk_t *chunk) {
    printf("%s %04d\n", name, (word) chunk->codes[offset+1]);
    return offset+1+sizeof(word);
}

static int long_constant_instruction(const char *name, int offset, chunk_t *chunk) {
    printf("%s %04d\n", name, (uint32_t) chunk->codes[offset+1]);
    return offset+1+sizeof(uint32_t);
}

void disassemble_chunk(chunk_t *chunk, const char *name) {
    printf("== %s ==\n", name);
    for (int offset = 0; offset < chunk->count;) {
        offset = disassemble_instruction(chunk, offset);
    }
}

int disassemble_instruction(chunk_t *chunk, int offset) {
    printf("%04d ", offset);
    uint8_t byte = chunk->codes[offset];
    switch (byte) {
        case OP_RETURN:
            return simple_instruction(STR(OP_RETURN), offset);
        case OP_ADD:
            return simple_instruction(STR(OP_ADD), offset);
        case OP_SUB:
            return simple_instruction(STR(OP_SUB), offset);
        case OP_DIV:
            return simple_instruction(STR(OP_DIV), offset);
        case OP_MUL:
            return simple_instruction(STR(OP_MUL), offset);
        case OP_READ:
            return simple_instruction(STR(OP_READ), offset);
        case OP_PUSH:
            return constant_instruction(STR(OP_PUSH), offset, chunk);
    }
    fputs("Unknow OPCODE\n", stderr);
    return offset + 1;
}
