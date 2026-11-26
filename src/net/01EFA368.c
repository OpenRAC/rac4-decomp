/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;

struct Type3 {
    char _p0[0x24];
    s32 (*fn24)(Type2 *);
    char _p28[0x18];
    void (*fn40)(Type2 *);
};

struct Type1 {
    char _p0[0x80];
    s32 *f80;
    char _p84[0x30];
    s32 fB4;
    s32 fB8;
    s32 fBC;
    char _pC0[0x14];
    s32 fD4;
    char _pD8[0x1C];
    s32 fF4;
};

struct Type2 {
    u8 f0;
    char _p1[0xD7];
    Type3 *fD8;
};

extern s32 func_0011AB04(u8 *);
extern void func_01EF9E90(Type1 *, u8);
extern void func_01EFAA2C(Type1 *, s32);
extern void func_01EFB300(Type1 *);
extern s32 func_01EFCFDC(s32, s32, u8 *, s32, s32);

void func_01EFA368(Type1 *arg0, Type2 *arg1) {
    u8 buf[2];
    s32 len;
    s32 v1;
    u8 *p;
    u8 ch;
    Type3 *vt;
    s32 v;

    vt = arg1->fD8;
    p = (u8 *)vt->fn24(arg1);
    len = func_0011AB04(p);
    v1 = func_0011AB04(arg0->fB4);
    if (len > 0)
        buf[0] = p[len - 1];
    else
        buf[0] = 0;
    buf[1] = 0;
    ch = arg1->f0;
    if (ch != 0) {
        func_01EF9E90(arg0, ch);
    } else if (len > 0 && v1 < arg0->fB8 - 1 && arg0->fF4 < arg0->fBC) {
        v = func_0011AB04(buf);
        arg0->fD4 = func_01EFCFDC(arg0->fB4, arg0->fB8, buf, v, arg0->fD4);
        func_01EFB300(arg0);
        func_01EFAA2C(arg0, *arg0->f80);
    }
    vt = arg1->fD8;
    vt->fn40(arg1);
}
