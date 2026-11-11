/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type3 {
    s32 f0;
    u32 f4;
    s32 f8;
    u8 *fC;
    u8 *f10;
} Type3;

typedef struct Type1 {
    u8 pad0[0x54];
    u8 *f54;
    u8 pad58[0x70 - 0x58];
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7C;
    u8 pad80[0xB0 - 0x80];
    s32 fB0;
} Type1;

extern void *func_0011A370(u8 *, u8 *, s32);
extern s32 func_0051A708(s32);
extern void func_00540840(s32, u8 *, u8 *, s32);
extern s32 func_00540E70(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void func_L00_00505D50(Type1 *, s32, s32);

s32 func_L00_00527DE0(Type1 *arg0, s32 arg1) {
    Type3 *b;
    s32 h;
    s32 ok;
    u64 len;
    s32 n;
    s32 pad;

    if (arg1 != 0) {
        h = arg0->f7C;
        b = (Type3 *)(arg0->f54 + 0xCC);
    } else {
        h = arg0->f70;
        b = (Type3 *)(arg0->f54 + 0xB4);
    }
    ok = 0;
    if (h != 0) {
        ok = func_00540E70(h);
    }
    if (arg0->fB0 == 0 || h == 0 || ok == 0) {
        func_0011A370(b->fC, b->f10, b->f4);
        b->f10 = b->fC;
    } else {
        len = b->f4;
        n = func_0051A708(h);
        if (n != 1 && arg1 != 0) {
            pad = n - (s32)len % n;
            len += pad;
            b->f4 += pad;
            b->f10[len - 1] = pad - 1;
        }
        func_00540840(h, b->fC, b->f10, len);
        if (n != 1 && arg1 == 0) {
            pad = b->fC[len - 1] + 1;
            if (n < pad) {
                func_L00_004F84C8(0x14, 0x86, 0x81, 0, 0);
                func_L00_00505D50(arg0, 2, 0x33);
                return 0;
            }
            b->f4 -= pad;
        }
    }
    return 1;
}
