#include "common.h"

extern void func_0011A9EC(void *, void *);
extern void func_L00_0070AED0(void);
extern s32 **D_002233A4;
extern s8 D_003F3E78[];
s32 D_00220A44 = 0;
s32 D_00220A48 = 0;
u8 D_00220A5F = 0;

static inline u8 sel_valid(void) {
    s32 sel = D_00220A48;
    if (sel == -1) {
        return 0;
    }
    return D_00220A44 != -1;
}

/* Handles a menu event: on a matching selection, resets the selection state and prints a message. */
s32 func_L00_0070AD48(s32 arg0, s32 *arg1) {
    s32 ret = 2;
    s32 one = 1;
    s32 none;
    s32 *p;

    if (arg0 == one) {
        func_L00_0070AED0();
    } else {
        p = *(s32 **)((u8 *)D_002233A4 + 0x3C);
        none = -1;
        if (*p != none && sel_valid() && arg1[2] == D_00220A48) {
            D_00220A44 = none;
            D_00220A48 = none;
            D_00220A5F = one;
            func_0011A9EC(D_003F3E78, (u8 *)arg1 + 0x1B);
            ret = 0;
        }
    }
    return ret;
}
