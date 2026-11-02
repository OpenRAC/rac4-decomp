#include "common.h"

typedef struct Type1 {
    s32 f0, f4;
    char pad8[0x4C];
} Type1;
extern Type1 D_002F33B8[];

/* Store the indexed record's mode. */
void func_00498590(s32 index, s32 mode)
{
    D_002F33B8[index].f4 = mode;
}
