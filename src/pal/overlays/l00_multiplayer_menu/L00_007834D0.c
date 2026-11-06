/* cflags: -G0 */
/* Adapted from rac3-decomp src/boot_elf/text/3AACC8.c, commit cd0e7c20fd8a93116566ba2e024fa2f3536bd30c. */
#include "common.h"

extern void func_0015DB98(void *);
extern u8 D_0016FE40[];

// Publish the address at +0x10 and optionally release the object.
void func_L00_007834D0(void *p, s32 flags) {
    *(void **)((u8 *)p + 0x10) = D_0016FE40;
    if (flags & 1)
        func_0015DB98(p);
}
