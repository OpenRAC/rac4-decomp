/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

/* checks the two links of the object at arg0, runs its hooks for the flags at 0x98 and 0x9C, then returns 1 */
extern u32 func_01EED8A4(s32, s32, s32);
extern void func_01F0C090(const char *, s32);
extern char D_0019DFE8[];

typedef struct Type1 Type1;
typedef struct { char _p0[0x68]; void (*f68)(Type1 *, s32); void (*f6C)(Type1 *, s8); } Type2;
struct Type1 { s32 f0; char _p4[0x7C]; s32 *f80; char _p84[0x14]; s32 f98; s32 f9C; char _pA0[0x10]; Type2 *vt; };

s32 func_01F03D08(Type1 *arg0, s32 arg1) {
    s32 temp_s1;
    u32 var_a1;

    temp_s1 = arg0->f80[1];
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019DFE8, 0xA);
    }
    if (temp_s1 == 0) {
        func_01F0C090(D_0019DFE8, 0xB);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019DFE8, 0xC);
    }
    if (arg0->f98 != 0) {
        arg0->vt->f68(arg0, temp_s1);
    }
    if ((arg0->f9C != 0) && (((var_a1 = func_01EED8A4(temp_s1, 0x11, 4)) != 0) || ((var_a1 = func_01EED8A4(temp_s1, 0x11, 5)) != 0))) {
        arg0->vt->f6C(arg0, var_a1);
    }
    return 1;
}
