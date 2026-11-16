#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A5D0(void *, u8 *);
extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern u8 D_00220C88[];

void func_L00_00717958(u8 *arg0, char *arg1) {
    u8 *s0;

    if (arg1 == 0) {
        arg0[0x60] = 0;
        s0 = arg0 + 0x60;
    } else {
        s0 = arg0 + 0x60;
        func_0011AFC8((char *)s0, arg1, 0xC8);
        arg0[0x127] = 0;
    }
    func_0011A518(arg0 + 0x3D4, 0, 0xC8);
    {
        s32 t = func_0011AB04(s0);
        if (t > 0) {
            s32 n = t;
            do {
                func_0011A5D0(arg0 + 0x3D4, D_00220C88);
            } while (--n != 0);
        }
    }
    *(s32 *)(arg0 + 0x230) = 0;
}
