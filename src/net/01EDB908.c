/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EDB438(u32 arg0);
extern s32 func_01EDB798(void *arg0, void *arg1);

s32 func_01EDB908(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        return -0x15;
    }
    if (arg1 == NULL) {
        return -0x15;
    }
    *(s32 *)((u8 *)arg0 + 0x34) = func_01EDB438(-1);
    *(s32 *)((u8 *)arg0 + 0x38) = *(s32 *)((u8 *)arg1 + 0x14);
    *(u8 *)((u8 *)arg0 + 0x30) = 1;
    return func_01EDB798(arg0, arg1);
}
