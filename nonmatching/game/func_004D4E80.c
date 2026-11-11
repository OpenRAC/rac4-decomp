/* Not matching yet: BYTES 30/828 (tools/try_func.py func_004D4E80 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
    Type1 *f8;
} Type2;

typedef struct {
    char _p0[0x54];
    s32 f54;
} Type3;

extern s32 func_0045E038(s32);
extern void func_004979A8(void *, s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00504F68(s32, s32);
extern void func_00505238(s32, s32);
extern void func_00505328(s32, s32);
extern void func_005054F8(s32, s32);
s32 D_0021FBB4 = 0;
s32 D_0021FBB0 = 0;
extern u8 D_0031B9C4[];

void func_004D4E80(Type3 *arg0, Type2 *arg1, s32 arg2) {
    s32 *p;
    s32 *q;
    Type1 *s;
    s32 h;
    u8 *buf;

    p = &arg1->f4;
    s = arg1->f8;
    func_00504F68(func_004A1A60(p, 6), s->f0 == 0);
    func_00504F68(func_004A1A60(p, 2), s->f0 != 0);
    if (s->f0 == 0) {
        h = func_004A1A60(p, 7);
        func_00505238(h, func_0045E038(s->f14));
        return;
    }
    func_005054F8(func_004A1A60(p, 4), 0x7534);
    h = func_004A1A60(p, 3);
    func_00505238(h, func_0045E038(s->f14));
    if (s->f8 == 0) {
        h = func_004A1A60(p, 5);
        func_00505238(h, func_0045E038(0x30DC));
    } else {
        buf = D_0031B9C4 + arg2 * 16;
        func_004979A8(buf, s->f8, 0);
        func_00505238(func_004A1A60(p, 5), (s32)buf);
    }
    if (s->f20 != 0) {
        func_00505328(func_004A1A60(&arg1->f4, 4), 0x80808080);
        q = &arg1->f4;
        func_00505328(func_004A1A60(&arg1->f4, 3), 0x80808080);
        if (s->f8 == 0) {
            func_00505328(func_004A1A60(q, 5), 0x8040D0D0);
        } else {
            func_00505328(func_004A1A60(q, 5), 0x80D0D0D0);
        }
    } else {
        func_00505328(func_004A1A60(&arg1->f4, 4), 0x80404040);
        q = &arg1->f4;
        func_00505328(func_004A1A60(&arg1->f4, 3), 0x80404040);
        func_00505328(func_004A1A60(&arg1->f4, 5), 0x80404080);
    }
    if (arg0->f54 == arg2) {
        func_00505328(func_004A1A60(q, 4), 0x80D0D0D0);
        func_00505328(func_004A1A60(q, 3), 0x80D0D0D0);
    }
    switch (s->f0) {
    case 11:
        if (s->f4 == D_0021FBB4) {
            func_00505328(func_004A1A60(q, 4), 0x8040D0D0);
            func_00505328(func_004A1A60(q, 3), 0x8040D0D0);
        }
        break;
    case 10:
        if (s->f4 == D_0021FBB0) {
            func_00505328(func_004A1A60(q, 4), 0x8040D0D0);
            func_00505328(func_004A1A60(q, 3), 0x8040D0D0);
        }
        break;
    }
}
