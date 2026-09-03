#ifndef DISSASEMBLE_H_
#define DISSASEMBLE_H_
#include "common.h"
#include "chunk.h"

void disassemble_chunk(chunk_t *chunk, const char *name);
int disassemble_instruction(chunk_t *chunk, int offset);

#endif