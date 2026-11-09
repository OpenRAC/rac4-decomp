#include "common.h"

typedef struct {
    u32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    u8 fE[2];
} Type0;

extern void func_001587E0(s32 arg0);
extern void func_00158920(s32 arg0, void *arg1, u64 arg2);
extern void func_001592D8(s32 arg0);
extern void func_00159308(s32 arg0);
extern void func_00159338(s32 arg0, void *arg1, u64 arg2);
extern void func_00159368(s32 arg0, void *arg1, u64 arg2);
extern void func_00159398(s32 arg0, void *arg1, u64 arg2);
extern s32 func_00453508(void *arg0);
extern s32 D_0021EDD4;
extern char func_00489C88[];
extern void func_00489E28(void);
extern void func_00489E68(void);
extern void func_00489E80(void);

void func_004894D8(Type0 *arg0) {
    s16 state;
    u32 h;
    u32 a;
    u64 p;

    state = arg0->fA;
    if (state != 9 && (h = arg0->f0) != 0 && h != 0xFFFFFFFF) {
        if (state == 5) {
            if (h == 0) {
                arg0->fA = 0;
            } else {
                func_001587E0(h);
                arg0->fA = 6;
            }
        } else if (state == 6) {
            if (h == 0) {
                arg0->fA = 0;
            } else {
                func_001587E0(h);
            }
        }
        if (arg0->f0 != 0) {
            if (arg0->fC & 0x8000) {
                if (!(arg0->fA & 0x8000)) {
                    func_001592D8(arg0->f0);
                    arg0->fA |= 0x8000;
                }
                if (func_00453508(arg0->fE) == 2) {
                    arg0->fC = 4;
                }
            } else if (arg0->fA & 0x8000) {
                func_00159308(arg0->f0);
                arg0->fA ^= 0x8000;
            }
            if (!(arg0->fA & 0x8000) && arg0->fA != 1 && arg0->fA != 8 && arg0->fA != 9) {
                if ((u16)(arg0->fA - 2) >= 2) {
                    a = arg0->f0;
                    arg0->f0 = 0xFFFFFFFF;
                    p = (u32)arg0;
                    func_00159338(a, func_00489E68, p);
                    func_00159368(a, func_00489E80, p);
                    func_00158920(a, func_00489E28, p);
                } else if (arg0->f0 != 0xFFFFFFFF && arg0->fA == 2) {
                    func_00159398(arg0->f0, func_00489C88 + 8, (u32)arg0);
                }
            } else if (D_0021EDD4 == 1 && arg0->fA == 8) {
                u32 b = arg0->f0;
                arg0->f0 = 0xFFFFFFFF;
                func_00158920(b, func_00489E28, (u32)arg0);
            }
        }
    } else if (state == 7 || arg0->f0 == 0) {
        arg0->fA = 0;
    }
    if (arg0->fA == 0) {
        arg0->f4 = -1;
    }
}
