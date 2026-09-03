#include "vm.h"

vm_t vm;

void static reset_stacks() {
    vm.data_stack_top = vm.data_stack;
    vm.return_stack_top = vm.return_stack;
}

void vm_init() {
    chunk_init(vm.chunk);
    dict_init(vm.dict);
    reset_stacks();
}

void vm_free() {
    chunk_free(vm.chunk);
}

static word peek() {
    return *vm.data_stack_top;
}

static interpret_result_e run() {
    word a, b, c;
    
    #define READ_BYTE() (vm.chunk->codes[vm.pc++])
    #define READ_NUM() (vm.chunk->codes[vm.pc++])
    #define BINARY_OP(op) do {    \
        a = pop_data_stack();\
        b = pop_data_stack();\
        push_data_stack(a op b);  \
    } while (false)
    
    uint8_t instruction;
    for (;;) {
        instruction = READ_BYTE();
        switch (instruction) {
            case OP_RETURN:
                uintptr_t address = pop_return_stack();
                vm.pc = address;
                break;
            case OP_CALL:
                word id = READ_NUM();
                push_return_stack(vm.pc);
                vm.pc = dict_get_address(vm.dict, id);
                break;
            case OP_PUSH:
                push_data_stack(READ_NUM());
                break;
            case OP_ADD:
                BINARY_OP(+);
                break;
            case OP_SUB:
                BINARY_OP(-);
                break;
            case OP_DIV:
                BINARY_OP(/);
                break;
            case OP_MUL:
                BINARY_OP(*);
                break;
            case OP_MOD:
                BINARY_OP(%);
                break;
            case OP_AND:
                BINARY_OP(&);
                break;
            case OP_OR:
                BINARY_OP(|);
            case OP_XOR:
                BINARY_OP(^);
                break;
            case OP_DUP:
                push_data_stack(peek());
                break;
            case OP_ROT:
                a = pop_data_stack();
                b = pop_data_stack();
                c = pop_data_stack();
                push_data_stack(c);
                push_data_stack(a);
                push_data_stack(b);
                break;
            case OP_READ:
                break;
            case OP_WRITE:
                break;
            default:
                return INTERPRET_RUNTIME_ERROR;
        }
    }

    #undef BINARY_OP
    #undef READ_NUM
    #undef READ_BYTE
}

interpret_result_e interpret(chunk_t *chunk) {
    vm.chunk = chunk;
    vm.pc = 0;
    return run();
}

void push_data_stack(word value) {
    *vm.data_stack_top = value;
    vm.data_stack_top++;
}

word pop_data_stack() {
    word value = *vm.data_stack_top;
    --vm.data_stack_top;
    return value;
}

void push_return_stack(uintptr_t offset) {
    *vm.return_stack_top = offset;
    vm.return_stack_top++;
}

uintptr_t pop_return_stack() {
    uintptr_t offset = *vm.return_stack_top;
    vm.return_stack_top--;
    return offset;
}

