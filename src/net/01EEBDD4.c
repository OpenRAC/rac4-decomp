/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct { char _p0[0xC]; s32 (*fC)(Type1 *, void *, s32, s32 *); } Type2;
struct Type1 { char _p0[8]; Type2 *vt; };
extern void func_01EED528(s32);
extern void func_01EEBEA4(u8 *, s32);
void func_01EEBDD4(u8 *arg0) {
    s32 x = 0;
    Type1 *q = *(Type1 **)(arg0 + 0x20);
    s32 r = q->vt->fC(q, arg0 + 0x658, *(s32 *)(arg0 + 0x138), &x);
    *(s32 *)(arg0 + 0x1C) = r;
    if (r == 0) {
        func_01EED528(0x12);
        return;
    }
    if (x != 0) {
        func_01EEBEA4(arg0, 5);
    } else {
        func_01EEBEA4(arg0, 4);
    }
}
