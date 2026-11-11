#include "common.h"

typedef struct {
    u8 padding[0x1C];
    u8 *target;
} Entry;

extern Entry *D_00222990;

void func_L01_00524548(s32 index)
{
    D_00222990[index].target[0xB2] = 0;
}
