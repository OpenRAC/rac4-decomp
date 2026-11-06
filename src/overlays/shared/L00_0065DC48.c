#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D5E48(void);
extern void func_004D5F68(void);
extern void func_004D5FD0(void);

s32 D_00222A94 = 0;
s32 D_00222A98 = 0;
s32 D_00222A9C = 0;
s32 D_00222AA0 = 0;
extern u8 D_00322B70[];
extern u8 D_00322B88[];
extern u8 D_00322BA0[];
extern u8 D_00322BB8[];
extern WordTable4 D_0021F498;

// On first use register the four blocks D_00322B70, D_00322B88, D_00322BA0 and
// D_00322BB8 through func_00501458 (with the callbacks func_004D5E48,
// func_004D5F68, func_004D5FD0), each guarded by its own flag, then return word
// index of the table D_0021F498.
s32 func_L00_0065DC48(s32 index) {
    WordTable4 copy;
    if (D_00222A94 == 0) {
        func_00501458(D_00322B70, (void *)func_004D5E48, (void *)func_004D5F68,
                      (void *)func_004D5FD0, 0, 0);
        D_00222A94 = 1;
    }
    if (D_00222A98 == 0) {
        func_00501458(D_00322B88, (void *)func_004D5E48, (void *)func_004D5F68,
                      (void *)func_004D5FD0, 0, 0);
        D_00222A98 = 1;
    }
    if (D_00222A9C == 0) {
        func_00501458(D_00322BA0, (void *)func_004D5E48, (void *)func_004D5F68,
                      (void *)func_004D5FD0, 0, 0);
        D_00222A9C = 1;
    }
    if (D_00222AA0 == 0) {
        func_00501458(D_00322BB8, (void *)func_004D5E48, (void *)func_004D5F68,
                      (void *)func_004D5FD0, 0, 0);
        D_00222AA0 = 1;
    }
    copy = D_0021F498;
    return copy.f0[index];
}
