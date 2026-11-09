#include "common.h"

extern s32 func_0012A918(void *);
extern void func_00127568(void *, s32);
extern s32 func_0011D5D8(const char *, ...);
extern s32 D_0021DD20;
extern u8 D_1BD480[];
extern u8 D_001A4768[];

u32 *D_0021DCA8 = 0;
s32 D_0021DCAC = 0;

s32 func_00158198(void) {
    u32 *p;

    if (D_0021DCA8 == 0) {
        return 1;
    }
    if (func_0012A918(D_1BD480) != 0) {
        return 0;
    }
    func_00127568(D_0021DCA8, (D_0021DCAC << 2) + (s32)D_0021DCA8 + 8);
    p = D_0021DCA8;
    if (p[0] == 0xFFFFFFFF && p[D_0021DCAC + 1] == p[0]) {
        D_0021DCA8 = 0;
        return 1;
    }
    if (D_0021DD20 != 0) {
        return 0;
    }
    func_0011D5D8((const char *)D_001A4768);
    return 0;
}
