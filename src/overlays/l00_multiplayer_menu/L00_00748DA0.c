#include "common.h"

extern s32 D_002232D0;
extern s32 D_002233A4;
extern s32 func_0011AB04(u8 *);
extern void *func_L00_0077C380(s32, s32);

/* Pick a valid object pointer or a default and store it at +0x260. */
void func_L00_00748DA0(u8 *obj) {
    u8 *p;
    s32 v;

    p = func_L00_0077C380(*(s32 *)((u8 *)D_002233A4 + 0x68), 0);
    if (p == 0) {
        v = D_002232D0;
    } else {
        if ((u32)func_0011AB04(p) >= 0x2801) {
            v = D_002232D0;
        } else {
            *(s32 *)(obj + 0x260) = (s32)p;
            return;
        }
    }
    *(s32 *)(obj + 0x260) = v;
}
