/* Not matching yet: BYTES 61/92 (tools/try_func.py func_L00_00520AB4 --diff). Not part of the build. */
/* cflags: -G0 -malign-jumps=3 */
#include "common.h"

extern s32 func_L00_0052D408(u8 *object);

void *func_L00_00520AB4(u8 *arg0) {
    u8 buf[0x18];

    if (arg0 == NULL) {
        return NULL;
    }
    if (func_L00_0052D408(buf) != 0) {
        return NULL;
    }
    memcpy(arg0, buf + 8, 8);
    *(s32 *)(arg0 + 8) = *(s32 *)(buf + 0x10);
    return arg0;
}
