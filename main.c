#include "main.h"

int main(int argc, const char *argv[]) {
    chunk_t chunk;
    chunk_init(&chunk);
    chunk_write(&chunk, OP_RETURN);
    chunk_write(&chunk, OP_PUSH);
    chunk_write(&chunk, 10);
    disassemble_chunk(&chunk, "Test");
    chunk_free(&chunk);
}