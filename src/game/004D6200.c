#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
} Type2;

typedef struct Type3 {
    char _p0[0x54];
    s32 f54;
} Type3;

typedef struct Type1 {
    s32 f0;
    s32 f4;
    Type2 *f8;
} Type1;

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(s32, s32);
extern s32 func_00505328(s32, s32);

void func_004D6200(Type3 *arg0, Type1 *arg1, s32 arg2) {
    s32 *p;
    Type2 *t;

    p = &arg1->f4;
    t = arg1->f8;
    func_00505238(func_004A1A60(p, 2), t->f0);
    func_00505238(func_004A1A60(p, 3), t->f4);
    if (arg2 == arg0->f54) {
        func_00505328(func_004A1A60(p, 2), 0x80D0D0D0);
        func_00505328(func_004A1A60(p, 3), 0x80D0D0D0);
        return;
    }
    func_00505328(func_004A1A60(p, 2), 0x80808080);
    func_00505328(func_004A1A60(p, 3), 0x80808080);
}
