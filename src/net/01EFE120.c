/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type2 Type2;
struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8[6];
    s32 (*f20)(void *);
};
typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s8 pad4[0x7C];
    Type2 *f80;
    s8 pad84[0x2C];
    Type2 *fB0;
    s8 padB4[0xD8];
    s32 f18C;
};
extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01EF4188();
extern void func_01EFF24C(s32, void *);
extern void func_01F0C090(const char *, s32);
extern char D_0019D938[];

/* Checks the object's handler slots, then runs the request step through func_01EF4188 when the handler test passes. */
s32 func_01EFE120(Type1 *arg0, s32 arg1) {
    s32 s1;
    s32 s2;

    s1 = arg0->f80->f4;
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019D938, 0x7B);
    }
    if (s1 == 0) {
        func_01F0C090(D_0019D938, 0x7C);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019D938, 0x7D);
    }
    if (arg0->fB0->f20(arg0) != 0) {
        if (func_01EED8A4(s1, 0x11, 0x10) != 0) {
            if (arg0->f18C == 0) {
                func_01F0C090(D_0019D938, 0x83);
            }
            func_01EFF24C(arg0->f18C, arg0);
        }
        if (func_01EED8A4(s1, 0x11, 0) != 0 || func_01EED8A4(s1, 0x11, 1) != 0 || func_01EED8A4(s1, 0x11, 2) != 0 || func_01EED8A4(s1, 0x11, 3) != 0) {
            s2 = arg0->f80->f0;
            if (s2 == 0) {
                func_01F0C090(D_0019D938, 0x8D);
            }
            return func_01EF4188(arg0, s1, s2, arg0->f0, arg1) == 0;
        }
        return 1;
    }
    return 1;
}
