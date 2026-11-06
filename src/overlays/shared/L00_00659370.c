#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D1708(void);
extern void func_004D1960(void);
extern void func_004D1A18(void);

s32 D_00222A3C = 0;
s32 D_00222A40 = 0;
s32 D_00222A44 = 0;
s32 D_00222A48 = 0;
extern u8 D_00320DF0[];
extern u8 D_00320E08[];
extern u8 D_00320E20[];
extern u8 D_00320E38[];
extern WordTable4 D_0021F3D0;

// On first use register the four blocks D_00320DF0, D_00320E08, D_00320E20 and
// D_00320E38 through func_00501458 (with the callbacks func_004D1708,
// func_004D1960, func_004D1A18), each guarded by its own flag, then return word
// index of the table D_0021F3D0.
s32 func_L00_00659370(s32 index) {
    WordTable4 copy;
    if (D_00222A3C == 0) {
        func_00501458(D_00320DF0, (void *)func_004D1708, (void *)func_004D1960,
                      (void *)func_004D1A18, 0, 0);
        D_00222A3C = 1;
    }
    if (D_00222A40 == 0) {
        func_00501458(D_00320E08, (void *)func_004D1708, (void *)func_004D1960,
                      (void *)func_004D1A18, 0, 0);
        D_00222A40 = 1;
    }
    if (D_00222A44 == 0) {
        func_00501458(D_00320E20, (void *)func_004D1708, (void *)func_004D1960,
                      (void *)func_004D1A18, 0, 0);
        D_00222A44 = 1;
    }
    if (D_00222A48 == 0) {
        func_00501458(D_00320E38, (void *)func_004D1708, (void *)func_004D1960,
                      (void *)func_004D1A18, 0, 0);
        D_00222A48 = 1;
    }
    copy = D_0021F3D0;
    return copy.f0[index];
}
