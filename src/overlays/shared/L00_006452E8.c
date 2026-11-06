#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004BD5B8(void);
extern void func_004BD6F0(void);
extern void func_004BD780(void);

s32 D_002228BC = 0;
s32 D_002228C0 = 0;
s32 D_002228C4 = 0;
s32 D_002228C8 = 0;
extern u8 D_00310E28[];
extern u8 D_00310E40[];
extern u8 D_00310E58[];
extern u8 D_00310E70[];
extern WordTable4 D_0021F210;

// On first use register the four blocks D_00310E28, D_00310E40, D_00310E58 and
// D_00310E70 through func_00501458 (with the callbacks func_004BD5B8,
// func_004BD6F0, func_004BD780), each guarded by its own flag, then return word
// index of the table D_0021F210.
s32 func_L00_006452E8(s32 index) {
    WordTable4 copy;
    if (D_002228BC == 0) {
        func_00501458(D_00310E28, (void *)func_004BD5B8, (void *)func_004BD6F0,
                      (void *)func_004BD780, 0, 0);
        D_002228BC = 1;
    }
    if (D_002228C0 == 0) {
        func_00501458(D_00310E40, (void *)func_004BD5B8, (void *)func_004BD6F0,
                      (void *)func_004BD780, 0, 0);
        D_002228C0 = 1;
    }
    if (D_002228C4 == 0) {
        func_00501458(D_00310E58, (void *)func_004BD5B8, (void *)func_004BD6F0,
                      (void *)func_004BD780, 0, 0);
        D_002228C4 = 1;
    }
    if (D_002228C8 == 0) {
        func_00501458(D_00310E70, (void *)func_004BD5B8, (void *)func_004BD6F0,
                      (void *)func_004BD780, 0, 0);
        D_002228C8 = 1;
    }
    copy = D_0021F210;
    return copy.f0[index];
}
