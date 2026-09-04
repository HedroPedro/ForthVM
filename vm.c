#include "vm.h"

vm_t vm;

void static reset_stacks() {
    vm.data_stack_top = vm.data_stack;
    vm.return_stack_top = vm.return_stack;
}

void vm_init() {
    chunk_init(vm.chunk);
    dict_init(vm.dict, MAX_ENTRIES);
    reset_stacks();
}

void vm_free() {
    chunk_free(vm.chunk);
}

static word peek() {
    return *vm.data_stack_top;
}

static address read_address() {
    address ad = vm.chunk->codes[vm.pc];
    vm.pc += ADDRESS_SIZE;
    return ad;
}

static word read_number() {
    word w = vm.chunk->codes[vm.pc];
    vm.pc += WORD_SIZE;
    return w;
}

static interpret_result_e run() {
    #define READ_BYTE() (vm.chunk->codes[vm.pc++])
    #define COMP_OP(op) do {  \
        ad = read_address();    \
        a = pop_data_stack();  \
        if (op ad) vm.pc = ad; \
    } while(false)
    #define BINARY_OP(op) do {    \
        a = pop_data_stack();\
        b = pop_data_stack();\
        push_data_stack(a op b);  \
    } while (false)
    word a, b, c, id;
    address ad;
    
    uint8_t instruction;
    for (;;) {
        instruction = READ_BYTE();
        switch (instruction) {
            case OP_RETURN:
                ad = pop_return_stack();
                vm.pc = ad;
                break;
            case OP_CALL:
                id = read_number();
                push_return_stack(vm.pc);
                vm.pc = dict_get_address(vm.dict, id);
                break;
            case OP_JFALSE:
                COMP_OP(!);
                break;
            case OP_JTRUE:
                COMP_OP();
                break;
            case OP_PUSH:
                push_data_stack(read_number());
                break;
            case OP_POP:
                a = pop_data_stack();
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
            case OP_SHL:
                BINARY_OP(>>);
                break;
            case OP_SHR:
                BINARY_OP(<<);
                break;
            case OP_AND:
                BINARY_OP(&);
                break;
            case OP_OR:
                BINARY_OP(|);
            case OP_XOR:
                BINARY_OP(^);
                break;
            case OP_EQ:
                BINARY_OP(==);
                break;
            case OP_NEQ:
                BINARY_OP(!=);
                break;
            case OP_GE:
                BINARY_OP(>);
                break;
            case OP_GEQ:
                BINARY_OP(>=);
                break;
            case OP_LE:
                BINARY_OP(<);
                break;
            case OP_LEQ:
                BINARY_OP(<=);
                break;
            case OP_DUP:
                push_data_stack(peek());
                break;
            case OP_OVER:
                a = *(vm.data_stack_top-2);
                push_data_stack(a);
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
                fprintf(stderr, "Bytecode value %04d not known\n", instruction);
                return INTERPRET_RUNTIME_ERROR;
        }
    }

    #undef COMP_OP
    #undef BINARY_OP
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
