/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_0051B4A8();
void func_L00_00526030(void *, s32, void *);
extern s32 D_004A1960[];
extern s32 D_004A1998[];

/* One-time init of the D_004A1960 block, returns D_004A1998. */
s32 *func_L00_00525B70(void) {
    s32 buf[4];
    if (!(D_004A1960[12] & 2)) {
        buf[0] = 2;
        D_004A1960[12] |= 2;
        D_004A1960[6] = (s32)D_004A1960;
        D_004A1960[8] = func_0051B4A8();
        D_004A1960[9] = 0;
        func_L00_00526030(D_004A1998, 0x10, buf);
    }
    return D_004A1998;
}
