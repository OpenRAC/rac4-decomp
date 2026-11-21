/* cflags: @ee296 -O2 -G0 */
#include "common.h"
s32 func_003F66F0(s32, s32, s32 *);
s32 func_003F6978(s32, s32, s32, s32);
s32 func_003F69F0(s32);
s32 func_003F7208(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 h;
    if (func_003F66F0(b, d, &h) != 0 || func_003F6978(h, a, c, e) != 0) {
        return -1;
    }
    return func_003F69F0(h) == 0 ? 0 : -1;
}
