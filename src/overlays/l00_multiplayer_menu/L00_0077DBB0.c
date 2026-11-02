/* cflags: -Wuninitialized */
#include "common.h"

extern u32 D_0021DDCC;

/* Mask the word at offset 0x1B4 with the low 16 bits of the third argument. */
unsigned long func_L00_0077DBB0(long a1, long a2, unsigned short a3)
{
    return *(int *)(D_0021DDCC + 436) & (unsigned long)a3;
}
