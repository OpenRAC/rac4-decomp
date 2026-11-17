/* cflags: @ee296 -O2 -G0 */
#include "common.h"

void *func_01ED2458();
void func_01ECFD78(s32, u8);
void func_01ED2260(s32);

// Calls func_01ECFD78 with arg0 and the byte at 0x78 of the object func_01ED2458 returns (unless it is 0xFF), clears the word at 0x4 of that object and calls func_01ED2260 with arg0; returns 0, or 0x17 when func_01ED2458 returns NULL.
s32 func_01ED14A8(s32 arg0) {
    s32 var_v0;
    u8 *temp_v0;

    temp_v0 = func_01ED2458();
    var_v0 = 0x17;
    if (temp_v0 != NULL) {
        if (temp_v0[0x78] != 0xFF) {
            func_01ECFD78(arg0, temp_v0[0x78]);
        }
        *(s32 *)(temp_v0 + 4) = 0;
        func_01ED2260(arg0);
        var_v0 = 0;
    }
    return var_v0;
}
