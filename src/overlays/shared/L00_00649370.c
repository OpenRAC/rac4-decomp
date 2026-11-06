#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004C1640(void);
extern void func_004C1E98(void);
extern void func_004C1FA8(void);

s32 D_002228FC = 0;
s32 D_00222900 = 0;
s32 D_00222904 = 0;
s32 D_00222908 = 0;
extern u8 D_00311498[];
extern u8 D_003114B0[];
extern u8 D_003114C8[];
extern u8 D_003114E0[];
extern WordTable4 D_0021F268;

// On first use register the four blocks D_00311498, D_003114B0, D_003114C8 and
// D_003114E0 through func_00501458 (with the callbacks func_004C1640,
// func_004C1E98, func_004C1FA8), each guarded by its own flag, then return word
// index of the table D_0021F268.
s32 func_L00_00649370(s32 index) {
    WordTable4 copy;
    if (D_002228FC == 0) {
        func_00501458(D_00311498, (void *)func_004C1640, (void *)func_004C1E98,
                      (void *)func_004C1FA8, 0, 0);
        D_002228FC = 1;
    }
    if (D_00222900 == 0) {
        func_00501458(D_003114B0, (void *)func_004C1640, (void *)func_004C1E98,
                      (void *)func_004C1FA8, 0, 0);
        D_00222900 = 1;
    }
    if (D_00222904 == 0) {
        func_00501458(D_003114C8, (void *)func_004C1640, (void *)func_004C1E98,
                      (void *)func_004C1FA8, 0, 0);
        D_00222904 = 1;
    }
    if (D_00222908 == 0) {
        func_00501458(D_003114E0, (void *)func_004C1640, (void *)func_004C1E98,
                      (void *)func_004C1FA8, 0, 0);
        D_00222908 = 1;
    }
    copy = D_0021F268;
    return copy.f0[index];
}
