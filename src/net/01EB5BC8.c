/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC;
extern s32 func_01E9D380(s32, s32 *);
s32 func_01EB5BC8(s32 arg0, s32 *arg1) {
    s32 x = 0;
    if (D_001694FC == 0) {
        return 5;
    }
    if (arg0 < 0) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    *arg1 = 0;
    if (func_01E9D380(arg0, &x) != 0) {
        return 0xC350;
    }
    if (x != 0) {
        *arg1 = 1;
    }
    return 0;
}
