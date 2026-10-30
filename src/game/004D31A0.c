#include "common.h"

extern void func_004D3148(s32 *arg0, s32 arg1);
extern u8 D_003D9BE0[];

/* Copy the word at D_003D9BE0 + 8 into the three words after it, advancing it by 0x800 each time, then call func_004D3148. */
void func_004D31A0(void) {
    u8 *base = D_003D9BE0;
    s32 n = 3;
    s32 *p = (s32 *)(base + 0xC);

    do {
        n--;
        *p = *(s32 *)(base + 8);
        p++;
        *(s32 *)(base + 8) = *(s32 *)(base + 8) + 0x800;
    } while (n >= 0);
    func_004D3148(p, n);
}
