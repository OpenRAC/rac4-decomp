#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004AE2A0(void);
extern void func_004AE6D8(void);
extern void func_004AE448(void);

s32 D_0022272C = 0;
s32 D_00222730 = 0;
s32 D_00222734 = 0;
s32 D_00222738 = 0;
extern u8 D_0030F040[];
extern u8 D_0030F058[];
extern u8 D_0030F070[];
extern u8 D_0030F088[];
extern WordTable4 D_0021F010;

// On first use register the four blocks D_0030F040, D_0030F058, D_0030F070 and
// D_0030F088 through func_00501458 (with the callbacks func_004AE2A0,
// func_004AE6D8, func_004AE448), each guarded by its own flag, then return word
// index of the table D_0021F010.
s32 func_L00_00635EC0(s32 index) {
    WordTable4 copy;
    if (D_0022272C == 0) {
        func_00501458(D_0030F040, (void *)func_004AE2A0, (void *)func_004AE6D8,
                      (void *)func_004AE448, 0, 0);
        D_0022272C = 1;
    }
    if (D_00222730 == 0) {
        func_00501458(D_0030F058, (void *)func_004AE2A0, (void *)func_004AE6D8,
                      (void *)func_004AE448, 0, 0);
        D_00222730 = 1;
    }
    if (D_00222734 == 0) {
        func_00501458(D_0030F070, (void *)func_004AE2A0, (void *)func_004AE6D8,
                      (void *)func_004AE448, 0, 0);
        D_00222734 = 1;
    }
    if (D_00222738 == 0) {
        func_00501458(D_0030F088, (void *)func_004AE2A0, (void *)func_004AE6D8,
                      (void *)func_004AE448, 0, 0);
        D_00222738 = 1;
    }
    copy = D_0021F010;
    return copy.f0[index];
}
