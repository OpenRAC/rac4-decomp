/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } Stream;
typedef struct { Stream st; Stream save; u8 f28; char _p29[0x23]; } Ctx;
extern void *func_0011A518(void *, s32, u32);
extern void func_01EAA0D0(Ctx *, u8 *, u8 *);
extern s32 func_01EDB5C0(s32, Ctx *, Ctx *);
s32 func_01EDB658(Ctx *c, u8 *buf) {
    if (c == 0) {
        return -0x15;
    }
    if (buf == 0) {
        return -0x15;
    }
    func_0011A518(c, 0, sizeof(Ctx));
    func_01EAA0D0(c, buf, buf + sizeof(Ctx));
    c->save = c->st;
    return func_01EDB5C0(2, c, c);
}
