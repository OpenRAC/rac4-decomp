/* Not matching yet: BYTES 22/108 (tools/try_func.py func_01ED0BE0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

void *func_01ED2458();

void *func_01ED0BE0(s32 arg0, u32 arg1) {
    void *temp_v1;
    void *var_v0;
    s32 temp_a0;

    temp_v1 = func_01ED2458(arg0);
    if (temp_v1 == NULL) {
        return temp_v1;
    }
    var_v0 = NULL;
    if (*(u8 *)(temp_v1 + 0x78) != 0xFF) {
        if (arg1 < *(u32 *)(temp_v1 + 0x10)) {
            temp_a0 = *(s32 *)(temp_v1 + 0x88);
            if (temp_a0 != 0) {
                var_v0 = (void *)(temp_a0 + arg1 * *(u32 *)(temp_v1 + 0x14) * 2);
            }
        }
    }
    return var_v0;
}
