/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 state[4]; u32 count[2]; u8 buf[64]; } Md5;
extern void func_01EB1A80(u8 *, u32 *, u32);
extern void func_01EB10E0(Md5 *, u8 *, u32);
extern u8 D_00169478[];
extern void *func_0011A518(void *, s32, s32);
void func_01EB11C8(Md5 *ctx, u8 *digest) {
    u8 bits[8];
    u32 index;
    u32 pad;
    func_01EB1A80(bits, ctx->count, 8);
    index = (ctx->count[0] >> 3) & 0x3F;
    pad = (index < 56) ? (56 - index) : (120 - index);
    func_01EB10E0(ctx, D_00169478, pad);
    func_01EB10E0(ctx, bits, 8);
    func_01EB1A80(digest, ctx->state, 16);
    func_0011A518(ctx, 0, sizeof(*ctx));
}
