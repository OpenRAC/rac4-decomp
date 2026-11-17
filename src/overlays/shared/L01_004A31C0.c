#include "common.h"

extern s32 D_001DFCA0[];
void func_L00_005CD220(s32);

/* Store the new value at +0x684 of the linked object, notifying first if it differs from D_001DFCA0. */
void func_L01_004A31C0(u8 *obj, s32 v) {
    u8 *p = *(u8 **)(obj + 0xAC);
    if (D_001DFCA0[0] != v) {
        func_L00_005CD220(v);
    }
    p[0x684] = v;
}
