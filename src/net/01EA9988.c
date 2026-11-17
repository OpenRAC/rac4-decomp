/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 mt[625]; s32 mti; } MT;
extern MT D_001681B0;
void func_01EA9988(u32 seed) {
    s32 i;
    u32 *p = D_001681B0.mt;
    seed |= 1;
    D_001681B0.mti = 0x26F;
    *p++ = seed;
    for (i = 0x26F; i != 0; i--) {
        seed *= 69069;
        *p++ = seed;
    }
}
