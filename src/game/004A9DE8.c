#include "common.h"

typedef struct {
    s16 f0;
    s16 f2;
    s32 f4;
    u8 pad8[0x14];
} Type1;
typedef struct {
    u8 pad0[4];
    u8 f4;
    u8 f5;
    u8 pad6[0xA];
} Type2;

extern s32 func_00498918(s32, s32);
extern Type1 D_308460[];
extern Type2 D_003D1848[];

/* Passes entry arg0's word at +4 (or, when negative, its D_003D1848 record's byte at +4) and that record's byte at +5 to func_00498918. */
s32 func_004A9DE8(s32 arg0) {
    s32 v = D_308460[arg0].f4;
    if (v < 0) {
        v = ((Type2 *)((D_308460[arg0].f0 << 4) + (s32)D_003D1848))->f4;
    }
    return func_00498918(v, ((Type2 *)((D_308460[arg0].f0 << 4) + (s32)D_003D1848))->f5);
}
