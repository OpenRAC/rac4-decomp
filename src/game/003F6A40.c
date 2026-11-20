/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { u8 b[8]; } K8;
typedef struct { u8 *p; s32 z0; s32 q; s32 *n; u8 *r; s32 z1; } Args;
extern u8 D_003CA128[];
extern K8 D_003CF3E0;
u8 *func_003F6470(u8 *, u8 *);
s32 func_003FCEC0(s32 *);
s32 func_003FD478(s32 *);
s32 func_003FD588(s32, s32 (*)(s32 *), Args *);
s32 func_003FF4F8(s32, s32, void *, s32);
s32 func_003FF720(s32 *);
void func_003FF788(s32 *);
s32 func_003FF7F0(s32, s32, s32);
s32 func_003F6A40(s32 a0, void *a1, u8 *a2, s32 a3, s32 *t0, s32 t1, s32 *t2) {
    K8 k = D_003CF3E0;
    s32 h = 0;
    s32 s = 0;
    s32 r;
    Args A;
    while ((r = func_003FF720(&h)) == 0
           && (r = func_003FF7F0(h, t1, a0)) == 0
           && (r = func_003FD478(&s)) == 0) {
        A.p = a2;
        A.q = a3;
        A.n = t0;
        A.z0 = 0;
        A.r = func_003F6470(D_003CA128, k.b);
        A.z1 = 0;
        r = func_003FD588(s, func_003FCEC0, &A);
        if (r == 0) {
            r = func_003FF4F8(s, h, a1, 0);
        }
        break;
    }
    func_003FF788(&h);
    *t2 = s;
    return r;
}
