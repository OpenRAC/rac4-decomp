#include "common.h"

extern s32 func_0045E038(s32);

typedef struct {
    u8 pad[0x14];
    s32 f14;
    u8 pad2[0x8];
} Type1;

extern Type1 D_003D8500[];

// Conditional lookup in array and function call
s32 func_0047CE20(u32 arg0) {
    if (arg0 < 0xD) {
        return func_0045E038(D_003D8500[arg0].f14);
    }
    return 0;
}
