#ifndef DICT_H_
#define DICT_H_
#include "common.h"
#include "chunk.h"
#define MAX_ENTRIES 256

typedef struct {
    uintptr_t offset;
    word id;
    bool is_set;
} dictionary_t;

void dict_init();
void dict_append(uint32_t id, int offset);
void dict_reset(dictionary_t dict);
#endif