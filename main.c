#include "main.h"

int main(int argc, const char *argv[]) {
    chunk_t chunk;
    chunk_init(&chunk);
    value_t val = {OP_RETURN, 0};

    disassemble_chunk(&chunk, "Test");
    chunk_free(&chunk);
}