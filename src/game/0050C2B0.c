#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x1C];
    void (*f1C)(Type1 *, f32);
};
struct Type1 {
    char _p0[0x8];
    Type2 *f8;
    s32 fC;
    char _p10[0x1C];
    f32 f2C;
};

s32 func_00501940();
s32 func_00501960();

void func_0050C2B0(Type1 *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 var_f12;

    var_f12 = fparg0;
    if ((arg0->fC & 1) && (var_f12 > 0.001f)) {
        temp_f1 = arg0->f2C;
        if (temp_f1 > 0.001f) {
            if (temp_f1 < 0.999f) {
                var_f12 *= temp_f1;
            }
            arg0->f8->f1C(arg0, var_f12);
        }
    }
    if (arg0->fC & 0x4000) {
        func_00501960();
        func_00501940();
    }
}
