#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D2380(void);
extern void func_004D26D8(void);
extern void func_004D2748(void);

s32 D_00222A5C = 0;
s32 D_00222A60 = 0;
s32 D_00222A64 = 0;
s32 D_00222A68 = 0;
extern u8 D_00321450[];
extern u8 D_00321468[];
extern u8 D_00321480[];
extern u8 D_00321498[];
extern WordTable4 D_0021F3E8;

// On first use register the four blocks D_00321450, D_00321468, D_00321480 and
// D_00321498 through func_00501458 (with the callbacks func_004D2380,
// func_004D26D8, func_004D2748), each guarded by its own flag, then return word
// index of the table D_0021F3E8.
s32 func_L00_00659F28(s32 index) {
    WordTable4 copy;
    if (D_00222A5C == 0) {
        func_00501458(D_00321450, (void *)func_004D2380, (void *)func_004D26D8,
                      (void *)func_004D2748, 0, 0);
        D_00222A5C = 1;
    }
    if (D_00222A60 == 0) {
        func_00501458(D_00321468, (void *)func_004D2380, (void *)func_004D26D8,
                      (void *)func_004D2748, 0, 0);
        D_00222A60 = 1;
    }
    if (D_00222A64 == 0) {
        func_00501458(D_00321480, (void *)func_004D2380, (void *)func_004D26D8,
                      (void *)func_004D2748, 0, 0);
        D_00222A64 = 1;
    }
    if (D_00222A68 == 0) {
        func_00501458(D_00321498, (void *)func_004D2380, (void *)func_004D26D8,
                      (void *)func_004D2748, 0, 0);
        D_00222A68 = 1;
    }
    copy = D_0021F3E8;
    return copy.f0[index];
}
