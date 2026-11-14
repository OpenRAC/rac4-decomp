/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01E9D390(void *);
extern void func_00127A08(s32);
extern s32 func_01E9B788(void *, s32, void *, s32, s32);
extern s32 func_01E9B290(s32);
extern s32 D_00167EF4;
extern s32 D_00167EF8;
s32 func_01E9D740(void *a, void *b) {
    s32 i;
    i = 1000;
    while (i--) {
        func_01E9D390(a);
        func_00127A08(100);
    }
    if (func_01E9B788(a, 0x38, b, 0, 4) < 0) {
        return -0x21E;
    }
    i = 1000;
    while (i--) {
        func_01E9D390(a);
        func_00127A08(100);
    }
    if (func_01E9B290(D_00167EF4) != 0) {
        return -0x21C;
    }
    if (func_01E9B290(D_00167EF8) != 0) {
        return -0x21C;
    }
    D_00167EF8 = 0;
    D_00167EF4 = 0;
    return 0;
}
