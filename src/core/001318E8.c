#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

extern void func_00131680(Type1 *arg0);

void func_001318E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Type1 args;

    args.f0 = arg0;
    args.f4 = arg1;
    args.f8 = arg2;
    args.fC = arg3;
    func_00131680(&args);
}
