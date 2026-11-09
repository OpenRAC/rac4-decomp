/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x8];
    s32 (*f14)();
};
struct Type1 {
    Type2 *f0;
    char _p4[0x4];
    s32 f8;
    s32 fC;
};

s32 func_0011A518(s32, s32, s32);

void func_L00_005195A8(Type1 *arg0, s32 arg1, s32 *arg2) {
    arg0->f0->f14(arg1, arg0->fC);
    if (arg2 != NULL) {
        *arg2 = arg0->f0->f8;
    }
    func_0011A518(arg0->fC, 0, arg0->f8);
}
