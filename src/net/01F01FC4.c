/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_01EE38EC(s32 *arg0);
extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A98(void *arg0);
extern s32 func_01EE3AC0(void *arg0);
extern s32 func_01F020DC(void *);
extern s32 func_01F021B0(void *, s32);
extern s32 func_01F025D0(void *, s32);
extern s32 func_01F03110(void *);
extern void func_01F0C090(char *arg0, s32 arg1);
extern char D_0019DC20[];
extern char D_0019DE70[];
extern char D_0019DE78[];

/* Walk the entries of a list and dispatch on each entry's name. */
s32 func_01F01FC4(char *arg0) {
    s32 e;
    char *name;

    if (func_01EE3AC0(*(void **)arg0) == 0) {
        func_01F0C090(D_0019DC20, 0x3F0);
    }
    e = func_01EE3960(*(void **)arg0);
    while (e != 0) {
        name = (char *)func_01EE3A98((void *)e);
        if (name != 0) {
            if (func_0011A8A0(name, D_0019DE70) == 0) {
                if (*(s32 *)(arg0 + 0xC4) > 0 || *(s32 *)(arg0 + 0xC0) > 0) {
                    func_01F021B0(arg0, e);
                }
            } else if (func_0011A8A0(name, D_0019DE78) == 0) {
                func_01F025D0(arg0, e);
            } else {
                func_01F0C090(D_0019DC20, 0x409);
            }
        }
        e = func_01EE38EC((s32 *)e);
    }
    func_01F020DC(arg0);
    func_01F03110(arg0);
    return 1;
}
