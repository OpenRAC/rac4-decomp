/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
/* C adapted from OpenRAC/rac3-decomp func_L03_0034BAF0,
 * src/levels/shared/L03_0034B440.c at cd0e7c20fd8a93116566ba2e024fa2f3536bd30c.
 * See THIRD_PARTY_NOTICES.md for the source's separate legal scope and credits. */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_0026B590[];
extern u8 *func_0046B930(s32, s32);
extern void func_004706F0(u8 *);

u8 *func_L01_004BE3B0(u8 *parent, s32 class_id) {
    u8 *moby;

    if (D_0026B590[class_id] == 255) {
        return NULL;
    }
    if (class_id == 0) {
        return NULL;
    }
    moby = func_0046B930(class_id, 128);
    if (moby != NULL) {
        *(u128 *)(moby + 16) = *(u128 *)(parent + 16);
        *(u128 *)(moby + 240) = *(u128 *)(parent + 240);
        *(s64 *)(moby + 56) = *(s64 *)(parent + 56);
        *(u8 *)(moby + 48) = *(u8 *)(parent + 48);
        *(s16 *)(moby + 50) = *(u8 *)(parent + 48);
        *(u8 **)(moby + 184) = parent;
        *(u8 *)(moby + 49) = 1;
        if (*(s32 *)(moby + 36) != 0) {
            func_004706F0(moby);
        }
        return moby;
    }
    return NULL;
}
