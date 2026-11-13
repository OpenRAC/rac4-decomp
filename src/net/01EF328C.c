/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_01EE3A18();
extern s32 func_01EEE028(s32);
extern s64 func_00126718(s32, s32, s32);
extern void func_01F0C090(const char *, s32);
extern char D_0019C6B8[];

s32 func_01EF328C(s32 arg0, s32 arg1, s32 *arg2)
{
    void *v = (void *)func_01EE3A18();

    if (v != 0) {
        if (*(s8 *)v == 0x23 && func_01EEE028(*(s8 *)((char *)v + 1)) != 0) {
            *arg2 = (s32)func_00126718((s32)v + 1, 0, 0x10);
            return 1;
        }
        func_01F0C090(D_0019C6B8, 0xF1);
    }
    return 0;
}
