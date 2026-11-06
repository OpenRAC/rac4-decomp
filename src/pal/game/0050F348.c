#include "common.h"

typedef struct Type2 Type2;
typedef struct Type3 Type3;
typedef struct Type1 Type1;
struct Type3 {
    char _p0[0x14];
    s32 (*f14)();
};
struct Type1 {
    char _p0[0x48];
    s32 f48;
    s32 f4C;
    s32 f50;
    u8 f54;
    char _p55[0x3];
    f32 f58;
    f32 f5C;
    u8 f60;
    char _p61[0x3];
    s32 f64;
    f32 f68;
    f32 f6C;
};
struct Type2 {
    char _p0[0x8];
    Type3 *f8;
    char _pC[0x3C];
    s32 f48;
    s32 f4C;
    s32 f50;
    u8 f54;
    char _p55[0x3];
    f32 f58;
    f32 f5C;
    u8 f60;
    char _p61[0x3];
    s32 f64;
    f32 f68;
    f32 f6C;
};

s32 func_0050D040(void *, void *);

/* Copies state after the source callback accepts the operation. */
s32 func_0050F348(Type1 *arg0, Type2 *arg1)
{
    if (arg1->f8->f14(arg1, 1) != 0) {
        func_0050D040(arg0, arg1);
        arg0->f48 = (s32)arg1->f48;
        arg0->f4C = (s32)arg1->f4C;
        arg0->f50 = (s32)arg1->f50;
        arg0->f54 = (u8)arg1->f54;
        arg0->f58 = (f32)arg1->f58;
        arg0->f5C = (f32)arg1->f5C;
        arg0->f60 = (u8)arg1->f60;
        arg0->f64 = (s32)arg1->f64;
        arg0->f68 = (f32)arg1->f68;
        arg0->f6C = (f32)arg1->f6C;
        return 1;
    }
    return 0;
}
