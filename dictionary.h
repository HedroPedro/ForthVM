#ifndef DICT_H_
#define DICT_H_
#include "common.h"
#include "chunk.h"
#define MAX_ENTRIES 256

typedef struct {
    bool is_set;
    address start;
} dictionary_t;

void dict_init(dictionary_t *dict, size_t size);
address dict_get_address(dictionary_t *dict, word id);
#endif