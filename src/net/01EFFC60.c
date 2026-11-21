/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01EEE39C(void);
extern s32 func_01EF4188(void *, s32, s32, s32, void *);
extern void func_01EFF30C(void *, s32);
extern void func_01F0C090(char *arg0, s32 arg1);
extern s32 D_0019DA98[];
extern char D_0019DB60[];

typedef struct {
    s32 f0;
    s32 f4;
} Inner;

typedef struct {
    u8 pad0[0x20];
    s32 (*f20)(void *);
} Vt;

typedef struct {
    u8 pad0[0xC];
    s32 (*fC)(void *, s32, void *);
} Vt2;

typedef struct {
    s32 f0;
    u8 pad4[0x7C];
    Inner *f80;
    u8 pad84[0x2C];
    Vt *fB0;
    u8 padB4[0xA0];
    void *f154;
} Obj;

// Checks the object's state and hands its handler and flags to func_01EF4188, returning 1 when nothing is to be done.
s32 func_01EFFC60(Obj *arg0, s32 arg1) {
    s32 s1;
    s32 s2;
    Vt2 **o;
    void **t;

    s1 = arg0->f80->f4;
    if (arg0->f0 == 0) {
        func_01F0C090((char *)D_0019DA98, 0x5D);
    }
    if (s1 == 0) {
        func_01F0C090((char *)D_0019DA98, 0x5E);
    }
    if (arg1 == 0) {
        func_01F0C090((char *)D_0019DA98, 0x5F);
    }
    t = (void **)arg0->fB0;
    t = (void **)t[8];
    if (((s32 (*)(Obj *))t)(arg0) == 0) {
        return 1;
    }
    if (func_01EED8A4(s1, 0x11, 0x10) != 0) {
        if (*(u32 *)((u8 *)arg0 + 0x154) == 0) {
            func_01F0C090((char *)D_0019DA98, 0x65);
        }
        func_01EFF30C(arg0->f154, arg1);
        o = (Vt2 **)func_01EEE39C();
        (*o)->fC(o, 1, D_0019DB60);
    }
    if (func_01EED8A4(s1, 0x11, 0) != 0 || func_01EED8A4(s1, 0x11, 1) != 0 || func_01EED8A4(s1, 0x11, 2) != 0
        || func_01EED8A4(s1, 0x11, 3) != 0) {
        s2 = arg0->f80->f0;
        if (s2 == 0) {
            func_01F0C090((char *)D_0019DA98, 0x71);
        }
        return func_01EF4188(arg0, s1, s2, arg0->f0, (void *)arg1) == 0;
    }
    return 1;
}
