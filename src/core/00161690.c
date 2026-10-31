#include "common.h"

extern s32 func_00161568(void);
extern void func_00152058(s32, s32, s32, void *);

s32 D_0021E020 = 0;
s32 D_0021E028 = 0;
s32 D_0021E040 = 0;

/* Starts the subsystem once, then if it is enabled stores arg1 in a global, passes its address to func_00152058 and returns it. */
s32 func_00161690(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (D_0021E028 == 0) {
        func_00161568();
    }
    if (D_0021E028 == 1) {
        D_0021E040 = arg1;
        func_00152058(D_0021E020, 1, arg0, &D_0021E040);
        var_v0 = D_0021E040;
    }
    return var_v0;
}
