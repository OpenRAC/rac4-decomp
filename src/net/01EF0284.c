/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 D_0019C500[];
extern s32 D_0019C538[];

extern s8 *func_0011A700(char *, s32);
extern s32 func_0011AE00(char *, char *, s32);
extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_01EEE07C(s8);
extern void func_01F0C090(char *, s32);
extern s32 func_01EEFF4C(char *, char *, char *);

s32 func_01EF0284(char *arg0, char *arg1) {
    char buf[0x80];
    char *s0;
    char *v0;

    if (func_0011AE00(arg1, (char *)D_0019C538, 7) == 0) {
        func_01F0C090((char *)D_0019C500, 0xF8);
        return 0;
    }
    s0 = func_0011A700(arg1, 0x3A) + 1;
    while (func_01EEE07C(*s0) != 0) {
        s0++;
    }
    func_0011AFC8(buf, s0, 0x7F);
    buf[0x7E] = 0;
    s0 = func_0011A700(buf, 0x3D);
    if (s0 == 0) {
        func_01F0C090((char *)D_0019C500, 0x10F);
        return 0;
    }
    *s0 = 0;
    s0++;
    v0 = func_0011A700(s0, 0x3B);
    if (v0 == 0) {
        func_01F0C090((char *)D_0019C500, 0x117);
        return 0;
    }
    *v0 = 0;
    return func_01EEFF4C(arg0, buf, s0);
}
