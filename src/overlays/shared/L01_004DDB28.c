#include "common.h"

typedef struct Type2 {
    char _p0[0x1E0];
    f32 f1E0;
    f32 f1E4;
    f32 f1E8;
    char _p1EC[0x4];
    f32 f1F0;
    f32 f1F4;
    f32 f1F8;
    char _p1FC[0x390];
    f32 f58C;
    u32 f590;
    char _p594[0x4];
    f32 f598;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

f32 func_L00_005BD078(f32);

void func_L01_004DDB28(Type1 *arg0) {
    Type2 *p = arg0->fAC;
    u32 c = 0xFF303030;
    f32 v = p->f598;
    f32 t;

    p->f1E0 = func_L00_005BD078(p->f1E0 + 0.03f);
    p->f1E4 = func_L00_005BD078(p->f1E4 + 0.03f);
    p->f1E8 = func_L00_005BD078(p->f1E8 + 0.03f);
    p->f1F0 = func_L00_005BD078(p->f1F0 - 0.021f);
    p->f1F4 = func_L00_005BD078(p->f1F4 - 0.021f);
    t = func_L00_005BD078(p->f1F8 - 0.021f);
    p->f58C = v;
    p->f590 = c;
    p->f1F8 = t;
}
