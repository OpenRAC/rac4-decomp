/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x18]; s32 (*f18)(); } Type1;
typedef struct { char _p0[8]; Type1 *vt; } Type2;
typedef struct { char _p0[0x1C]; s32 f1C; Type2 *f20; } Type3;
extern void func_01EEBEA4(Type3 *, s32);
void func_01EEBE54(Type3 *arg0) {
    s32 x = arg0->f1C;
    if (arg0->f20->vt->f18(arg0->f20, &x) != 0) {
        func_01EEBEA4(arg0, 5);
    }
}
