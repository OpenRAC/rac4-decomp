/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_0011A9EC(void *, void *);
extern s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s8 D_00169CF8[];
extern s8 D_00169D10[];
extern s32 D_1BC8C4[];
extern s32 D_1BC8C8[];
extern s32 D_1BCABC[];
extern s32 D_1BCAC0[];

/* Sets the flags of the object at arg0, stores arg1 and arg2 in the slot its link selects, then runs func_01ED5DD0. */
s32 func_01ED7420(s8 *arg0, s32 arg1, s32 arg2)
{
    s32 cur;
    s32 link;

    arg0[0x14] = 0;
    arg0[0x25] = 0;
    cur = D_00169CD0;
    if (cur != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    if (arg0[0] == 0) {
        return -0x15;
    }
    link = *(s32 *)(arg0 + 0x28);
    if (link == 0) {
        goto slot_a;
    }
    if (link == cur) {
        goto slot_b;
    }
    return -0x15;
slot_a:
    if (func_0011A8A0((char *)arg0, (char *)D_00169D10) == 0) {
        return -0x15;
    }
    func_0011A9EC(D_00169CF8, arg0);
    D_1BCABC[0] = arg1;
    D_1BC8C4[0] = arg2;
    goto tail;
slot_b:
    if (func_0011A8A0((char *)arg0, (char *)D_00169CF8) == 0) {
        return -0x15;
    }
    func_0011A9EC(D_00169D10, arg0);
    D_1BCAC0[0] = arg1;
    D_1BC8C8[0] = arg2;
tail:
    return func_01ED5DD0(1, 0x47, 0x2C, (s32)arg0) == 0 ? 0 : -5;
}
