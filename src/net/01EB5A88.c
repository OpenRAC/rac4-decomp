/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC;
extern u8 D_001B26C0[];
extern u8 D_001B2700[];
extern s32 func_01E9B978(void *, void *, s32, void *, s32, s32, s32);
extern s32 func_01EB4D80(void *);
s32 func_01EB5A88(s32 arg0, s32 *arg1) {
    s32 buf[4];
    if (D_001694FC == 0) {
        return 5;
    }
    if (arg0 == 0) {
        return 2;
    }
    if (func_01E9B978(D_001B26C0, D_001B2700, 0, buf, arg0, 0, 0) < 0) {
        return 0xC350;
    }
    *arg1 = func_01EB4D80(buf);
    return 0;
}
