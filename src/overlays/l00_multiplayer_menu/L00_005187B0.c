/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_0051AEE0(u8 *object);

/* Frees the object's sub-record at 0x1C, clearing it, and returns 0. */
s32 func_L00_005187B0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s32 *p = *(s32 **)(obj + 0x1C);

    if (p != 0) {
        if (*p != 0) {
            *p = 0;
        }
        func_L00_0051AEE0(*(u8 **)(obj + 0x1C));
        *(s32 *)(obj + 0x1C) = 0;
    }
    return 0;
}
