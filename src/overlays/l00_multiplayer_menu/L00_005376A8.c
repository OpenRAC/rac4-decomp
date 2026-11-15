/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);

/* Calls the callback at arg0+4, then the one at arg0->0->0x14 when arg0+0xC is set; otherwise reports -2 after logging. */
s64 func_L00_005376A8(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *obj;
    void *cb;
    s64 r;

    if (arg0 == NULL || *(u8 **)arg0 == NULL || *(void **)(*(u8 **)arg0 + 0x14) == NULL) {
        func_L00_004F84C8(0x20, 0x66, 0x6F, 0, 0);
        return -2;
    }
    cb = *(void **)(arg0 + 0x4);
    if (cb != NULL) {
        r = (s32)((s64 (*)(u8 *, s32, s32, s32, s32, s32))cb)(arg0, 5, arg1, arg2, 0, 1);
        if (r <= 0) {
            return r;
        }
    }
    if (*(s32 *)(arg0 + 0xC) == 0) {
        func_L00_004F84C8(0x20, 0x66, 0x6E, 0, 0);
        return -2;
    }
    obj = *(u8 **)arg0;
    r = ((s64 (*)(u8 *, s32, s32))*(void **)(obj + 0x14))(arg0, arg1, arg2);
    if (cb != NULL) {
        r = (s32)((s64 (*)(u8 *, s32, s32, s32, s32, s64))cb)(arg0, 0x85, arg1, arg2, 0, r);
    }
    return r;
}
