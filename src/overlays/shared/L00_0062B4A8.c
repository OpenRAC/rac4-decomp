#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004A3B78(void);
extern void func_004A4578(void);
extern void func_004A45F8(void);

s32 D_0022268C = 0;
s32 D_00222690 = 0;
s32 D_00222694 = 0;
s32 D_00222698 = 0;
extern u8 D_0030D808[];
extern u8 D_0030D820[];
extern u8 D_0030D838[];
extern u8 D_0030D850[];
extern WordTable4 D_0021EF50;

// On first use register the four blocks D_0030D808, D_0030D820, D_0030D838 and
// D_0030D850 through func_00501458 (with the callbacks func_004A3B78,
// func_004A4578, func_004A45F8), each guarded by its own flag, then return word
// index of the table D_0021EF50.
s32 func_L00_0062B4A8(s32 index) {
    WordTable4 copy;
    if (D_0022268C == 0) {
        func_00501458(D_0030D808, (void *)func_004A3B78, (void *)func_004A4578,
                      (void *)func_004A45F8, 0, 0);
        D_0022268C = 1;
    }
    if (D_00222690 == 0) {
        func_00501458(D_0030D820, (void *)func_004A3B78, (void *)func_004A4578,
                      (void *)func_004A45F8, 0, 0);
        D_00222690 = 1;
    }
    if (D_00222694 == 0) {
        func_00501458(D_0030D838, (void *)func_004A3B78, (void *)func_004A4578,
                      (void *)func_004A45F8, 0, 0);
        D_00222694 = 1;
    }
    if (D_00222698 == 0) {
        func_00501458(D_0030D850, (void *)func_004A3B78, (void *)func_004A4578,
                      (void *)func_004A45F8, 0, 0);
        D_00222698 = 1;
    }
    copy = D_0021EF50;
    return copy.f0[index];
}
