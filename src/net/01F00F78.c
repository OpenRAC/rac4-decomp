/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01F00D68();
extern void func_01F00E54(void *, s32);
extern void func_01F02AE0(void *, s32, s32);
extern void func_01F02C18(void *, s32);

typedef struct {
    s32 f0;
    s32 f4;
} Inner;

typedef struct {
    u8 pad0[0x80];
    Inner *f80;
    u8 pad84[0x38];
    s32 fBC;
    u8 padC0[0xBC];
    s32 f17C;
} Obj;

// Steps the object's state from the events reported for it and returns 1 when none applied.
s32 func_01F00F78(Obj *arg0, s32 arg1) {
    s32 s0;
    s32 a1;

    s0 = arg0->f80->f4;
    if (arg0->f17C == 0) {
        if (func_01F00D68() != 0) {
            return 0;
        }
        if (arg0->fBC <= 0) {
            return 1;
        }
        if (func_01EED8A4(s0, 0x11, 0x10) != 0) {
            arg0->f17C = 1;
            return 0;
        }
        return 1;
    }
    if (func_01EED8A4(s0, 0x11, 0x11) != 0) {
        arg0->f17C = 0;
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 2) != 0) {
        func_01F02C18(arg0, -2);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 3) != 0) {
        func_01F02C18(arg0, 2);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 0) != 0) {
        func_01F02C18(arg0, -1);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 1) != 0) {
        func_01F02C18(arg0, 1);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 0x10) != 0) {
        func_01F00E54(arg0, arg1);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 5) != 0) {
        func_01F02AE0(arg0, 1, 1);
        return 0;
    }
    if (func_01EED8A4(s0, 0x11, 4) != 0) {
        func_01F02AE0(arg0, -1, 1);
        return 0;
    }
    return 1;
}
