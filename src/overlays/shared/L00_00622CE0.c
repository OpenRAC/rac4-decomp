#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_L00_006231E8(void);
extern void func_L00_00623208(void);
extern void func_0049B920(void);

s32 D_0022263C = 0;
s32 D_00222640 = 0;
s32 D_00222644 = 0;
s32 D_00222648 = 0;
extern u8 D_0030CCC8[];
extern u8 D_0030CCE0[];
extern u8 D_0030CCF8[];
extern u8 D_0030CD10[];
extern WordTable4 D_0021EF10;

// On first use register the four blocks D_0030CCC8, D_0030CCE0, D_0030CCF8 and
// D_0030CD10 through func_00501458 (with the callbacks func_L00_006231E8,
// func_L00_00623208, func_0049B920), each guarded by its own flag, then return word
// index of the table D_0021EF10.
s32 func_L00_00622CE0(s32 index) {
    WordTable4 copy;
    if (D_0022263C == 0) {
        func_00501458(D_0030CCC8, (void *)func_L00_006231E8, (void *)func_L00_00623208,
                      (void *)func_0049B920, 0, 0);
        D_0022263C = 1;
    }
    if (D_00222640 == 0) {
        func_00501458(D_0030CCE0, (void *)func_L00_006231E8, (void *)func_L00_00623208,
                      (void *)func_0049B920, 0, 0);
        D_00222640 = 1;
    }
    if (D_00222644 == 0) {
        func_00501458(D_0030CCF8, (void *)func_L00_006231E8, (void *)func_L00_00623208,
                      (void *)func_0049B920, 0, 0);
        D_00222644 = 1;
    }
    if (D_00222648 == 0) {
        func_00501458(D_0030CD10, (void *)func_L00_006231E8, (void *)func_L00_00623208,
                      (void *)func_0049B920, 0, 0);
        D_00222648 = 1;
    }
    copy = D_0021EF10;
    return copy.f0[index];
}
