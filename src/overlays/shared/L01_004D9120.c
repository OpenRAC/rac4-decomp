/* cflags: -mno-split-addresses */
#include "common.h"

extern u32 D_222D14;
extern u32 D_222D2C;
extern void *func_L00_005DEBD0(s32, s32, s32);
extern void func_00585D88(void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

/* Adds each entry from D_222D14 up to D_222D2C that passes the func_L00_005DEBD0 test to the list at +0x6C, then runs two calls. */
void func_L01_004D9120(u8 *arg0)
{
    u8 *obj;
    u32 list;
    u32 cur;
    u32 lim;
    s32 n;

    obj = *(u8 **)(arg0 + 0xAC);
    *(s32 *)(obj + 0x8C) = 0;
    list = (u32)(obj + 0x6C);
    cur = D_222D14;
    if (cur < D_222D2C) {
        for (;;) {
            if (func_L00_005DEBD0(*(s16 *)(cur + 0xBC), 5, 0x10) != 0) {
                n = *(s32 *)(obj + 0x8C);
                *(u32 *)(list + (n << 2)) = cur;
                *(s32 *)(obj + 0x8C) = n + 1;
                lim = D_222D2C;
            } else {
                lim = D_222D2C;
            }
            cur += 0x100;
            if (!(cur < lim)) {
                break;
            }
        }
    }
    func_00585D88(arg0);
    func_L01_00591BD8(arg0, 1, -1);
}
