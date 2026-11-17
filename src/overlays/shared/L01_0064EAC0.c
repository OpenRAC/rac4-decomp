#include "common.h"

extern s32 D_222D14;
extern s32 D_222D60;
extern u16 *D_28BFE0[];
extern void func_L01_0064EA50(unsigned char *object, s32 arg1);

// Walks the u16 id list of slot arg0 in D_28BFE0, calling func_L01_0064EA50 on each referenced object until a stop condition.
void func_L01_0064EAC0(s32 arg0, s32 arg1) {
    u16 *p;
    s32 low;
    unsigned char *obj;

    if (arg0 == -1 || arg0 == 0xFF) {
        return;
    }
    low = arg0 & 0xFF;
    p = D_28BFE0[arg0];
    if (low == 0xFF || D_222D60 < arg0 || p == 0) {
        return;
    }
    for (;;) {
        obj = (unsigned char *)(D_222D14 + ((*p & 0x7FFF) << 8));
        if (obj == 0) {
            return;
        }
        func_L01_0064EA50(obj, arg1);
        p += 1;
        if (low == 0xFF || D_222D60 < arg0 || p == 0) {
            return;
        }
        if ((s16)p[-1] < 0 && p != D_28BFE0[arg0]) {
            return;
        }
    }
}
