/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_L00_005DD4A0(void *);
extern void func_L01_003D0838(void *);
extern u32 func_L01_003D09F8(u32 arg0);
extern s32 D_0021E824[];
extern s32 D_0021E828[];

// Either hands the object to func_L00_005DD4A0 or refreshes four halfwords from the state words.
void func_L01_003D0A00(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0xAC);
    u32 *src;
    s16 *dst;
    s32 n;

    if ((D_0021E824[0] == 0 && D_0021E828[0] == 1 && state[0x90] == D_0021E828[0])
        || (!(D_0021E824[0] == 0 && D_0021E828[0] == 1) && state[0x90] == 2)) {
        func_L00_005DD4A0(arg0);
        return;
    }
    arg0[0x30] = 0xFF;
    dst = (s16 *)(state + 0x84);
    src = (u32 *)(state + 0x50);
    n = 3;
    do {
        n -= 1;
        *dst = func_L01_003D09F8(*src);
        src++;
        dst++;
    } while (n >= 0);
    func_L01_003D0838(arg0);
    state[0x96] = 0;
}
