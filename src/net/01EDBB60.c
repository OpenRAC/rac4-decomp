/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x18];
    s32 f18;
};

s32 func_0011AFC8(void *, void *, s32);
extern s32 D_00169CE0[];
extern s32 D_001BC83C[];
extern s32 (*D_001BCA34)(void *, s32);

s32 func_01EDBB60(s32 arg0, s32 arg1, s32 arg2, Type1 *arg3) {
    if (arg3->f18 == 0) {
        func_0011AFC8(D_00169CE0, (void *)((u8 *)arg3 + 0x1C), 0x11);
    }
    if (D_001BCA34 != NULL) {
        D_001BCA34(arg3, D_001BC83C[0]);
    }
    return 0x30;
}
