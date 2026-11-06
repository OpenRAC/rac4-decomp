#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004BB018(void);
extern void func_004BB150(void);
extern void func_004BB300(void);

s32 D_0022287C = 0;
s32 D_00222880 = 0;
s32 D_00222884 = 0;
s32 D_00222888 = 0;
extern u8 D_003103A0[];
extern u8 D_003103B8[];
extern u8 D_003103D0[];
extern u8 D_003103E8[];
extern WordTable4 D_0021F1C0;

// On first use register the four blocks D_003103A0, D_003103B8, D_003103D0 and
// D_003103E8 through func_00501458 (with the callbacks func_004BB018,
// func_004BB150, func_004BB300), each guarded by its own flag, then return word
// index of the table D_0021F1C0.
s32 func_L00_00642C10(s32 index) {
    WordTable4 copy;
    if (D_0022287C == 0) {
        func_00501458(D_003103A0, (void *)func_004BB018, (void *)func_004BB150,
                      (void *)func_004BB300, 0, 0);
        D_0022287C = 1;
    }
    if (D_00222880 == 0) {
        func_00501458(D_003103B8, (void *)func_004BB018, (void *)func_004BB150,
                      (void *)func_004BB300, 0, 0);
        D_00222880 = 1;
    }
    if (D_00222884 == 0) {
        func_00501458(D_003103D0, (void *)func_004BB018, (void *)func_004BB150,
                      (void *)func_004BB300, 0, 0);
        D_00222884 = 1;
    }
    if (D_00222888 == 0) {
        func_00501458(D_003103E8, (void *)func_004BB018, (void *)func_004BB150,
                      (void *)func_004BB300, 0, 0);
        D_00222888 = 1;
    }
    copy = D_0021F1C0;
    return copy.f0[index];
}
