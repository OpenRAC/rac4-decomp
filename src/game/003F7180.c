/* cflags: @ee296 -O2 -G0 */
#include "common.h"
s32 func_003F6B90(s32, s32 *);
s32 func_003F7090(s32, s32, s32, s32);
s32 func_003F7118(s32);
s32 func_003F7180(s32 a, s32 b, s32 c, s32 d) {
    s32 h;
    if (func_003F6B90(b, &h) != 0 || func_003F7090(h, a, c, d) != 0) {
        return -1;
    }
    return func_003F7118(h) == 0 ? 0 : -1;
}
