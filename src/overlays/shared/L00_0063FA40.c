#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004B7E78(void);
extern void func_004B8038(void);
extern void func_004B80D0(void);

s32 D_0022280C = 0;
s32 D_00222810 = 0;
s32 D_00222814 = 0;
s32 D_00222818 = 0;
extern u8 D_0030FED0[];
extern u8 D_0030FEE8[];
extern u8 D_0030FF00[];
extern u8 D_0030FF18[];
extern WordTable4 D_0021F118;

// On first use register the four blocks D_0030FED0, D_0030FEE8, D_0030FF00 and
// D_0030FF18 through func_00501458 (with the callbacks func_004B7E78,
// func_004B8038, func_004B80D0), each guarded by its own flag, then return word
// index of the table D_0021F118.
s32 func_L00_0063FA40(s32 index) {
    WordTable4 copy;
    if (D_0022280C == 0) {
        func_00501458(D_0030FED0, (void *)func_004B7E78, (void *)func_004B8038,
                      (void *)func_004B80D0, 0, 0);
        D_0022280C = 1;
    }
    if (D_00222810 == 0) {
        func_00501458(D_0030FEE8, (void *)func_004B7E78, (void *)func_004B8038,
                      (void *)func_004B80D0, 0, 0);
        D_00222810 = 1;
    }
    if (D_00222814 == 0) {
        func_00501458(D_0030FF00, (void *)func_004B7E78, (void *)func_004B8038,
                      (void *)func_004B80D0, 0, 0);
        D_00222814 = 1;
    }
    if (D_00222818 == 0) {
        func_00501458(D_0030FF18, (void *)func_004B7E78, (void *)func_004B8038,
                      (void *)func_004B80D0, 0, 0);
        D_00222818 = 1;
    }
    copy = D_0021F118;
    return copy.f0[index];
}
