/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

// md5_finish of Christophe Devine's md5.c (THIRD_PARTY_NOTICES.md): pads, appends the bit count
// and writes the 16-byte digest.
typedef unsigned long uint32;
typedef struct { uint32 total[2]; uint32 state[4]; u8 buffer[64]; } md5_context;
#define PUT_UINT32(n, b, i) { (b)[(i)] = (u8)(((n)) & 0xFF); (b)[(i) + 1] = (u8)(((n) >> 8) & 0xFF); (b)[(i) + 2] = (u8)(((n) >> 16) & 0xFF); (b)[(i) + 3] = (u8)(((n) >> 24) & 0xFF); }
extern u8 D_0016E450[];
void func_01EF1E4C(md5_context *, u8 *, uint32);
void func_01EF1F70(md5_context *ctx, u8 *digest) {
    uint32 last, padn;
    u8 msglen[8];

    PUT_UINT32(ctx->total[0], msglen, 0);
    PUT_UINT32(ctx->total[1], msglen, 4);
    last = (ctx->total[0] >> 3) & 0x3F;
    padn = (last < 56) ? (56 - last) : (120 - last);
    func_01EF1E4C(ctx, D_0016E450, padn);
    func_01EF1E4C(ctx, msglen, 8);
    PUT_UINT32(ctx->state[0], digest, 0);
    PUT_UINT32(ctx->state[1], digest, 4);
    PUT_UINT32(ctx->state[2], digest, 8);
    PUT_UINT32(ctx->state[3], digest, 12);
}
