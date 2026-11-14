/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_0052F728(s32 *object, s32 *arg1);
extern s32 func_L00_00534888(void *a, u8 **pp);
extern s32 func_L00_00535150(s32, u8 **);
extern void func_L00_00535E08(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);
extern s32 func_L00_00535FB0(s32, s32, s32);
extern s32 func_L00_005363C0(s32, u8 **);
extern s32 func_L00_00536AC0(void *list, s32 *out, s32 (*fn)(s32, void *), s32 arg3, s32 arg4);
extern s32 func_L00_00542110(s32 *object, s32 *arg1);
extern s32 func_0052FF10(s32, u8 **);
extern s32 func_L00_0052F2E8(s32, void *);

// Sums the encoded lengths of the fields of the record at o and, when arg1 is given, writes the encoding through *arg1.
s32 func_L00_0052E950(s32 *o, u8 **arg1) {
    s32 v;
    s32 s5 = 0;
    s32 s3 = 0;
    s32 s0 = 0;
    u8 *pp;
    u8 *q;

    if (o == NULL) {
        return 0;
    }
    if (o[0] != 0) {
        s3 = func_L00_00535150(o[0], NULL);
        s0 = func_L00_00535FB0(1, s3, 0);
    }
    s0 += func_L00_00535150(o[1], NULL);
    s0 += func_L00_00542110((s32 *)o[2], NULL);
    s0 += func_L00_005363C0(o[3], NULL);
    s0 += func_0052FF10(o[4], NULL);
    s0 += func_L00_005363C0(o[5], NULL);
    s0 += func_L00_0052F728((s32 *)o[6], NULL);
    if (o[7] != 0) {
        s0 += func_L00_00534888((void *)o[7], NULL);
    }
    if (o[8] != 0) {
        s0 += func_L00_00534888((void *)o[8], NULL);
    }
    if (o[9] != 0 && *(s32 *)o[9] != 0) {
        s5 = func_L00_00536AC0((void *)o[9], NULL, func_L00_0052F2E8, 0x10, 0);
        s0 += func_L00_00535FB0(1, s5, 3);
    }
    v = func_L00_00535FB0(1, s0, 0x10);
    if (arg1 == NULL) {
        return v;
    }
    {
        pp = *arg1;
        func_L00_00535E08(&pp, 1, s0, 0x10, 0);
        if (o[0] != 0) {
            func_L00_00535E08(&pp, 1, s3, 0, 0x80);
            func_L00_00535150(o[0], &pp);
        }
        func_L00_00535150(o[1], &pp);
        func_L00_00542110((s32 *)o[2], (s32 *)&pp);
        func_L00_005363C0(o[3], &pp);
        func_0052FF10(o[4], &pp);
        func_L00_005363C0(o[5], &pp);
        func_L00_0052F728((s32 *)o[6], (s32 *)&pp);
        if (o[7] != 0) {
            q = pp;
            func_L00_00534888((void *)o[7], &pp);
            q[0] = (q[0] & 0x20) | 0x81;
        }
        if (o[8] != 0) {
            q = pp;
            func_L00_00534888((void *)o[8], &pp);
            q[0] = (q[0] & 0x20) | 0x82;
        }
        if (o[9] != 0 && *(s32 *)o[9] != 0) {
            func_L00_00535E08(&pp, 1, s5, 3, 0x80);
            func_L00_00536AC0((void *)o[9], (s32 *)&pp, func_L00_0052F2E8, 0x10, 0);
        }
        *arg1 = pp;
    }
    return v;
}
