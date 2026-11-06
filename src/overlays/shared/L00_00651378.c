#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004C97B8(void);
extern void func_004CA0E0(void);
extern void func_004C9C20(void);

s32 D_00222974 = 0;
s32 D_00222978 = 0;
s32 D_0022297C = 0;
s32 D_00222980 = 0;
extern u8 D_00314338[];
extern u8 D_00314350[];
extern u8 D_00314368[];
extern u8 D_00314380[];
extern WordTable4 D_0021F308;

// On first use register the four blocks D_00314338, D_00314350, D_00314368 and
// D_00314380 through func_00501458 (with the callbacks func_004C97B8,
// func_004CA0E0, func_004C9C20), each guarded by its own flag, then return word
// index of the table D_0021F308.
s32 func_L00_00651378(s32 index) {
    WordTable4 copy;
    if (D_00222974 == 0) {
        func_00501458(D_00314338, (void *)func_004C97B8, (void *)func_004CA0E0,
                      (void *)func_004C9C20, 0, 0);
        D_00222974 = 1;
    }
    if (D_00222978 == 0) {
        func_00501458(D_00314350, (void *)func_004C97B8, (void *)func_004CA0E0,
                      (void *)func_004C9C20, 0, 0);
        D_00222978 = 1;
    }
    if (D_0022297C == 0) {
        func_00501458(D_00314368, (void *)func_004C97B8, (void *)func_004CA0E0,
                      (void *)func_004C9C20, 0, 0);
        D_0022297C = 1;
    }
    if (D_00222980 == 0) {
        func_00501458(D_00314380, (void *)func_004C97B8, (void *)func_004CA0E0,
                      (void *)func_004C9C20, 0, 0);
        D_00222980 = 1;
    }
    copy = D_0021F308;
    return copy.f0[index];
}
