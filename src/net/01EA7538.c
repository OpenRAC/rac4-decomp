/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4C];
    s32 (*f4C)();
};

extern s32 func_01EA8270(void *);
extern s32 func_01EA8350(void *);
extern s32 func_01EA8CF0();
extern Type1 *D_00167F34;
extern s32 D_00167F8C;
extern s32 D_001B2188;
extern s32 D_001B23B0;

s32 func_01EA7538(void) {
    s32 var_v0;

    if (D_00167F8C != 0) {
        var_v0 = func_01EA8270(&D_001B2188);
        if ((var_v0 == 0) && (var_v0 = D_00167F34->f4C(), (var_v0 == 0)) && (var_v0 = func_01EA8350(&D_001B2188), (var_v0 == 0))) {
            if ((D_001B23B0 == 0) || (var_v0 = func_01EA8CF0(), (var_v0 == 0))) {
                goto block_6;
            }
        }
    } else {
block_6:
        var_v0 = 0;
    }
    return var_v0;
}
