#include "common.h"

s32 func_00454C18(void) {
    s32 x=*(s32*)0x0021DF14;
    return x ? *(s32*)(x-4) : -1;
}
