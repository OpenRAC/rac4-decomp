/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[16]; } B16;
typedef struct { B16 state; u8 cksum[16]; u8 buf[16]; u32 count; } Md2;
extern void func_01EB0D98(Md2 *, u8 *, u32);
extern u8 *D_00169430[];
extern void *func_0011A518(void *, s32, s32);
void *func_01EB0E58(Md2 *ctx, B16 *out) {
    u32 pad = 16 - ctx->count;
    func_01EB0D98(ctx, D_00169430[pad], pad);
    func_01EB0D98(ctx, ctx->cksum, 16);
    *out = ctx->state;
    return func_0011A518(ctx, 0, sizeof(*ctx));
}
