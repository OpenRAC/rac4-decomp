/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_01EAED20(u8 *);
extern void func_01EB0C70(u8 *, s32, s32);
extern void func_01EB0CA0(u8 *, u8 *, u32);

void func_01EAEBE0(u8 *ctx, u8 *out, u32 len) {
    s32 n;
    u8 *p;

    n = *(s32 *)(ctx + 0x58);
    n = (n >> 3) & 0x3F;
    p = ctx + n;
    n = 0x3F - n;
    *p++ = 0x80;
    if (n < 8) {
        func_0011A518(p, 0, n);
        func_01EB0C70(ctx, 0x40, *(s32 *)(ctx + 0x54));
        func_01EAED20(ctx);
        func_0011A518(ctx, 0, 0x38);
    } else {
        func_0011A518(p, 0, n - 8);
    }
    *(s32 *)(ctx + 0x38) = *(s32 *)(ctx + 0x5C);
    *(s32 *)(ctx + 0x3C) = *(s32 *)(ctx + 0x58);
    func_01EB0C70(ctx, 0x38, *(s32 *)(ctx + 0x54));
    func_01EAED20(ctx);
    if (len > 0x14) {
        func_0011A518(out + 0x14, 0, len - 0x14);
        len = 0x14;
    }
    func_01EB0CA0(out, ctx + 0x40, len);
    *(s32 *)ctx = 0;
}
