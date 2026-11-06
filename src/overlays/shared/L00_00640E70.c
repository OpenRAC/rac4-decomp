#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004B9240(void);
extern void func_004B9330(void);
extern void func_004B93B0(void);

s32 D_0022282C = 0;
s32 D_00222830 = 0;
s32 D_00222834 = 0;
s32 D_00222838 = 0;
extern u8 D_0030FFA0[];
extern u8 D_0030FFB8[];
extern u8 D_0030FFD0[];
extern u8 D_0030FFE8[];
extern WordTable4 D_0021F160;

// On first use register the four blocks D_0030FFA0, D_0030FFB8, D_0030FFD0 and
// D_0030FFE8 through func_00501458 (with the callbacks func_004B9240,
// func_004B9330, func_004B93B0), each guarded by its own flag, then return word
// index of the table D_0021F160.
s32 func_L00_00640E70(s32 index) {
    WordTable4 copy;
    if (D_0022282C == 0) {
        func_00501458(D_0030FFA0, (void *)func_004B9240, (void *)func_004B9330,
                      (void *)func_004B93B0, 0, 0);
        D_0022282C = 1;
    }
    if (D_00222830 == 0) {
        func_00501458(D_0030FFB8, (void *)func_004B9240, (void *)func_004B9330,
                      (void *)func_004B93B0, 0, 0);
        D_00222830 = 1;
    }
    if (D_00222834 == 0) {
        func_00501458(D_0030FFD0, (void *)func_004B9240, (void *)func_004B9330,
                      (void *)func_004B93B0, 0, 0);
        D_00222834 = 1;
    }
    if (D_00222838 == 0) {
        func_00501458(D_0030FFE8, (void *)func_004B9240, (void *)func_004B9330,
                      (void *)func_004B93B0, 0, 0);
        D_00222838 = 1;
    }
    copy = D_0021F160;
    return copy.f0[index];
}
