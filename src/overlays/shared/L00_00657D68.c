#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D01E8(void);
extern void func_004D03E0(void);
extern void func_004D04A0(void);

s32 D_00222A1C = 0;
s32 D_00222A20 = 0;
s32 D_00222A24 = 0;
s32 D_00222A28 = 0;
extern u8 D_003206D0[];
extern u8 D_003206E8[];
extern u8 D_00320700[];
extern u8 D_00320718[];
extern WordTable4 D_0021F3B0;

// On first use register the four blocks D_003206D0, D_003206E8, D_00320700 and
// D_00320718 through func_00501458 (with the callbacks func_004D01E8,
// func_004D03E0, func_004D04A0), each guarded by its own flag, then return word
// index of the table D_0021F3B0.
s32 func_L00_00657D68(s32 index) {
    WordTable4 copy;
    if (D_00222A1C == 0) {
        func_00501458(D_003206D0, (void *)func_004D01E8, (void *)func_004D03E0,
                      (void *)func_004D04A0, 0, 0);
        D_00222A1C = 1;
    }
    if (D_00222A20 == 0) {
        func_00501458(D_003206E8, (void *)func_004D01E8, (void *)func_004D03E0,
                      (void *)func_004D04A0, 0, 0);
        D_00222A20 = 1;
    }
    if (D_00222A24 == 0) {
        func_00501458(D_00320700, (void *)func_004D01E8, (void *)func_004D03E0,
                      (void *)func_004D04A0, 0, 0);
        D_00222A24 = 1;
    }
    if (D_00222A28 == 0) {
        func_00501458(D_00320718, (void *)func_004D01E8, (void *)func_004D03E0,
                      (void *)func_004D04A0, 0, 0);
        D_00222A28 = 1;
    }
    copy = D_0021F3B0;
    return copy.f0[index];
}
