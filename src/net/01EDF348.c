/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; u32 fC; } Sess;
extern char D_00199DF8[];
extern char D_00199E60[];
extern void func_0011EAA0(void *, s32, void *);
extern s32 func_01EE0980(Sess *, s32, u8 *, u8, u8 *, u32);
extern s32 func_0011A2DC(void *, void *, s32);
s32 func_01EDF348(Sess *s, u8 type, u8 *buf, u32 *len) {
    u8 tmp[0x20];
    u32 n;
    u32 rem;
    s32 r;
    switch (s->fC) {
    case 3:
    case 4:
        n = 0x10;
        break;
    case 5:
        n = 0x14;
        break;
    default:
        func_0011EAA0(D_00199DF8, 0x24A, D_00199E60);
        n = 0;
        break;
    }
    if (*len < n) {
        return -1;
    }
    rem = *len - n;
    r = func_01EE0980(s, 0, tmp, type, buf, rem);
    *len = rem;
    return func_0011A2DC(buf + rem, tmp, r);
}
