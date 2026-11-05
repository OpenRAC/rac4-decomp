#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_L00_005C9F50(s32);
extern void func_L00_0070AED0(void);
s32 D_00220A44 = -1;
s32 D_00220A48 = -1;
s8 D_00220A5E = 0;
extern s8 D_003F3E78[];

typedef struct {
    s8 pad[0x3C];
    s32 *f3C;
} Glob;
extern Glob *D_002233A4;

static inline u8 sel_valid(void) {
    if (D_00220A48 == -1) {
        return 0;
    }
    return D_00220A44 != -1;
}

/* Handles a menu event: on a matching selection, resets the selection state and prints a message */
s32 func_L00_0070AC80(s32 arg0, s32 *arg1) {
    s32 ret = 2;
    s32 one = 1;
    s32 *p;
    s32 none;

    if (arg0 == one) {
        func_L00_0070AED0();
    } else {
        p = D_002233A4->f3C;
        none = -1;
        if (*p != none && sel_valid() && arg1[2] == D_00220A48) {
            D_00220A44 = none;
            D_00220A48 = none;
            D_00220A5E = one;
            ret = 0;
            func_0011D920(D_003F3E78, (s8 *)func_L00_005C9F50(0x33E8), (s8 *)arg1 + 0x1B);
        }
    }
    return ret;
}
