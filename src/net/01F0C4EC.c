/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    char _p1C[0x4];
    s32 f20;
};

s32 func_01EF0550(s32, s32);

void func_01F0C4EC(Type1 *arg0) {
    s32 temp_v1;

    arg0->f4 = 0x1F4;
    temp_v1 = arg0->f8;
    if (temp_v1 != 0) {
        func_01EF0550(arg0->f18, temp_v1);
        arg0->f8 = 0;
    }
    arg0->fC = 0;
    arg0->f10 = 0;
    arg0->f14 = 0;
    arg0->f20 = 0;
}
