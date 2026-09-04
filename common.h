#ifndef COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/mman.h>
#define WORD_SIZE sizeof(word)
#define ADDRESS_SIZE sizeof(address)
#define AMOUNT_OF_WORDS (256)
#define STACK_SIZE (4*1024)
#define STR(x) (#x)
typedef int16_t word;
typedef uintptr_t address;

#endif