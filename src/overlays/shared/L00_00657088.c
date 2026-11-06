#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004CF420(void);
extern void func_004CF6D8(void);
extern void func_004CF778(void);

s32 D_002229FC = 0;
s32 D_00222A00 = 0;
s32 D_00222A04 = 0;
s32 D_00222A08 = 0;
extern u8 D_0031CAA0[];
extern u8 D_0031CAB8[];
extern u8 D_0031CAD0[];
extern u8 D_0031CAE8[];
extern WordTable4 D_0021F3A0;

// On first use register the four blocks D_0031CAA0, D_0031CAB8, D_0031CAD0 and
// D_0031CAE8 through func_00501458 (with the callbacks func_004CF420,
// func_004CF6D8, func_004CF778), each guarded by its own flag, then return word
// index of the table D_0021F3A0.
s32 func_L00_00657088(s32 index) {
    WordTable4 copy;
    if (D_002229FC == 0) {
        func_00501458(D_0031CAA0, (void *)func_004CF420, (void *)func_004CF6D8,
                      (void *)func_004CF778, 0, 0);
        D_002229FC = 1;
    }
    if (D_00222A00 == 0) {
        func_00501458(D_0031CAB8, (void *)func_004CF420, (void *)func_004CF6D8,
                      (void *)func_004CF778, 0, 0);
        D_00222A00 = 1;
    }
    if (D_00222A04 == 0) {
        func_00501458(D_0031CAD0, (void *)func_004CF420, (void *)func_004CF6D8,
                      (void *)func_004CF778, 0, 0);
        D_00222A04 = 1;
    }
    if (D_00222A08 == 0) {
        func_00501458(D_0031CAE8, (void *)func_004CF420, (void *)func_004CF6D8,
                      (void *)func_004CF778, 0, 0);
        D_00222A08 = 1;
    }
    copy = D_0021F3A0;
    return copy.f0[index];
}
