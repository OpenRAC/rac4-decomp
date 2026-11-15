/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern void *func_L00_004FACD8();

/* Allocates the object and its two 0x400-byte buffers; returns 1 on success, 0 on failure */
s32 func_L00_00515CE8(void *arg0) {
    void *p;
    void *b;

    p = func_L00_004FACD8(0x20);
    if (p == 0) {
        return 0;
    }
    b = func_L00_004FACD8(0x400);
    *(void **)((u8 *)p + 0x8) = b;
    if (b == 0) {
        goto fail;
    }
    b = func_L00_004FACD8(0x400);
    *(void **)((u8 *)p + 0x14) = b;
    if (b == 0) {
        func_004FAD28(*(void **)((u8 *)p + 0x8));
fail:
        func_004FAD28(p);
        return 0;
    }
    *(s32 *)((u8 *)p + 0xC) = 0;
    *(s32 *)((u8 *)p + 0x0) = 0x400;
    *(s32 *)((u8 *)p + 0x4) = 0x400;
    *(s32 *)((u8 *)p + 0x10) = 0;
    *(s32 *)((u8 *)p + 0x18) = 0;
    *(s32 *)((u8 *)p + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 1;
    *(void **)((u8 *)arg0 + 0x20) = p;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    return 1;
}
