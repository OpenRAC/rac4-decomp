/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 state[4]; u32 count[2]; u8 buf[64]; u32 _p58[2]; } Hc_60;
extern void func_01EB1C60(Hc_60 *, u8 *, u32);
extern void func_01EB2C50(u8 *, u32 *, u32);
extern u8 D_001694B8[];
extern void *func_0011A518(void *, s32, s32);
void func_01EB1DC0(u8 *out, Hc_60 *ctx) {
    u8 enc[8];
    u32 bits[2];
    u32 idx;
    u32 pad;
    bits[0] = ctx->count[0];
    bits[1] = ctx->count[1];
    idx = bits[0] & 0x3F;
    pad = ((idx < 56) ? 56 : 120) - idx;
    func_01EB1C60(ctx, D_001694B8, pad);
    bits[1] = (bits[1] << 3) + (bits[0] >> 29);
    bits[0] <<= 3;
    func_01EB2C50(enc, bits, 8);
    func_01EB1C60(ctx, enc, 8);
    func_01EB2C50(out, ctx->state, 16);
    func_0011A518(ctx, 0, sizeof(*ctx));
}
