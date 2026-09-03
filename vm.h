#ifndef VM_H_
#define VM_H_
#include "common.h"
#include "chunk.h"
#include "dictionary.h"

typedef struct {
    uintptr_t  pc;
    chunk_t *chunk;
    word *data_stack_top;
    uintptr_t  *return_stack_top;
    dictionary_t dict[MAX_ENTRIES];   // 256 entries
    uintptr_t   return_stack[STACK_SIZE];  // Absolute offset for return
    word  data_stack[STACK_SIZE];
} vm_t;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} interpret_result_e;

void vm_init();
void vm_free();

void push_data_stack(word value);
word pop_data_stack();
void push_return_stack(uintptr_t offset);
uintptr_t pop_return_stack();
interpret_result_e interpret(chunk_t *chunck);

#endif