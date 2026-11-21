/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void func_004FAD28(void *);
extern void *func_L00_004FACD8();
extern void *func_L00_0051A740(void);
extern void func_L00_0051A7B8(void *);
extern s32 func_L00_00525E80(void *arg0, void *arg1, s32 arg2);
extern s64 func_L00_00528810(void);
extern s32 D_004A1998[];

/* creates, destroys, queries and advances a counter object hung off a context */
s32 func_L00_00526030(s32 *ctx, s32 arg1, void *arg2) {
    u8 *s;
    s64 v;

    switch (arg1) {
    case 1:
        if (ctx == 0) {
            ctx = D_004A1998;
        }
        s = func_L00_004FACD8(0x38);
        if (s == 0) {
            return 1;
        }
        {
            u8 *o = (u8 *)ctx[3];
            *(s32 *)(s + 0x18) = *(s32 *)(o + 0x18);
            *(s64 *)(s + 0) = *(s64 *)(o + 0);
            *(s64 *)(s + 8) = *(s64 *)(o + 8);
            *(s64 *)(s + 0x10) = *(s64 *)(o + 0x10);
            *(s64 *)(s + 0x28) = *(s64 *)(o + 0x28);
            *(s32 *)(s + 0x1C) = 0;
            *(s32 *)(s + 0x20) = *(s32 *)(o + 0x20);
            *(void **)(s + 0x24) = func_L00_0051A740();
            *(s32 *)(s + 0x30) = arg1;
            *(void **)((u8 *)arg2 + 0xC) = s;
        }
        return 0;
    case 2:
        if (ctx == 0) {
            ctx = D_004A1998;
        }
        s = (u8 *)ctx[3];
        if (s != 0) {
            if (*(void **)(s + 0x24) != 0) {
                func_L00_0051A7B8(*(void **)(s + 0x24));
                *(s32 *)(s + 0x24) = 0;
            }
            if (*(s32 *)(s + 0x30) & 1) {
                func_004FAD28((void *)ctx[3]);
            }
        }
        return 0;
    case 3:
        s = (u8 *)ctx[3];
        if (arg2 != 0) {
            *(s64 *)arg2 = *(s64 *)(s + 0x28);
            return 0;
        }
        return 0;
    case 16:
        s = (u8 *)ctx[3];
        v = func_L00_00528810();
        func_L00_00525E80(ctx, &v, 8);
        *(s64 *)(s + 0x28) = *(s64 *)(s + 0x28) + 1;
        return 0;
    default:
        return 0;
    }
}
