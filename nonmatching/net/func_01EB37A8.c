/* Not matching yet: BYTES 1/144 (tools/try_func.py func_01EB37A8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node {
    u8 pad0[0x1C];
    s32 unk1C;
} Node;

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern void *func_01EA90F0();
extern s32 func_01EB2EE0(s32 arg0);
extern Node *func_01EB3028(void *l, u32 key);

s32 func_01EB37A8(s32 arg0, s32 arg1, u8 *arg2) {
    void *ctx;
    Node *n;

    ctx = func_01EA90F0();
    if (ctx == 0)
        return -1;
    if (arg2 == 0)
        return -1;
    n = func_01EB3028(ctx, arg1);
    if (n != 0 && func_01EB2EE0(n->unk1C) == 0)
        goto copy;
    func_0011A518(arg2, 0, 0x40);
    return -1;
copy:
    func_0011A370(arg2, (u8 *)n->unk1C, 0x40);
    return 0;
}
