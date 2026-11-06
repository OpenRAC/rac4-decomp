#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_L00_00637818(void);
extern void func_004AF9B8(void);
extern void func_L00_00637868(void);

s32 D_0022275C = 0;
s32 D_00222760 = 0;
s32 D_00222764 = 0;
s32 D_00222768 = 0;
extern u8 D_0030F168[];
extern u8 D_0030F180[];
extern u8 D_0030F198[];
extern u8 D_0030F1B0[];
extern WordTable4 D_0021F020;

// On first use register the four blocks D_0030F168, D_0030F180, D_0030F198 and
// D_0030F1B0 through func_00501458 (with the callbacks func_L00_00637818,
// func_004AF9B8, func_L00_00637868), each guarded by its own flag, then return word
// index of the table D_0021F020.
s32 func_L00_006375C0(s32 index) {
    WordTable4 copy;
    if (D_0022275C == 0) {
        func_00501458(D_0030F168, (void *)func_L00_00637818, (void *)func_004AF9B8,
                      (void *)func_L00_00637868, 0, 0);
        D_0022275C = 1;
    }
    if (D_00222760 == 0) {
        func_00501458(D_0030F180, (void *)func_L00_00637818, (void *)func_004AF9B8,
                      (void *)func_L00_00637868, 0, 0);
        D_00222760 = 1;
    }
    if (D_00222764 == 0) {
        func_00501458(D_0030F198, (void *)func_L00_00637818, (void *)func_004AF9B8,
                      (void *)func_L00_00637868, 0, 0);
        D_00222764 = 1;
    }
    if (D_00222768 == 0) {
        func_00501458(D_0030F1B0, (void *)func_L00_00637818, (void *)func_004AF9B8,
                      (void *)func_L00_00637868, 0, 0);
        D_00222768 = 1;
    }
    copy = D_0021F020;
    return copy.f0[index];
}
