#include "common.h"

/* The first argument is unused; retail reads the following two from a1/a2. */
typedef struct S_arg1 S_arg1;
typedef struct S_arg1_174 S_arg1_174;
struct S_arg1_174 {
    char _p0[0x78];
    f32 f78;
};
struct S_arg1 {
    char _p0[0x170];
    s32 f170;
    S_arg1_174 *f174;
    char _p178[0xC];
    s32 f184;
};

s32 func_131850(f32);
s32 func_L00_0066D220(s32, s32, s32);


void func_L01_0048F020(s32 unused0, S_arg1 *arg1, s32 arg2) {
    f32 temp_f12;
    s32 temp_v1;

    if (arg2 != 0) {
        arg1->f184 = 2;
        return;
    }
    temp_v1 = arg1->f184;
    if ((temp_v1 == 0) || (temp_v1 == 3)) {
        arg1->f184 = 1;
        temp_f12 = arg1->f174->f78;
        if (temp_f12 > -1.0f) {
            func_L00_0066D220(func_131850(temp_f12), 0, arg1->f170);
        }
    }
}
