/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EB2EE0(u8 *);
extern s32 func_01EB37A8(s32, s32, u8 *);
s32 func_01EB3838(s32 a, s32 b, u8 *key) {
    u8 buf[64];
    s32 i;
    if (func_01EB2EE0(key) != 0) {
        return -1;
    }
    if (func_01EB37A8(a, b, buf) != 0) {
        return 1;
    }
    i = 63;
    do {
        if (key[i] > buf[i]) {
            return 1;
        }
        if (key[i] < buf[i]) {
            return -1;
        }
    } while (i-- > 0);
    return 0;
}
