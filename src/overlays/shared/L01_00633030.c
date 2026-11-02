#include "common.h"

extern u8 D_0020FF08[];
s32 func_L01_00633030(s32 arg0)
{ D_0020FF08[arg0] |= 1; return (s32)D_0020FF08; }
