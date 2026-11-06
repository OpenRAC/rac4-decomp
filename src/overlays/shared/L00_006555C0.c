#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004CD978(void);
extern void func_004CDC10(void);
extern void func_004CDCC8(void);

s32 D_002229BC = 0;
s32 D_002229C0 = 0;
s32 D_002229C4 = 0;
s32 D_002229C8 = 0;
extern u8 D_00314A30[];
extern u8 D_00314A48[];
extern u8 D_00314A60[];
extern u8 D_00314A78[];
extern WordTable4 D_0021F368;

// On first use register the four blocks D_00314A30, D_00314A48, D_00314A60 and
// D_00314A78 through func_00501458 (with the callbacks func_004CD978,
// func_004CDC10, func_004CDCC8), each guarded by its own flag, then return word
// index of the table D_0021F368.
s32 func_L00_006555C0(s32 index) {
    WordTable4 copy;
    if (D_002229BC == 0) {
        func_00501458(D_00314A30, (void *)func_004CD978, (void *)func_004CDC10,
                      (void *)func_004CDCC8, 0, 0);
        D_002229BC = 1;
    }
    if (D_002229C0 == 0) {
        func_00501458(D_00314A48, (void *)func_004CD978, (void *)func_004CDC10,
                      (void *)func_004CDCC8, 0, 0);
        D_002229C0 = 1;
    }
    if (D_002229C4 == 0) {
        func_00501458(D_00314A60, (void *)func_004CD978, (void *)func_004CDC10,
                      (void *)func_004CDCC8, 0, 0);
        D_002229C4 = 1;
    }
    if (D_002229C8 == 0) {
        func_00501458(D_00314A78, (void *)func_004CD978, (void *)func_004CDC10,
                      (void *)func_004CDCC8, 0, 0);
        D_002229C8 = 1;
    }
    copy = D_0021F368;
    return copy.f0[index];
}
