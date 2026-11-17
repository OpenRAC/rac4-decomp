/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } Stream;
typedef struct { Stream st; Stream save; u8 f28; char _p29[0x23]; } Ctx;
extern void *func_0011A518(void *, s32, u32);
extern void func_01EAA0D0(Ctx *, u8 *, u8 *);
s32 func_01EDB6F8(Ctx *c, u32 len) {
    u32 n = len - sizeof(Ctx);
    u8 *p;
    if (c == 0) {
        return -0x15;
    }
    if (len < sizeof(Ctx)) {
        return -0x15;
    }
    func_0011A518(c, 0, sizeof(Ctx));
    p = (u8 *)(c + 1);
    func_01EAA0D0(c, p, p + n);
    c->st.f8 += sizeof(Ctx);
    c->save = c->st;
    c->f28 = 1;
    return 0;
}
