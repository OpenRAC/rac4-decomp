#include "common.h"

extern s32 func_L00_005BC980(void *p);
extern s32 func_L01_0056CCC8();
extern s32 func_L01_0056D748();
extern void func_L01_0056CE60();
extern s32 D_24AD00[];

// Start a lookup through the object's list and act on the result found.
void func_L01_0056D030(u8 *arg0) {
    u8 *q;
    s32 *d;

    if (arg0 != 0) {
        q = arg0 + 0x1D0;
        if (func_L00_005BC980(arg0 + 0x1F4) != 0) {
            if (q[0x12] != 0) {
                if (*(s32 *)(arg0 + 0x110) > 0) {
                    d = D_24AD00;
                    d[0] = 0;
                    d[1] = 0;
                    d[3] = (s32)arg0;
                    if (func_L01_0056D748(arg0 + 0xD0, func_L01_0056CE60, d) != 0) {
                        if (d[1] != 0) {
                            func_L01_0056CCC8(arg0, d[1], 0);
                        }
                    }
                }
            }
        }
    }
}
