#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004B9BE8(void);
extern void func_004B9DF8(void);
extern void func_004B9EB0(void);

s32 D_0022285C = 0;
s32 D_00222860 = 0;
s32 D_00222864 = 0;
s32 D_00222868 = 0;
extern u8 D_00310000[];
extern u8 D_00310018[];
extern u8 D_00310030[];
extern u8 D_00310048[];
extern WordTable4 D_0021F190;

// On first use register the four blocks D_00310000, D_00310018, D_00310030 and
// D_00310048 through func_00501458 (with the callbacks func_004B9BE8,
// func_004B9DF8, func_004B9EB0), each guarded by its own flag, then return word
// index of the table D_0021F190.
s32 func_L00_00641850(s32 index) {
    WordTable4 copy;
    if (D_0022285C == 0) {
        func_00501458(D_00310000, (void *)func_004B9BE8, (void *)func_004B9DF8,
                      (void *)func_004B9EB0, 0, 0);
        D_0022285C = 1;
    }
    if (D_00222860 == 0) {
        func_00501458(D_00310018, (void *)func_004B9BE8, (void *)func_004B9DF8,
                      (void *)func_004B9EB0, 0, 0);
        D_00222860 = 1;
    }
    if (D_00222864 == 0) {
        func_00501458(D_00310030, (void *)func_004B9BE8, (void *)func_004B9DF8,
                      (void *)func_004B9EB0, 0, 0);
        D_00222864 = 1;
    }
    if (D_00222868 == 0) {
        func_00501458(D_00310048, (void *)func_004B9BE8, (void *)func_004B9DF8,
                      (void *)func_004B9EB0, 0, 0);
        D_00222868 = 1;
    }
    copy = D_0021F190;
    return copy.f0[index];
}
