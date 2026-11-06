/* Not matching yet: BYTES 8/240 (tools/try_func.py func_00492150 --diff). Not part of the build. */
#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));
s32 func_001633D0(void);
void *func_00490968(s32);
extern u8 *D_0027096C;

typedef struct {
    u128 v;
    s32 a;
    s32 b;
    s16 c;
    s16 d;
    f32 e;
} Type1;

void *func_00492150(u128 *arg0, u128 *arg1, s32 arg2, s32 arg3,
                    s32 arg4, s32 arg5, f32 arg6) {
    u8 *p;
    Type1 *q;
    if (arg4 == 0) return 0;
    p = func_00490968(0x15);
    if (p != 0) {
        *(u128 *)(p + 0x10) = *arg0;
        *(s32 *)(p + 4) = arg2;
        p[1] = 0;
        *(f32 *)(p + 0xC) = arg6;
        p[9] = 0xA4;
        p[3] = 0x48;
        p[8] = func_001633D0();
        q = (Type1 *)(p + 0x20);
        p[2] = *D_0027096C;
        *(s16 *)(p + 0xA) = arg4;
        q->c = arg4;
        q->e = arg6;
        q->a = arg2;
        q->b = arg3;
        q->d = arg5;
        q->v = *arg1;
    }
    return p;
}
