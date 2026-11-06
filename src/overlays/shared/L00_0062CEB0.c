#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004A54D8(void);
extern void func_004A5558(void);
extern void func_004A5588(void);

s32 D_002226A4 = 0;
s32 D_002226A8 = 0;
s32 D_002226AC = 0;
s32 D_002226B0 = 0;
extern u8 D_0030DD08[];
extern u8 D_0030DD20[];
extern u8 D_0030DD38[];
extern u8 D_0030DD50[];
extern WordTable4 D_0021EF78;

// On first use register the four blocks D_0030DD08, D_0030DD20, D_0030DD38 and
// D_0030DD50 through func_00501458 (with the callbacks func_004A54D8,
// func_004A5558, func_004A5588), each guarded by its own flag, then return word
// index of the table D_0021EF78.
s32 func_L00_0062CEB0(s32 index) {
    WordTable4 copy;
    if (D_002226A4 == 0) {
        func_00501458(D_0030DD08, (void *)func_004A54D8, (void *)func_004A5558,
                      (void *)func_004A5588, 0, 0);
        D_002226A4 = 1;
    }
    if (D_002226A8 == 0) {
        func_00501458(D_0030DD20, (void *)func_004A54D8, (void *)func_004A5558,
                      (void *)func_004A5588, 0, 0);
        D_002226A8 = 1;
    }
    if (D_002226AC == 0) {
        func_00501458(D_0030DD38, (void *)func_004A54D8, (void *)func_004A5558,
                      (void *)func_004A5588, 0, 0);
        D_002226AC = 1;
    }
    if (D_002226B0 == 0) {
        func_00501458(D_0030DD50, (void *)func_004A54D8, (void *)func_004A5558,
                      (void *)func_004A5588, 0, 0);
        D_002226B0 = 1;
    }
    copy = D_0021EF78;
    return copy.f0[index];
}
