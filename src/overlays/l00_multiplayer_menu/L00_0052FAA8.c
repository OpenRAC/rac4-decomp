/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_0053D468(s32, s32, void *, s64);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_0051CA88(s32 arg0);
extern void func_L00_0051D000(s32 object);
extern void *func_L00_0053D1F0(void *arg0, void *arg1, s64 arg2);

/* Builds and caches the object for a descriptor. */
s32 *func_L00_0052FAA8(s32 *arg0) {
    s32 sp0;
    s32 *s1;
    s32 *a;
    u32 *d;
    s32 t;
    s64 x;
    s32 c;

    s1 = 0;
    if (arg0 != 0) {
        if (arg0[2] != 0) return (s32 *)arg0[2];
        if (arg0[1] != 0) {
            t = func_L00_0051CA88(*(s32 *)arg0[0]);
            d = (u32 *)arg0[1];
            x = d[0];
            sp0 = d[2];
            s1 = (s32 *)func_0053D468(t, 0, &sp0, x);
            if (s1 == 0) {
                func_L00_004F84C8(0xB, 0xD1, 0x98, 0, 0);
            } else {
                s1[4] = 0;
                a = (s32 *)arg0[0];
                if (s1[0] == 0x74) {
                    c = *(s32 *)a[1];
                    if (c == 0x10) {
                        *(s32 *)(s1[3] + 8) = 0;
                        sp0 = ((s32 *)((s32 *)a[1])[1])[2];
                        if (func_L00_0053D1F0(s1 + 3, &sp0, ((u32 *)((s32 *)a[1])[1])[0]) == 0) goto fail;
                    }
                    s1[4] = 1;
                }
                arg0[2] = (s32)s1;
                return s1;
            }
        }
    }
fail:
    if (s1 != 0) func_L00_0051D000((s32)s1);
    return 0;
}
