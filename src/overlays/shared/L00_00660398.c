#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D8598(void);
extern void func_004D8658(void);
extern void func_004D86B0(void);

s32 D_00222BA4 = 0;
s32 D_00222BA8 = 0;
s32 D_00222BAC = 0;
s32 D_00222BB0 = 0;
extern u8 D_00325EE8[];
extern u8 D_00325F00[];
extern u8 D_00325F18[];
extern u8 D_00325F30[];
extern WordTable4 D_0021F4F0;

// On first use register the four blocks D_00325EE8, D_00325F00, D_00325F18 and
// D_00325F30 through func_00501458 (with the callbacks func_004D8598,
// func_004D8658, func_004D86B0), each guarded by its own flag, then return word
// index of the table D_0021F4F0.
s32 func_L00_00660398(s32 index) {
    WordTable4 copy;
    if (D_00222BA4 == 0) {
        func_00501458(D_00325EE8, (void *)func_004D8598, (void *)func_004D8658,
                      (void *)func_004D86B0, 0, 0);
        D_00222BA4 = 1;
    }
    if (D_00222BA8 == 0) {
        func_00501458(D_00325F00, (void *)func_004D8598, (void *)func_004D8658,
                      (void *)func_004D86B0, 0, 0);
        D_00222BA8 = 1;
    }
    if (D_00222BAC == 0) {
        func_00501458(D_00325F18, (void *)func_004D8598, (void *)func_004D8658,
                      (void *)func_004D86B0, 0, 0);
        D_00222BAC = 1;
    }
    if (D_00222BB0 == 0) {
        func_00501458(D_00325F30, (void *)func_004D8598, (void *)func_004D8658,
                      (void *)func_004D86B0, 0, 0);
        D_00222BB0 = 1;
    }
    copy = D_0021F4F0;
    return copy.f0[index];
}
