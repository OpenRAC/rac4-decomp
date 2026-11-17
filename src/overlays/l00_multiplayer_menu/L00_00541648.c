/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_004FAD28(void *);
extern void *func_L00_004FACD8();

/* Packs the entries' buffers into one new allocation. */
s32 func_L00_00541648(u8 *arg0) {
    s32 i;
    s32 total;
    u8 **list;
    u8 *buf;
    u8 *dst;
    u8 *e;
    u8 *f;

    total = 0;
    list = *(u8 ***)(arg0 + 0xC);
    for (i = 0; i < *(s32 *)(arg0 + 4); i++) {
        f = list[i];
        if (*(s32 *)(f + 0xC) != 0) {
            total += *(s32 *)(f + 0x10);
        }
    }
    dst = func_L00_004FACD8(total);
    if (dst == 0) {
        return 2;
    }
    buf = dst;
    for (i = 0; i < *(s32 *)(arg0 + 4); i++) {
        e = list[i];
        if (*(s32 *)(e + 0xC) != 0 && *(s32 *)(e + 0x10) != 0) {
            func_0011A370(dst, *(u8 **)(e + 0xC), *(s32 *)(e + 0x10));
            if (*(s32 *)(e + 0x14) & 2) {
                func_004FAD28(*(void **)(e + 0xC));
            }
            *(u8 **)(e + 0xC) = dst;
            *(s32 *)(e + 0x14) = *(s32 *)(e + 0x14) & ~2;
            dst += *(s32 *)(e + 0x10);
        }
    }
    if (*(void **)(arg0 + 0x10) != 0) {
        func_004FAD28(*(void **)(arg0 + 0x10));
    }
    *(u8 **)(arg0 + 0x10) = buf;
    return 0;
}
