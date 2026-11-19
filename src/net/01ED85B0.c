/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern s32 func_01ED8528();

s32 *func_01ED85B0(void *arg0) {
    s32 i;

    if (arg0 == 0) {
        return 0;
    }
    i = func_01ED8528();
    if (i == 0xFFFF) {
        return 0;
    }
    return ((s32 **)(*(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 8)))[i];
}
