/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 w[24]; } Sc_60;
extern void func_01EAE980(Sc_60 *);
extern void func_01EAEA48(Sc_60 *, u8 *, u32);
extern void func_01EAEBE0(Sc_60 *, u8 *, u32);
void func_01EB3138(u8 *a, u32 alen, u8 *b, u32 blen, u8 *out, u32 outlen) {
    Sc_60 ctx;
    func_01EAE980(&ctx);
    if (a != 0 && alen != 0) {
        func_01EAEA48(&ctx, a, alen);
    }
    func_01EAEA48(&ctx, b, blen);
    func_01EAEBE0(&ctx, out, outlen);
}
