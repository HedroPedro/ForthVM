#ifndef COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/mman.h>
#define WORD_SIZE sizeof(word)
#define AMOUNT_OF_WORDS (256)
#define STACK_SIZE (WORD_SIZE*AMOUNT_OF_WORDS)
#define STR(x) (#x)
typedef uint8_t word;


#endif