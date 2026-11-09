/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_0011AFC8(s8 *, s8 *, s32);
extern s8 D_00169CE0[];

s32 func_01ED5D30(s8 *arg0) {
    if (D_00169CE0[0] == 0) {
        return -0xB;
    }
    func_0011AFC8(arg0, D_00169CE0, 0x11);
    return 0;
}
