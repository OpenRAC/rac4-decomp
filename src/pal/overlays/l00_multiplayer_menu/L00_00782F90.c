/* cflags: -Wuninitialized */
#include "common.h"

extern u32 D_0021DE54;

/* Mask the word at offset 0x1B4 with the low 16 bits of the third argument. */
unsigned long func_L00_00782F90(long a1, long a2, unsigned short a3)
{
    return *(int *)(D_0021DE54 + 436) & (unsigned long)a3;
}
