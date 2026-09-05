#ifndef MEMORY_H_
#define MEMORY_H_
#include "common.h"
#define GROW_CAPACITY(u) (u < 8 ? 8 : (u<<2))
#define GROW_ARRAY(type, new_size, old_size, ptr) \
    (type *) reallocate(ptr, sizeof(type) * old_size, sizeof(type) * new_size)
#define FREE_ARRAY(type, old_size, ptr) \
    reallocate(ptr, sizeof(type) * old_size, 0)
    
void *reallocate(void *ptr, size_t old_size, size_t new_size);
#endif