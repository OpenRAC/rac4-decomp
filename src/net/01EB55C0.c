/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0; u32 f4; } Type1;
extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];
extern s32 func_01E9D060();
extern void func_01EB4D28(u8 *p, u32 x);

/* Send a buffer through the net layer, accumulating the sent count. */
s32 func_01EB55C0(s32 a0, Type1 a1, u32 a2, s32 a3, s32 *out)
{
    u8 buf[16];
    s32 flags;
    s32 r;
    u32 x;
    u8 *p;

    x = a1.f0;
    flags = 0;
    if (!D_001694FC[0]) return 5;
    if (a0 < 0) return 2;
    if (!x) return 2;
    if (a2 & 0xFFFF0000) return 2;
    p = buf;
    *out = 0;
    func_01EB4D28(p, x);
    r = func_01E9D060(D_1B26C0, D_1B2700, a0, a3, &flags, p, a2, 0);
    if (r < 0) return 0xC350;
    *out += r;
    return 0;
}
