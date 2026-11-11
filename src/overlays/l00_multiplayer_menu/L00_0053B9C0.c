/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s64 *p;
    s32 n;
    s32 pad[5];
} Buf;

typedef struct {
    s64 *f0;
    s32 f4;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0x14];
    char f20[0x28];
    s64 f48;
} Type1;

extern void func_00538180(Buf *);
extern void func_L00_00537CE8(void *, void *, void *, s32);
extern s32 func_L00_00537F68(Type2 *);
extern void func_L00_00538038(void *);
extern void func_L00_00538098(void *, s32);
extern void func_L00_005383D0(void *, Type2 *);
extern void func_L00_00538508(void *, s32);
extern void func_L00_00538938(void *, void *, s32);
extern void func_L00_00539310(void *, s32);
extern s64 func_L00_0053BCF0(s64, s64, s64);
extern s32 func_L00_00546D70(s64);
extern s32 func_L00_00546F50(void *, s32);

s32 func_L00_0053B9C0(Type1 *arg0, Type2 *arg1, s32 arg2) {
    Buf buf;
    void *s4;
    void *s1;
    s64 key;
    s64 a;
    s64 b;

    if (arg1->f4 == 0) {
        return 0;
    }
    s4 = arg0->f20;
    func_00538180(&buf);
    func_L00_005383D0(s4, arg1);
    s1 = arg0->fC;
    arg0->f0 = 1;
    arg0->f8 = (func_L00_00537F68(arg1) + 63) / 64;
    func_L00_00538508(s1, 0);
    func_L00_00546F50(s1, 0x40);
    key = *arg1->f0;
    func_L00_00538508(&buf, func_L00_00546D70(key));
    func_L00_00538938(&buf, &buf, 0x40);
    if (buf.n != 0 && (buf.n != 1 || buf.p[0] != 0)) {
        func_L00_00539310(&buf, 1);
    } else {
        func_L00_00538508(&buf, -1);
    }
    a = 0;
    if (buf.n >= 2) {
        a = buf.p[1];
    }
    if (buf.n > 0) {
        b = buf.p[0];
    } else {
        b = 0;
    }
    arg0->f48 = func_L00_0053BCF0(a, b, key);
    func_L00_00538038(&buf);
    func_L00_00538508(s1, 0);
    func_L00_00546F50(s1, arg0->f8 << 7);
    func_L00_00537CE8(s1, s1, s4, arg2);
    func_L00_00538098(s1, arg0->f8);
    return 1;
}
