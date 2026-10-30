#include "common.h"

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_308108[];

// When the two flags are clear and set, ORs 0xC into the word at 0x98 of D_308108 and every 0xB8 bytes after it, twice.
void func_004A90A0(void) {
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        s32 i = 1;
        u8 *base = D_308108;
        u8 *p = base + 0x98;
        do {
            i -= 1;
            *(s32 *)p = *(s32 *)p | 0xC;
            p += 0xB8;
        } while (i >= 0);
    }
}
