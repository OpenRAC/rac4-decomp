#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004AD888(void);
extern void func_004AD8E8(void);
extern void func_004AD918(void);

s32 D_0022270C = 0;
s32 D_00222710 = 0;
s32 D_00222714 = 0;
s32 D_00222718 = 0;
extern u8 D_0030EF40[];
extern u8 D_0030EF58[];
extern u8 D_0030EF70[];
extern u8 D_0030EF88[];
extern WordTable4 D_0021EFD0;

// On first use register the four blocks D_0030EF40, D_0030EF58, D_0030EF70 and
// D_0030EF88 through func_00501458 (with the callbacks func_004AD888,
// func_004AD8E8, func_004AD918), each guarded by its own flag, then return word
// index of the table D_0021EFD0.
s32 func_L00_00635510(s32 index) {
    WordTable4 copy;
    if (D_0022270C == 0) {
        func_00501458(D_0030EF40, (void *)func_004AD888, (void *)func_004AD8E8,
                      (void *)func_004AD918, 0, 0);
        D_0022270C = 1;
    }
    if (D_00222710 == 0) {
        func_00501458(D_0030EF58, (void *)func_004AD888, (void *)func_004AD8E8,
                      (void *)func_004AD918, 0, 0);
        D_00222710 = 1;
    }
    if (D_00222714 == 0) {
        func_00501458(D_0030EF70, (void *)func_004AD888, (void *)func_004AD8E8,
                      (void *)func_004AD918, 0, 0);
        D_00222714 = 1;
    }
    if (D_00222718 == 0) {
        func_00501458(D_0030EF88, (void *)func_004AD888, (void *)func_004AD8E8,
                      (void *)func_004AD918, 0, 0);
        D_00222718 = 1;
    }
    copy = D_0021EFD0;
    return copy.f0[index];
}
