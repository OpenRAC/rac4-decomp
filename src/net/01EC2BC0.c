/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Runs func_01EC3240 over slots 0 to 10 of the object, returns 2 when it is NULL. */
extern s32 func_00126880();
extern s32 func_01EC3240(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EC3238(void);

s32 func_01EC2BC0(s32 arg0) {
    s32 (*fn)(void);
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        fn = func_01EC3238;
        func_01EC3240(0, func_00126880(0, fn, -1), arg0);
        func_01EC3240(1, func_00126880(1, fn, -1), arg0);
        func_01EC3240(2, func_00126880(2, fn, -1), arg0);
        func_01EC3240(3, func_00126880(3, fn, -1), arg0);
        func_01EC3240(4, func_00126880(4, fn, -1), arg0);
        func_01EC3240(5, func_00126880(5, fn, -1), arg0);
        func_01EC3240(6, func_00126880(6, fn, -1), arg0);
        func_01EC3240(7, func_00126880(7, fn, -1), arg0);
        func_01EC3240(8, func_00126880(8, fn, -1), arg0);
        func_01EC3240(9, func_00126880(9, fn, -1), arg0);
        func_01EC3240(0xA, func_00126880(0xA, fn, -1), arg0);
        var_v0 = 0;
    }
    return var_v0;
}
