#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;

struct Type1 {
    char _p0[0x5C];
    s32 f5C;
    s32 f60;
    f32 f64;
    f32 f68;
    f32 f6C;
    f32 f70;
    s32 f74;
    s32 f78;
};

struct Type2 {
    char _p0[0x40];
    s32 f40;
    s32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    s32 f58;
};

void func_L00_007107F0(Type1 *, Type2 *);

void func_L00_00711FA0(Type1 *arg0, Type2 *arg1) {
    func_L00_007107F0(arg0, arg1);
    arg0->f5C = arg1->f40;
    arg0->f60 = arg1->f44;
    arg0->f64 = arg1->f48;
    arg0->f6C = arg1->f50;
    arg0->f68 = arg1->f4C;
    arg0->f70 = arg1->f54;
    arg0->f74 = arg1->f58;
    arg0->f78 = 0;
}
