/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(const char *, s32);
extern s32 D_0019E698[];

/* Removes the entry that the object's vtable slot 0x80 returns from the list at 0xC0. */
s32 func_01F0B5E0(u8 *p) {
    s32 (*fn)(u8 *);
    s32 cc;
    s32 d4;
    s32 count;
    s32 r;
    s32 i;
    s32 *list;

    fn = *(s32 (**)(u8 *))(*(u8 **)(p + 0xB0) + 0x80);
    r = fn(p);
    if (r == -1) {
        return 0;
    }
    cc = *(s32 *)(p + 0xCC);
    if (r >= cc) {
        func_01F0C090((const char *)D_0019E698, 0x1D6);
        return 0;
    }
    i = r;
    while (i < *(s32 *)(p + 0xCC) - 1) {
        list = *(s32 **)(p + 0xC0);
        list[i] = list[i + 1];
        if (*(s32 *)(p + 0xD0) == i + 1) {
            *(s32 *)(p + 0xD0) = i;
        }
        i++;
    }
    d4 = *(s32 *)(p + 0xD4);
    if (r < d4 + *(s32 *)(p + 0xC8)) {
        if (d4 > 0) {
            *(s32 *)(p + 0xD4) = d4 - 1;
        }
    }
    count = *(s32 *)(p + 0xCC) - 1;
    *(s32 *)(p + 0xCC) = count;
    (*(s32 **)(p + 0xC0))[count] = 0;
    return 1;
}
