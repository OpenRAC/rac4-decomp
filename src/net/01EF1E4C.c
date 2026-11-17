/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

// md5_update of Christophe Devine's md5.c (THIRD_PARTY_NOTICES.md): adds length bytes of input.
typedef unsigned long uint32;
typedef struct { uint32 total[2]; uint32 state[4]; u8 buffer[64]; } md5_context;
void *func_0011A370(void *, void *, s32);
void func_01EF0D88(md5_context *, u8 *);
void func_01EF1E4C(md5_context *ctx, u8 *input, uint32 length) {
    uint32 left, fill;

    if (!length) {
        return;
    }
    left = (ctx->total[0] >> 3) & 0x3F;
    fill = 64 - left;
    ctx->total[0] += length << 3;
    ctx->total[1] += length >> 29;
    ctx->total[0] &= 0xFFFFFFFF;
    ctx->total[1] += ctx->total[0] < (length << 3);
    if (left && length >= fill) {
        func_0011A370((void *)(ctx->buffer + left), (void *)input, fill);
        func_01EF0D88(ctx, ctx->buffer);
        length -= fill;
        input += fill;
        left = 0;
    }
    while (length >= 64) {
        func_01EF0D88(ctx, input);
        length -= 64;
        input += 64;
    }
    if (length) {
        func_0011A370((void *)(ctx->buffer + left), (void *)input, length);
    }
}
