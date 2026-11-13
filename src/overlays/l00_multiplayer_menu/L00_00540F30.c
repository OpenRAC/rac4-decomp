/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;

struct Type1 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x4];
    u8 *fC;
};

struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

s32 func_L00_00548070(Type1 *, s32);
void func_0011A370(u8 *, u8 *, s32);

s32 func_L00_00540F30(Type1 *arg0, Type2 *arg1) {
    if (!func_L00_00548070(arg0, arg1->f0)) return 0;
    arg0->f4 = arg1->f4;
    if (arg1->fC != 0) {
        func_0011A370(arg0->fC, (u8 *)arg1->fC, arg1->f8);
    }
    return 1;
}
