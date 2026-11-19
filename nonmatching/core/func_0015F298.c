/* Not matching yet: BYTES 6/96 (tools/try_func.py func_0015F298 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    u8 pad[0xAD0 - 0x10];
} S1;

extern void func_0015EF88(void *arg0);
extern S1 D_01F31380[];
s32 D_0021DFEC = 0;

void func_0015F298(void) {
    S1 *p;
    S1 *end;

    p = D_01F31380;
    end = p + 10;
    do {
        if (p->fC != 0) {
            D_0021DFEC = D_0021DFEC - 1;
            func_0015EF88(p);
            p->fC = 0;
        }
        p++;
    } while ((s32)p < (s32)end);
}
