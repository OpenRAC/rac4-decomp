#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004C57C0(void);
extern void func_004C5910(void);
extern void func_004C59A0(void);

s32 D_00222924 = 0;
s32 D_00222928 = 0;
s32 D_0022292C = 0;
s32 D_00222930 = 0;
extern u8 D_00311670[];
extern u8 D_00311688[];
extern u8 D_003116A0[];
extern u8 D_003116B8[];
extern WordTable4 D_0021F2A8;

// On first use register the four blocks D_00311670, D_00311688, D_003116A0 and
// D_003116B8 through func_00501458 (with the callbacks func_004C57C0,
// func_004C5910, func_004C59A0), each guarded by its own flag, then return word
// index of the table D_0021F2A8.
s32 func_L00_0064D4F0(s32 index) {
    WordTable4 copy;
    if (D_00222924 == 0) {
        func_00501458(D_00311670, (void *)func_004C57C0, (void *)func_004C5910,
                      (void *)func_004C59A0, 0, 0);
        D_00222924 = 1;
    }
    if (D_00222928 == 0) {
        func_00501458(D_00311688, (void *)func_004C57C0, (void *)func_004C5910,
                      (void *)func_004C59A0, 0, 0);
        D_00222928 = 1;
    }
    if (D_0022292C == 0) {
        func_00501458(D_003116A0, (void *)func_004C57C0, (void *)func_004C5910,
                      (void *)func_004C59A0, 0, 0);
        D_0022292C = 1;
    }
    if (D_00222930 == 0) {
        func_00501458(D_003116B8, (void *)func_004C57C0, (void *)func_004C5910,
                      (void *)func_004C59A0, 0, 0);
        D_00222930 = 1;
    }
    copy = D_0021F2A8;
    return copy.f0[index];
}
