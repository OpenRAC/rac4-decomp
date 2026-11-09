/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 (*D_004A192C)();

s32 func_L00_00520A68(void) {
    if (D_004A192C != NULL) {
        return D_004A192C();
    }
    return 0;
}
