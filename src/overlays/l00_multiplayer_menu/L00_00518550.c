/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_0051A628(void *);

/* Free the object's handle if set. */
s32 func_L00_00518550(void *arg0) {
    void *h = *(void **)((u8 *)arg0 + 0x1C);
    if (h != 0) {
        func_L00_0051A628(h);
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    }
    return 0;
}
