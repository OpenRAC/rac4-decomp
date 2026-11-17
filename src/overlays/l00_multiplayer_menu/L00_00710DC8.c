#include "common.h"

extern void func_0069CC48(void *, s32, s32);
extern void func_0069D318(void *, void *);
extern s32 func_0069D408(s32, s32);
extern s32 func_L00_005E6358(s32, s32, s32, s32, s32, s32);

typedef struct T {
    u8 pad0[4];
    s32 f4;
    u8 pad1[0xC];
    void *f14;
    u8 f18[0x44];
    s32 f5C;
} T;

// Apply a color to the object's sub-handle based on its mode.
void func_L00_00710DC8(T *arg0) {
    s32 c;
    s32 a;
    s32 t;
    if (arg0->f4 != 0 && arg0->f14 != 0) {
        c = 0x80D6CBBE;
        func_0069D318(arg0->f14, arg0->f18);
        if (arg0->f4 == 1) {
            func_0069CC48(arg0->f14, 1, 0);
            return;
        }
        func_0069CC48(arg0->f14, 1, 1);
        a = arg0->f5C;
        t = arg0->f4;
        if (a == 0) {
            if (t == 3) {
                c = 0x80808080;
            } else if (t != 4) {
                if (t == 5) {
                    c = func_L00_005E6358(0x80D6CBBE, 0x66A6BEFA, 0x2D, 1, 0, 1);
                } else if (t == 6) {
                    c = 0x66A6BEFA;
                }
            }
        } else if (t == 5) {
            c = func_L00_005E6358(a, 0x66A6BEFA, 0x2D, 1, 0, 1);
        } else {
            c = a;
        }
        func_0069D408((s32)arg0->f14, c);
    }
}
