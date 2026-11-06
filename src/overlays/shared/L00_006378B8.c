#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004AFC80(void);
extern void func_004AFCC8(void);
extern void func_004AFD20(void);

s32 D_0022277C = 0;
s32 D_00222780 = 0;
s32 D_00222784 = 0;
s32 D_00222788 = 0;
extern u8 D_0030F298[];
extern u8 D_0030F2B0[];
extern u8 D_0030F2C8[];
extern u8 D_0030F2E0[];
extern WordTable4 D_0021F030;

// On first use register the four blocks D_0030F298, D_0030F2B0, D_0030F2C8 and
// D_0030F2E0 through func_00501458 (with the callbacks func_004AFC80,
// func_004AFCC8, func_004AFD20), each guarded by its own flag, then return word
// index of the table D_0021F030.
s32 func_L00_006378B8(s32 index) {
    WordTable4 copy;
    if (D_0022277C == 0) {
        func_00501458(D_0030F298, (void *)func_004AFC80, (void *)func_004AFCC8,
                      (void *)func_004AFD20, 0, 0);
        D_0022277C = 1;
    }
    if (D_00222780 == 0) {
        func_00501458(D_0030F2B0, (void *)func_004AFC80, (void *)func_004AFCC8,
                      (void *)func_004AFD20, 0, 0);
        D_00222780 = 1;
    }
    if (D_00222784 == 0) {
        func_00501458(D_0030F2C8, (void *)func_004AFC80, (void *)func_004AFCC8,
                      (void *)func_004AFD20, 0, 0);
        D_00222784 = 1;
    }
    if (D_00222788 == 0) {
        func_00501458(D_0030F2E0, (void *)func_004AFC80, (void *)func_004AFCC8,
                      (void *)func_004AFD20, 0, 0);
        D_00222788 = 1;
    }
    copy = D_0021F030;
    return copy.f0[index];
}
