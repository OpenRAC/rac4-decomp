#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_0049ABE8(void);
extern void func_0049AC78(void);
extern void func_0049AD48(void);

s32 D_0022261C = 0;
s32 D_00222620 = 0;
s32 D_00222624 = 0;
s32 D_00222628 = 0;
extern u8 D_0030CB60[];
extern u8 D_0030CB78[];
extern u8 D_0030CB90[];
extern u8 D_0030CBA8[];
extern WordTable4 D_0021EF00;

// On first use register the four blocks D_0030CB60, D_0030CB78, D_0030CB90 and
// D_0030CBA8 through func_00501458 (with the callbacks func_0049ABE8,
// func_0049AC78, func_0049AD48), each guarded by its own flag, then return word
// index of the table D_0021EF00.
s32 func_L00_00622240(s32 index) {
    WordTable4 copy;
    if (D_0022261C == 0) {
        func_00501458(D_0030CB60, (void *)func_0049ABE8, (void *)func_0049AC78,
                      (void *)func_0049AD48, 0, 0);
        D_0022261C = 1;
    }
    if (D_00222620 == 0) {
        func_00501458(D_0030CB78, (void *)func_0049ABE8, (void *)func_0049AC78,
                      (void *)func_0049AD48, 0, 0);
        D_00222620 = 1;
    }
    if (D_00222624 == 0) {
        func_00501458(D_0030CB90, (void *)func_0049ABE8, (void *)func_0049AC78,
                      (void *)func_0049AD48, 0, 0);
        D_00222624 = 1;
    }
    if (D_00222628 == 0) {
        func_00501458(D_0030CBA8, (void *)func_0049ABE8, (void *)func_0049AC78,
                      (void *)func_0049AD48, 0, 0);
        D_00222628 = 1;
    }
    copy = D_0021EF00;
    return copy.f0[index];
}
