/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern void func_01EE68FC(void *, void *, s32);
extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01EEE39C(void);
extern s32 func_01EF4188(void *, s32, s32, s32, void *);
extern void func_01F0C090(const char *, s32);
extern char D_0019D208[];
extern char D_0019D220[];

/* Checks the object and its record, then dispatches it through its handler table. */
s32 func_01EF8F4C(u8 *arg0, u8 *arg1)
{
    s32 temp_s1;
    s32 temp_s2;
    u8 *temp_v0;
    u8 *vt;

    temp_s1 = *(s32 *)(*(u8 **)(arg0 + 0x80) + 4);
    if (*(s32 *)arg0 == 0) {
        func_01F0C090(D_0019D208, 0x5A);
    }
    if (temp_s1 == 0) {
        func_01F0C090(D_0019D208, 0x5B);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019D208, 0x5C);
    }
    if (func_01EED8A4(temp_s1, 0x11, 0x10) != 0) {
        vt = *(u8 **)(arg0 + 0xB0);
        if ((*(s32 (**)(u8 *))(vt + 0x24))(arg0) == 0) {
            vt = *(u8 **)(arg0 + 0xB0);
            if ((*(s32 (**)(u8 *))(vt + 0x20))(arg0) != 0 && *(s32 *)(arg1 + 0x5B10) == 0) {
                if ((s32)arg0 == -0xB4) {
                    func_01F0C090(D_0019D208, 0x63);
                }
                if (*(s8 *)(arg0 + 0xB4) != 0) {
                    func_01EE68FC(arg1, arg0 + 0xB4, 0);
                    temp_v0 = (u8 *)func_01EEE39C();
                    (*(s32 (**)(void *, s32, char *))(*(u8 **)temp_v0 + 0xC))(temp_v0, 1, D_0019D220);
                    return 0;
                }
            }
        }
    }
    vt = *(u8 **)(arg0 + 0xB0);
    if ((*(s32 (**)(u8 *))(vt + 0x20))(arg0) != 0) {
        if (func_01EED8A4(temp_s1, 0x11, 0) != 0 || func_01EED8A4(temp_s1, 0x11, 1) != 0 || func_01EED8A4(temp_s1, 0x11, 2) != 0 || func_01EED8A4(temp_s1, 0x11, 3) != 0) {
            temp_s2 = *(s32 *)*(u8 **)(arg0 + 0x80);
            if (temp_s2 == 0) {
                func_01F0C090(D_0019D208, 0x77);
            }
            return func_01EF4188(arg0, temp_s1, temp_s2, *(s32 *)arg0, arg1) == 0;
        }
        return 1;
    }
    return 1;
}
