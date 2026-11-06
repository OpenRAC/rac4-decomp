#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004CB848(void);
extern void func_004CBE10(void);
extern void func_004CBEF8(void);

s32 D_00222994 = 0;
s32 D_00222998 = 0;
s32 D_0022299C = 0;
s32 D_002229A0 = 0;
extern u8 D_003147F0[];
extern u8 D_00314808[];
extern u8 D_00314820[];
extern u8 D_00314838[];
extern WordTable4 D_0021F350;

// On first use register the four blocks D_003147F0, D_00314808, D_00314820 and
// D_00314838 through func_00501458 (with the callbacks func_004CB848,
// func_004CBE10, func_004CBEF8), each guarded by its own flag, then return word
// index of the table D_0021F350.
s32 func_L00_006534A0(s32 index) {
    WordTable4 copy;
    if (D_00222994 == 0) {
        func_00501458(D_003147F0, (void *)func_004CB848, (void *)func_004CBE10,
                      (void *)func_004CBEF8, 0, 0);
        D_00222994 = 1;
    }
    if (D_00222998 == 0) {
        func_00501458(D_00314808, (void *)func_004CB848, (void *)func_004CBE10,
                      (void *)func_004CBEF8, 0, 0);
        D_00222998 = 1;
    }
    if (D_0022299C == 0) {
        func_00501458(D_00314820, (void *)func_004CB848, (void *)func_004CBE10,
                      (void *)func_004CBEF8, 0, 0);
        D_0022299C = 1;
    }
    if (D_002229A0 == 0) {
        func_00501458(D_00314838, (void *)func_004CB848, (void *)func_004CBE10,
                      (void *)func_004CBEF8, 0, 0);
        D_002229A0 = 1;
    }
    copy = D_0021F350;
    return copy.f0[index];
}
