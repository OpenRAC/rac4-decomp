/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x24]; s32 f24; char _p28[0x8]; } Type1;
extern s32 func_0012CB20(char *);
extern void func_001294F0(char *, ...);
extern void func_00127A08(s32);
extern s32 func_0012A538(Type1 *, s32, s32);
extern char D_00193FD0[];
extern char D_00193FE0[];
extern char D_00193FE8[];
extern char D_00193FF8[];
extern char D_00194010[];
extern Type1 D_001AD1C0;
extern s32 D_001AD1E8;
extern s32 D_001AD1EC;
s32 func_01E9A000(void) {
    s32 id;
    char *name = D_00193FD0;
    D_001AD1E8 = id = func_0012CB20(name);
    if (id < 0) {
        func_001294F0(D_00193FE0, D_00193FE8);
        func_001294F0(D_00193FF8, name);
        D_001AD1EC = 0;
    } else {
        while (1) {
            if (func_0012A538(&D_001AD1C0, 0x75499128, 0) < 0) {
                func_001294F0(D_00193FE0, D_00193FE8);
                func_001294F0(D_00194010);
            }
            if (D_001AD1C0.f24 != 0) {
                break;
            }
            func_00127A08(10000);
        }
        D_001AD1EC = 1;
    }
    return (id > 0) ? 0 : id;
}
