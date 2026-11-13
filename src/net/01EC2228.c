/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a; s32 b; } Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x84];
    s32 f84;
    char _p88[0x28];
    void (*fB0)(Type2 *, s32, Type1, s32, s32);
    s32 fB4;
};
void func_01EC2228(s32 arg0, s32 arg1, s32 arg2, Type1 arg3, s32 arg4, Type2 *arg5) {
    if (arg5 != NULL) {
        arg5->f84 = 0;
        arg5->fB0(arg5, arg1, arg3, arg4, arg5->fB4);
    }
}
