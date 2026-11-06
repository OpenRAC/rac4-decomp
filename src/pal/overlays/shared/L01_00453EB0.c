/* cflags:  */
#include "common.h"

// Calls func_L01_00453948 when the moby's state (+0x20) is 0, then sets pvar+0x16 to 1.

typedef struct Type2 {
    char _p0[18];
    u8 f16;
} Type2;

typedef struct Type1 {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAC - 0x21];
    Type2 *fAC;
} Type1;

extern void func_L01_00453948(Type1 *arg0);

void func_L01_00453EB0(Type1 *arg0) {
    Type2 *p = arg0->fAC;

    if (arg0->f20 == 0) {
        func_L01_00453948(arg0);
    }
    p->f16 = 1;
}
