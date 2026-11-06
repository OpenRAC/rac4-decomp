#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004A68D8(void);
extern void func_004A6AA8(void);
extern void func_004A6AD8(void);

s32 D_002226CC = 0;
s32 D_002226D0 = 0;
s32 D_002226D4 = 0;
s32 D_002226D8 = 0;
extern u8 D_0030DEA8[];
extern u8 D_0030DEC0[];
extern u8 D_0030DED8[];
extern u8 D_0030DEF0[];
extern WordTable4 D_0021EF90;

// On first use register the four blocks D_0030DEA8, D_0030DEC0, D_0030DED8 and
// D_0030DEF0 through func_00501458 (with the callbacks func_004A68D8,
// func_004A6AA8, func_004A6AD8), each guarded by its own flag, then return word
// index of the table D_0021EF90.
s32 func_L00_0062E2B0(s32 index) {
    WordTable4 copy;
    if (D_002226CC == 0) {
        func_00501458(D_0030DEA8, (void *)func_004A68D8, (void *)func_004A6AA8,
                      (void *)func_004A6AD8, 0, 0);
        D_002226CC = 1;
    }
    if (D_002226D0 == 0) {
        func_00501458(D_0030DEC0, (void *)func_004A68D8, (void *)func_004A6AA8,
                      (void *)func_004A6AD8, 0, 0);
        D_002226D0 = 1;
    }
    if (D_002226D4 == 0) {
        func_00501458(D_0030DED8, (void *)func_004A68D8, (void *)func_004A6AA8,
                      (void *)func_004A6AD8, 0, 0);
        D_002226D4 = 1;
    }
    if (D_002226D8 == 0) {
        func_00501458(D_0030DEF0, (void *)func_004A68D8, (void *)func_004A6AA8,
                      (void *)func_004A6AD8, 0, 0);
        D_002226D8 = 1;
    }
    copy = D_0021EF90;
    return copy.f0[index];
}
