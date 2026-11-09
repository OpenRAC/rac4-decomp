#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[0x70];
} Type1;

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);

extern s8 D_0021F9C0[];
extern s8 D_0021F9D0[];
extern s32 D_00221880;
extern s8 D_0030B6F8[];
extern Type1 D_0030B7F8[];

void func_004C2DE8(void) {
    Type1 *p;

    p = &D_0030B7F8[func_00505B20()];
    func_00505238(func_004A1A60(&D_00221880, 0x41), D_0030B6F8);
    if (p->f0 == 2) {
        s8 *fmt = D_0021F9C0;
        s32 a = func_0045E038(0x30D1);
        s32 b = func_0045E038(0x30D2);
        func_0011D920(D_0030B6F8, fmt, a, b, func_0045E038(0x2350));
    } else {
        s8 *fmt = D_0021F9D0;
        s32 a = func_0045E038(0x234F);
        func_0011D920(D_0030B6F8, fmt, a, func_0045E038(0x2350));
    }
}
