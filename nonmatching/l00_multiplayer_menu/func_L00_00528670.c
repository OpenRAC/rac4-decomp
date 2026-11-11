/* Not matching yet: BYTES 28/416 (tools/try_func.py func_L00_00528670 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    void *f0;
    void *f4;
} Type2;

typedef struct Type1 {
    char _p0[0x4];
    Type2 *f4;
    s32 f8;
    char _pC[0x40 - 0xC];
    Type2 f40[8];
} Type1;

typedef struct Type3 {
    s32 f0;
    s32 f4;
    char f8[4];
    s32 fC;
} Type3;

extern char D_004AE7E0[];

s32 func_L00_00527598(s32);
void func_L00_004F84C8(int, int, int, int, int);
s32 func_004F7BE0(void *);
void func_L00_00507DC8(s32, Type3 *);
void func_L00_00519EC8(void);
s32 func_L00_005269F0(s32);
s32 func_004F81D8(void *, Type3 *);
void func_L00_004F79A0(void *);
void func_004F8220(void *);
s32 func_L00_004FAAF0(void *, s32, s32, void *, s32);

s32 func_L00_00528670(Type1 *arg0, Type3 *arg1) {
    s32 i;
    s32 ok = 0;

    i = func_L00_00527598(0);
    if (i < 0) {
        func_L00_004F84C8(0x14, 0xC2, 0xF7, 0, 0);
        return 0;
    }
    if (arg0->f40[i].f0 != 0) {
        func_L00_00507DC8(func_004F7BE0(arg0->f40[i].f0), arg1);
        func_L00_00519EC8();
        if (arg1->f0 != 6 || !(func_L00_005269F0(arg1->fC) & 1)) {
            if (func_004F81D8(arg0->f40[i].f0, arg1) == 0) {
                if (i == 3 || i == 4) {
                    i = (i == 3) ? 4 : 3;
                    if (arg0->f40[i].f0 != 0) {
                        ok = func_004F81D8(arg0->f40[i].f0, arg1) == 0;
                    }
                } else {
                    ok = 1;
                }
            }
        }
    }
    if (ok) {
        func_L00_004F79A0(arg0->f40[i].f0);
        arg0->f40[i].f0 = 0;
        return 0;
    }
    if (arg0->f40[i].f4 != 0) {
        func_004F8220(arg0->f40[i].f4);
    }
    func_L00_004FAAF0(arg1->f8, 1, 0xA, D_004AE7E0, 0x11A);
    arg0->f40[i].f4 = arg1;
    arg0->f8 = 0;
    arg0->f4 = &arg0->f40[i];
    return 1;
}
