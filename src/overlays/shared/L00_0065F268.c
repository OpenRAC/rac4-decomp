#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D7488(void);
extern void func_004D75A8(void);
extern void func_004D7628(void);

s32 D_00222B74 = 0;
s32 D_00222B78 = 0;
s32 D_00222B7C = 0;
s32 D_00222B80 = 0;
extern u8 D_003245F8[];
extern u8 D_00324610[];
extern u8 D_00324628[];
extern u8 D_00324640[];
extern WordTable4 D_0021F4D0;

// On first use register the four blocks D_003245F8, D_00324610, D_00324628 and
// D_00324640 through func_00501458 (with the callbacks func_004D7488,
// func_004D75A8, func_004D7628), each guarded by its own flag, then return word
// index of the table D_0021F4D0.
s32 func_L00_0065F268(s32 index) {
    WordTable4 copy;
    if (D_00222B74 == 0) {
        func_00501458(D_003245F8, (void *)func_004D7488, (void *)func_004D75A8,
                      (void *)func_004D7628, 0, 0);
        D_00222B74 = 1;
    }
    if (D_00222B78 == 0) {
        func_00501458(D_00324610, (void *)func_004D7488, (void *)func_004D75A8,
                      (void *)func_004D7628, 0, 0);
        D_00222B78 = 1;
    }
    if (D_00222B7C == 0) {
        func_00501458(D_00324628, (void *)func_004D7488, (void *)func_004D75A8,
                      (void *)func_004D7628, 0, 0);
        D_00222B7C = 1;
    }
    if (D_00222B80 == 0) {
        func_00501458(D_00324640, (void *)func_004D7488, (void *)func_004D75A8,
                      (void *)func_004D7628, 0, 0);
        D_00222B80 = 1;
    }
    copy = D_0021F4D0;
    return copy.f0[index];
}
