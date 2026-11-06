#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004CE660(void);
extern void func_004CEAB0(void);
extern void func_004CEB68(void);

s32 D_002229DC = 0;
s32 D_002229E0 = 0;
s32 D_002229E4 = 0;
s32 D_002229E8 = 0;
extern u8 D_003155C0[];
extern u8 D_003155D8[];
extern u8 D_003155F0[];
extern u8 D_00315608[];
extern WordTable4 D_0021F380;

// On first use register the four blocks D_003155C0, D_003155D8, D_003155F0 and
// D_00315608 through func_00501458 (with the callbacks func_004CE660,
// func_004CEAB0, func_004CEB68), each guarded by its own flag, then return word
// index of the table D_0021F380.
s32 func_L00_006562C8(s32 index) {
    WordTable4 copy;
    if (D_002229DC == 0) {
        func_00501458(D_003155C0, (void *)func_004CE660, (void *)func_004CEAB0,
                      (void *)func_004CEB68, 0, 0);
        D_002229DC = 1;
    }
    if (D_002229E0 == 0) {
        func_00501458(D_003155D8, (void *)func_004CE660, (void *)func_004CEAB0,
                      (void *)func_004CEB68, 0, 0);
        D_002229E0 = 1;
    }
    if (D_002229E4 == 0) {
        func_00501458(D_003155F0, (void *)func_004CE660, (void *)func_004CEAB0,
                      (void *)func_004CEB68, 0, 0);
        D_002229E4 = 1;
    }
    if (D_002229E8 == 0) {
        func_00501458(D_00315608, (void *)func_004CE660, (void *)func_004CEAB0,
                      (void *)func_004CEB68, 0, 0);
        D_002229E8 = 1;
    }
    copy = D_0021F380;
    return copy.f0[index];
}
