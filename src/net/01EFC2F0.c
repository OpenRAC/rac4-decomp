/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct { char _p0[0x14]; void (*f14)(Type1 *, s32, char *, s32); } Type2;
struct Type1 { Type2 *vt; };
typedef struct {
    char _p0[0x80];
    Type1 **f80;
    char _p84[0x240];
    s32 f2C4;
} Type3;
extern void func_01F0C090(void *, s32);
extern void func_0011A518(void *, s32, s32);
extern void func_0011AFC8(char *, char *, s32);
extern s32 func_0011AB04(char *);
extern char D_0019D4A0[];
void func_01EFC2F0(Type3 *arg0, char *arg1, s32 arg2, s32 arg3) {
    char buf[0x200];
    Type1 *o;
    s32 n;
    n = arg3 - arg2;
    o = *arg0->f80;
    if (n >= 0x200) {
        func_01F0C090(D_0019D4A0, 0x202);
    }
    func_0011A518(buf, 0, 0x200);
    func_0011AFC8(buf, arg1 + arg2, n);
    o->vt->f14(o, arg0->f2C4, buf, func_0011AB04(buf));
}
