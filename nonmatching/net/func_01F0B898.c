/* Not matching yet: BYTES 3/168 (tools/try_func.py func_01F0B898 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

extern u8 D_0019E698[];
extern void func_01F0C090(void *, s32);

typedef struct {
    char pad0[0xC0];
    s32 *unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
} Thing;

s32 func_01F0B898(Thing *arg0)
{
    if (arg0->unkCC > arg0->unkC4) {
        func_01F0C090(D_0019E698, 0x223);
    }
    if (arg0->unkD0 < arg0->unkD4) {
        func_01F0C090(D_0019E698, 0x224);
    }
    if (arg0->unkD0 >= arg0->unkD4 + arg0->unkC8) {
        func_01F0C090(D_0019E698, 0x225);
    }
    return *(s32 *)((u8 *)arg0->unkC0 + (arg0->unkD0 << 2));
}
