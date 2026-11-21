/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0011EB90(s32 a0);
extern s32 func_0012B338(const char *name, s32 flags, ...);
extern s32 func_0012B5C8(s32 fd);
extern s32 func_0012B740(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0012B980(s32, void *, s32);
extern s32 func_01EE34E0(s32 *p);
extern void func_01EE38C4(void **p);
extern s8 *func_01EE39E0(s32 arg0, void *arg1);
extern void func_01EE4AA0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void func_01EE4D48(s32 arg0);
extern void *func_01EEDCD0(void *, const void *, s32);
extern s32 func_01EEE070(s32 arg0);
extern void func_01F0C090(const char *, s32);
extern s32 D_0016E418[];
extern s8 D_0019C378[];
extern s8 D_0019C380[];
extern s8 D_0019C390[];
extern s8 D_0019C398[];
extern s8 D_0019C3A0[];

// Reads the file named from arg1 into a scratch buffer and fills the object at arg0 from its three sections; returns 1 on success.
s32 func_01EEDAA8(void *arg0, s32 arg1) {
    s8 buf[0x1000];
    s8 name[0x100];
    s32 sec;
    s32 fd;
    s32 size;
    s32 ok;
    s32 ret;
    s32 tab;
    s8 *p;

    ret = 0;
    func_0011A518(buf, 0, 0x1000);
    func_0011D920(name, D_0019C378, D_0016E418[0], arg1);
    fd = func_0012B338(name, 1);
    if (fd < 0) {
        return ret;
    }
    size = func_0012B740(fd, 0, 2);
    func_0012B740(fd, 0, 0);
    if (size <= 0) {
        func_01F0C090(D_0019C380, 0x48);
    }
    ok = size < 0x1000;
    if (!ok) {
        func_01F0C090(D_0019C380, 0x4B);
    }
    func_0012B980(fd, buf, size);
    if (!ok) {
        func_01F0C090(D_0019C380, 0x4F);
    }
    func_0012B5C8(fd);
    sec = 0;
    tab = func_01EE34E0(&sec);
    func_01EE4AA0(tab, buf, 0, 1);
    if (sec == 0) {
        func_01F0C090(D_0019C380, 0x7E);
    }
    p = func_01EE39E0(sec, D_0019C390);
    if (p == NULL) {
        func_01F0C090(D_0019C380, 0x84);
    }
    func_01EEDCD0(arg0, p, 0x40);
    p = func_01EE39E0(sec, D_0019C398);
    if ((s32)arg0 == -0x44) {
        func_01F0C090(D_0019C380, 0x88);
    }
    func_01EEDCD0((u8 *)arg0 + 0x44, p, 0x100);
    p = func_01EE39E0(sec, D_0019C3A0);
    if (p == NULL || func_01EEE070(p[0]) == 0) {
        func_01F0C090(D_0019C380, 0x8C);
    }
    *(s32 *)((u8 *)arg0 + 0x40) = func_0011EB90((s32)p);
    func_01EE4D48(tab);
    func_01EE38C4((void **)sec);
    ret = 1;
    *(s32 *)((u8 *)arg0 + 0x144) = 1;
    return ret;
}
