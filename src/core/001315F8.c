#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s64 f10;
} Type1;

extern void func_001309C0(Type1 *arg0);

/* Packs four values into a request object. */
void func_001315F8(s32 arg0, s32 arg1, s32 arg2, s64 arg3) {
    Type1 request;

    request.f0 = arg0;
    request.f4 = arg1;
    request.f8 = arg2;
    request.f10 = arg3;
    func_001309C0(&request);
}
