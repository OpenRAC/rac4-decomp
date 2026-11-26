/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x1C]; s32 f1C; } Node_1C;

extern s32 func_01EA8F98(s32 *arg0);
extern s32 func_01EA90F0(s32 id);
extern s32 func_01EAE710(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_01EB2EE0(s32 arg0);
extern Node_1C *func_01EB3028(s32 l, s32 key);
extern void func_01EB30C8(const void *a, s32 b, void *c, s32 d);

s32 func_01EB3B78(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 a[16];
    u32 b[16];
    s32 t;
    Node_1C *n;
    u32 i;

    if (arg3 == 0) {
        goto fail;
    }
    if (func_01EA8F98((s32 *)arg2) != 0) {
        return -1;
    }
    t = func_01EA90F0(arg0);
    if (t == 0) {
        return -1;
    }
    n = func_01EB3028(t, arg1);
    if (n == 0) {
        return -1;
    }
    if (func_01EB2EE0(n->f1C) != 0) {
        goto fail;
    }
    goto success;
fail:
    return -1;
success:
    func_01EB30C8((void *)n->f1C, 4, a, 0x40);
    func_01EAE710(arg2, arg3, (s32)b, 0x40);
    for (i = 0; i < 16; i++) {
        if (a[i] != b[i]) {
            goto fail;
        }
    }
    return 0;
}
