#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type1;

extern void func_0011A9EC(void *, void *);
extern s32 func_0011D920(void *arg0, void *arg1, ...);
extern void *func_0045E038(s32);
extern s32 func_00498918(s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505238(s32, void *);
extern s32 func_005056C8(s32 handle, s32 a, s32 b, s32 c, s32 d);
extern s32 func_00505B70(s32 index, s32 handle);

extern s32 D_002217E0;
extern Type1 D_003D9528[];
extern char D_0021F8E0[];
extern char D_0030A460[];
extern char D_0030A4E0[];
extern char D_0030A540[];

void func_004BA958(void)
{
    s32 a;
    s32 b;
    void *s;
    char *buf;
    char *fmt;

    func_00501638(&D_002217E0, 0x25, -1);
    func_00505B70(0xF, D_002217E0);
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[0].f8), func_0045E038(0x2347));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[1].f8), func_0045E038(0x2348));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[2].f8), func_0045E038(0x2349));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[3].f8), func_0045E038(0x234A));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[4].f8), func_0045E038(0x3503));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[5].f8), func_0045E038(0x234B));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[6].f8), func_0045E038(0x234C));
    func_00505238(func_004A1A60(&D_002217E0, D_003D9528[7].f8), func_0045E038(0x234D));
    a = func_00498918(1, 0);
    b = func_00498918(1, 2);
    func_005056C8(func_004A1A60(&D_002217E0, 0x20), b, a, b, a);
    func_005056C8(func_004A1A60(&D_002217E0, 0x1D), b, a, b, a);
    func_005056C8(func_004A1A60(&D_002217E0, 0x1A), b, a, b, a);
    buf = D_0030A460;
    fmt = D_0021F8E0;
    s = func_0045E038(0x234F);
    func_0011D920(buf, fmt, s, func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_002217E0, 0x13), buf);
    func_00505238(func_004A1A60(&D_002217E0, 0x14), func_0045E038(0x2F25));
    func_0011A9EC(D_0030A4E0, func_0045E038(0x176));
    func_0011A9EC(D_0030A4E0 + 0x30, func_0045E038(0x175));
    func_0011A9EC(D_0030A540, func_0045E038(0x236));
    func_0011A9EC(D_0030A540 + 0x30, func_0045E038(0x237));
}
