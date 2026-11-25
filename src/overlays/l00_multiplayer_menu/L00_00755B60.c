#include "common.h"
extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_0011D9A8(void *, const char *, ...);
extern u8 D_002215F0[];
extern void *D_0021DD70;
s32 func_L00_00755B60(s32 unused0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 result = 0;
    u32 value;
    u8 *p;
    (void)unused0;
    if (arg1 != 0 && func_0011AB04(arg1) != 0) {
        if (func_0011D9A8(arg1, (const char *)D_002215F0, &value) == 1) {
            p = arg1;
            if (*p++ != 0x20) { do { } while (*p++ != 0x20); }
            func_0011AFC8((char *)arg2, (char *)p, arg3);
            *((u8 *)(arg3 + arg2 - 1)) = 0;
            result = value != *(u32 *)((u8 *)D_0021DD70 + 8);
        }
    }
    return result;
}
