#include "common.h"

typedef struct S_arg0 S_arg0;
typedef struct S_arg1 S_arg1;
typedef struct S_arg2 S_arg2;
struct S_arg0 {
    f32 f0;
    f32 f4;
    f32 f8;
};
struct S_arg1 {
    f32 f0;
    f32 f4;
    f32 f8;
};
struct S_arg2 {
    f32 f0;
    f32 f4;
    f32 f8;
};

f32 func_L00_005BCE00(f32);
f32 func_L00_005BCFE8(f32, f32);
f32 func_L00_005BD030(f32, f32);

void func_L01_00591F88(S_arg0 *arg0, S_arg1 *arg1, S_arg2 *arg2, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = (1.0f - func_L00_005BCE00(fparg0 * 3.1415927f)) * 0.5f;
    arg0->f0 = func_L00_005BCFE8(arg1->f0, func_L00_005BD030(arg2->f0, arg1->f0) * temp_f20);
    arg0->f4 = func_L00_005BCFE8(arg1->f4, func_L00_005BD030(arg2->f4, arg1->f4) * temp_f20);
    arg0->f8 = func_L00_005BCFE8(arg1->f8, func_L00_005BD030(arg2->f8, arg1->f8) * temp_f20);
}
