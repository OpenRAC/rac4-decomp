/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 state[4]; u32 count[2]; u8 buf[64]; } Md5;
extern void func_01EB1C20(Md5 *);
extern void func_01EB1C60(Md5 *, u8 *, u32);
extern void func_01EB1DC0(u8 *, Md5 *);
void func_01EB1B90(u8 *a, u32 alen, u8 *b, u32 blen, u8 *out) {
    Md5 ctx;
    func_01EB1C20(&ctx);
    if (a != 0 && alen != 0) {
        func_01EB1C60(&ctx, a, alen);
    }
    func_01EB1C60(&ctx, b, blen);
    func_01EB1DC0(out, &ctx);
}
