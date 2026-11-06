#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D97E0(void);
extern void func_004D98A0(void);
extern void func_004D98F8(void);

s32 D_00222BE4 = 0;
s32 D_00222BE8 = 0;
s32 D_00222BEC = 0;
s32 D_00222BF0 = 0;
extern u8 D_003273C0[];
extern u8 D_003273D8[];
extern u8 D_003273F0[];
extern u8 D_00327408[];
extern WordTable4 D_0021F520;

// On first use register the four blocks D_003273C0, D_003273D8, D_003273F0 and
// D_00327408 through func_00501458 (with the callbacks func_004D97E0,
// func_004D98A0, func_004D98F8), each guarded by its own flag, then return word
// index of the table D_0021F520.
s32 func_L00_006615E0(s32 index) {
    WordTable4 copy;
    if (D_00222BE4 == 0) {
        func_00501458(D_003273C0, (void *)func_004D97E0, (void *)func_004D98A0,
                      (void *)func_004D98F8, 0, 0);
        D_00222BE4 = 1;
    }
    if (D_00222BE8 == 0) {
        func_00501458(D_003273D8, (void *)func_004D97E0, (void *)func_004D98A0,
                      (void *)func_004D98F8, 0, 0);
        D_00222BE8 = 1;
    }
    if (D_00222BEC == 0) {
        func_00501458(D_003273F0, (void *)func_004D97E0, (void *)func_004D98A0,
                      (void *)func_004D98F8, 0, 0);
        D_00222BEC = 1;
    }
    if (D_00222BF0 == 0) {
        func_00501458(D_00327408, (void *)func_004D97E0, (void *)func_004D98A0,
                      (void *)func_004D98F8, 0, 0);
        D_00222BF0 = 1;
    }
    copy = D_0021F520;
    return copy.f0[index];
}
