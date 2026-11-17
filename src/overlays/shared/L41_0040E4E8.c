#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[0x10];
} Type1;

extern Type1 D_375B50[][4];

// True when the entry's word at offset 4 is zero.
s32 func_L41_0040E4E8(s32 arg0, s32 arg1) {
    return D_375B50[arg0][arg1].f4 == 0;
}
