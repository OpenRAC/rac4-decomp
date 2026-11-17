/* cflags: @ee296 -Os -G0 -fno-optimize-sibling-calls -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
struct Type2 {
    char _p0[0x4];
    s32 f4;
};
struct Type3 {
    char _p0[0x20];
    s32 (*f20)();
};
struct Type1 {
    char _p0[0x80];
    Type2 *f80;
    char _p84[0x2C];
    Type3 *fB0;
};

s32 func_01EED8A4(s32, s32, s32);
s32 func_01EEE12C();
void func_01EEF814(s32, s32, void *);
void func_01F0C090(void *, s32);
extern s32 D_0019C7B8;

void func_01EF3D40(Type1 *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0->f80->f4;
    if (temp_s2 == 0) {
        func_01F0C090(&D_0019C7B8, 0xF7);
    }
    temp_s1 = func_01EEE12C();
    if (arg0->fB0->f20(arg0) != 0) {
        func_01EEF814(temp_s1, 8, arg0);
        if (func_01EED8A4(temp_s2, 0x11, 0x10) != 0) {
            func_01EEF814(temp_s1, 0, arg0);
        }
    }
}
