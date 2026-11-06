#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004A9FA0(void);
extern void func_004AA068(void);
extern void func_004AA0B0(void);

s32 D_002226F0 = 0;
s32 D_002226F4 = 0;
s32 D_002226F8 = 0;
s32 D_002226FC = 0;
extern u8 D_0030E200[];
extern u8 D_0030E218[];
extern u8 D_0030E230[];
extern u8 D_0030E248[];
extern WordTable4 D_0021EFC0;

// On first use register the four blocks D_0030E200, D_0030E218, D_0030E230 and
// D_0030E248 through func_00501458 (with the callbacks func_004A9FA0,
// func_004AA068, func_004AA0B0), each guarded by its own flag, then return word
// index of the table D_0021EFC0.
s32 func_L00_00631CD0(s32 index) {
    WordTable4 copy;
    if (D_002226F0 == 0) {
        func_00501458(D_0030E200, (void *)func_004A9FA0, (void *)func_004AA068,
                      (void *)func_004AA0B0, 0, 0);
        D_002226F0 = 1;
    }
    if (D_002226F4 == 0) {
        func_00501458(D_0030E218, (void *)func_004A9FA0, (void *)func_004AA068,
                      (void *)func_004AA0B0, 0, 0);
        D_002226F4 = 1;
    }
    if (D_002226F8 == 0) {
        func_00501458(D_0030E230, (void *)func_004A9FA0, (void *)func_004AA068,
                      (void *)func_004AA0B0, 0, 0);
        D_002226F8 = 1;
    }
    if (D_002226FC == 0) {
        func_00501458(D_0030E248, (void *)func_004A9FA0, (void *)func_004AA068,
                      (void *)func_004AA0B0, 0, 0);
        D_002226FC = 1;
    }
    copy = D_0021EFC0;
    return copy.f0[index];
}
