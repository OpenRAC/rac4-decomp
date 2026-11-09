/* Not matching yet: EXACT bytes, but the {2,3,4,5} initialiser constant gcc emits lands at 0x21F1B0 instead of retail's D_0021F1B8 (audit_relocs mismatch) (tools/try_func.py func_0046A360 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 b[4];
} Type1;

extern void func_0046A510(s32);
s32 D_0021F1A8 = 0;
s32 D_0021F1AC = 0;
extern u8 D_001F87F0[];

void func_0046A360(void) {
    u8 copy[4] = { 2, 3, 4, 5 };
    s32 mask;
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    s32 byte;
    s32 was;

    mask = 0;
    for (i = 0; i < 4; i++) {
        byte = D_001F87F0[copy[i] * 12 + 8];
        if ((byte >> 1) & 1) {
            mask |= 1 << i;
        }
    }
    D_0021F1A8 = 0;
    for (j = 1; j < 16; j++) {
        p = &D_001F87F0[((j - 1) % 20) * 0x304];
        was = p[0x300];
        was >>= 1;
        was &= 1;
        func_0046A510(j);
        if (!was) {
            byte = p[0x300];
            if ((byte >> 1) & 1) {
                D_0021F1A8 |= 1 << j;
            }
        }
    }
    func_0046A510(1);
    D_0021F1AC = 0;
    for (k = 0; k < 4; k++) {
        if (((mask >> k) ^ 1) & 1) {
            byte = D_001F87F0[copy[k] * 12 + 8];
            if ((byte >> 1) & 1) {
                D_0021F1AC |= 1 << k;
            }
        }
    }
}
