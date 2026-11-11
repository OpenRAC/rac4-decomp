#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x58];
    void *f58;
    char _p5C[0x4];
    s32 f60;
    char _p64[0xA4];
    s32 f108;
    char _p10C[0xC];
    s32 f118;
    s32 f11C;
    s32 f120;
};

s32 func_L00_00710750();
extern s32 D_004B9A28[];

void *func_L00_00719F68(Type1 *arg0) {
    s32 *var_v1;
    s32 var_a0;

    func_L00_00710750();
    arg0->f58 = D_004B9A28;
    var_a0 = 0x28;
    var_v1 = (void *)((u8 *)arg0 + 0x104);
    arg0->f60 = -1;
    arg0->f118 = -1;
    arg0->f11C = -1;
    arg0->f120 = -1;
    do {
        *var_v1 = 0;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    arg0->f108 = 0;
    return arg0;
}
