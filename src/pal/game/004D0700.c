#include "common.h"

typedef struct Type2 Type2;
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x54];
    s32 f54;
};
struct Type2 {
    char _p0[0x8];
    const char *f8;
};

s32 func_004A2798(s32 *, s32);
s32 func_004D0968(const char *);
s32 func_005062D0(s32, const char *);
s32 func_005063C0(s32, s32);

/* Updates two properties using the selector-dependent value. */
void func_004D0700(Type1 *arg0, Type2 *arg1, s32 arg2)
{
    s32 temp_s0;
    s32 *temp_s2;
    const char *temp_s3;

    temp_s2 = (s32 *)((char *)arg1 + 4);
    temp_s3 = arg1->f8;
    func_005062D0(func_004A2798(temp_s2, 2), temp_s3);
    if (arg2 == arg0->f54) {
        func_005063C0(func_004A2798(temp_s2, 2), 0x80D0D0D0);
    } else {
        temp_s0 = func_004A2798(temp_s2, 2);
        func_005063C0(temp_s0, func_004D0968(temp_s3));
    }
}
