#include "common.h"

extern s32 func_00505B20(void);
s32 func_004A1A60(s32 *arg0, s32 arg1);
extern const char *func_0045E038(s32);
extern s32 func_00505238(s32, const char *);
extern s32 D_002219E0;
typedef struct Type1 {
    s32 f0, f4, f8;
    char padC[0x10];
} Type1;
typedef struct Type2 {
    char pad[0x10];
    s32 f10, f14;
} Type2;
extern Type1 D_0031B6B0[];
extern Type2 D_003D2A00[];

/* Refresh the current entry's localized label and clear its pending bit. */
void func_004D27F8(void)
{
    Type1 *p = D_0031B6B0 + func_00505B20();
    if (p->f4 >= 0) {
        s32 handle = func_004A1A60(&D_002219E0, 5);
        func_00505238(handle, func_0045E038(D_003D2A00[p->f4].f10));
        p->f8 &= ~1;
    }
}
