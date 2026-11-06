#include "common.h"

typedef struct __attribute__((packed)) {
    u32 f0[4];
} WordTable4;

extern void *func_00501458(void *, void *, void *, void *, void *, void *);
extern void func_004D8D98(void);
extern void func_004D8E58(void);
extern void func_004D8EB0(void);

s32 D_00222BC4 = 0;
s32 D_00222BC8 = 0;
s32 D_00222BCC = 0;
s32 D_00222BD0 = 0;
extern u8 D_00326EB0[];
extern u8 D_00326EC8[];
extern u8 D_00326EE0[];
extern u8 D_00326EF8[];
extern WordTable4 D_0021F508;

// On first use register the four blocks D_00326EB0, D_00326EC8, D_00326EE0 and
// D_00326EF8 through func_00501458 (with the callbacks func_004D8D98,
// func_004D8E58, func_004D8EB0), each guarded by its own flag, then return word
// index of the table D_0021F508.
s32 func_L00_00660B98(s32 index) {
    WordTable4 copy;
    if (D_00222BC4 == 0) {
        func_00501458(D_00326EB0, (void *)func_004D8D98, (void *)func_004D8E58,
                      (void *)func_004D8EB0, 0, 0);
        D_00222BC4 = 1;
    }
    if (D_00222BC8 == 0) {
        func_00501458(D_00326EC8, (void *)func_004D8D98, (void *)func_004D8E58,
                      (void *)func_004D8EB0, 0, 0);
        D_00222BC8 = 1;
    }
    if (D_00222BCC == 0) {
        func_00501458(D_00326EE0, (void *)func_004D8D98, (void *)func_004D8E58,
                      (void *)func_004D8EB0, 0, 0);
        D_00222BCC = 1;
    }
    if (D_00222BD0 == 0) {
        func_00501458(D_00326EF8, (void *)func_004D8D98, (void *)func_004D8E58,
                      (void *)func_004D8EB0, 0, 0);
        D_00222BD0 = 1;
    }
    copy = D_0021F508;
    return copy.f0[index];
}
