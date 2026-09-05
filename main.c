#include "main.h"

int main(int argc, const char *argv[]) {
    value_t val = {OP_RETURN, CODE};
    chunk_t chunk;
    chunk_init(&chunk);
    chunk_write(&chunk, &val);
    val.code = OP_PUSH;
    chunk_write(&chunk, &val);
    val.w = 5;
    val.type = WORD;
    chunk_write(&chunk, &val);
    val.code = OP_JFALSE;
    val.type = CODE;
    chunk_write(&chunk, &val);
    val.a = 12;
    val.type = ADDRESS;
    chunk_write(&chunk, &val);
    disassemble_chunk(&chunk, "Test");
    chunk_free(&chunk);
}