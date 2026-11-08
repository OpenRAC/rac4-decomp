/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x18];
    s32 f18;
};

extern s32 D_00169CF4[];
extern s32 D_001BCA18[];
extern s32 (*D_001BCC10)(void *, s32);

s32 func_01EDDDA8(s32 arg0, s32 arg1, s32 arg2, Type1 *arg3) {
    if (arg3->f18 == -0x3B6) {
        D_00169CF4[0] = 0;
    }
    if (D_001BCC10 != NULL) {
        D_001BCC10(arg3, D_001BCA18[0]);
    }
    return 0x1C;
}
