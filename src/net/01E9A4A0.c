/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x24]; s32 f24; char _p28[0x8]; } Type1;
extern s32 func_0012CB20(char *);
extern void func_001294F0(char *, ...);
extern void func_00127A08(s32);
extern s32 func_0012A538(Type1 *, s32, s32);
extern char D_001941A0[];
extern char D_001941B0[];
extern char D_001941B8[];
extern char D_001941C8[];
extern char D_001941E0[];
extern Type1 D_001AD380;
extern s32 D_001AD3A8;
extern s32 D_001AD3AC;
s32 func_01E9A4A0(void) {
    s32 id;
    char *name = D_001941A0;
    D_001AD3A8 = id = func_0012CB20(name);
    if (id < 0) {
        func_001294F0(D_001941B0, D_001941B8);
        func_001294F0(D_001941C8, name);
        D_001AD3AC = 0;
    } else {
        while (1) {
            if (func_0012A538(&D_001AD380, 0x75488909, 0) < 0) {
                func_001294F0(D_001941B0, D_001941B8);
                func_001294F0(D_001941E0);
            }
            if (D_001AD380.f24 != 0) {
                break;
            }
            func_00127A08(10000);
        }
        D_001AD3AC = 1;
    }
    return (id > 0) ? 0 : id;
}
