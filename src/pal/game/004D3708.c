#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(s32, const char *);
extern s32 D_00221AE0;
typedef struct Type1 {
    s32 f0, f4, f8;
    char padC[0x10];
} Type1;
typedef struct Type2 {
    char pad[0x10];
    s32 f10, f14;
} Type2;
extern Type1 D_0031B6B0[];
extern Type2 D_003D2A70[];

/* Refresh the current entry's localized label and clear its pending bit. */
void func_004D3708(void)
{
    Type1 *p = D_0031B6B0 + func_00506BB8();
    if (p->f4 >= 0) {
        s32 handle = func_004A2798(&D_00221AE0, 5);
        func_005062D0(handle, func_0045E850(D_003D2A70[p->f4].f10));
        p->f8 &= ~1;
    }
}
