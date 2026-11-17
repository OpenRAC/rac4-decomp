#include "common.h"

extern s32 func_004E1F90(s32 arg0, s32 arg1, void *arg2);

typedef struct Type1 {
    u16 f0;
    u16 f2;
} Type1;

typedef struct Type2 {
    u8 pad0[0x12];
    u8 f12;
    u8 pad13;
    Type1 *f14;
} Type2;

typedef struct Type3 {
    u8 pad0[0xC];
    u8 fC;
    u8 padD[0x48 - 0xD];
    Type2 *f48[1];
} Type3;

/* Calls func_004E1F90 for each entry of an object's table whose key is at or above the limit. */
void func_0047BF48(u8 *arg0, s32 arg1, u16 arg2) {
    Type3 *t;
    Type2 *s2;
    Type1 *list;
    s32 i;

    t = *(Type3 **)(arg0 + 0x24);
    if (t != 0 && arg1 < t->fC) {
        s2 = t->f48[arg1];
        if (s2->f12 != 0) {
            list = s2->f14;
            for (i = 0; i < s2->f12 && (arg2 << 4) >= list[i].f2; i++) {
                func_004E1F90(list[i].f0, 0, arg0);
            }
        }
    }
}
