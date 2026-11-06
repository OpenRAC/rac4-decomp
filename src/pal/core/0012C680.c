/* cflags: @ee29 -O2 -G0 */
/* C adapted from rac3-decomp func_00123ED8 (NTSC-U func_00123ED8, commit 403f30a9) */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    char f8[0xFC];
    char f104[0xFC];
} Type1;

typedef struct {
    char f0[0xFC];
} Type2;

extern Type1 D_001A9580;
extern u8 D_001A9780[];
extern s32 func_0012C4B8(void);
extern s32 func_0012C5B8(void);
extern s32 func_0012A718();
extern void func_0011A370(void *, void *, s32);

/* Submits the bounded request payload and returns its status and size. */
s32 func_0012C680(s32 arg0, s32 arg1, s32 arg2, s32 *arg3)
{
    if (func_0012C4B8() < 0) {
        return 0xFFFF0000;
    }
    if (func_0012C5B8() != 0) {
        return 0xFFFEFFFC;
    }
    D_001A9580.f0 = arg0;
    if (arg2 != 0) {
        if (arg1 > 0xFC) {
            *(Type2 *)D_001A9580.f104 = *(Type2 *)arg2;
            D_001A9580.f4 = 0xFC;
        } else {
            func_0011A370(D_001A9580.f104, (void *)arg2, arg1);
            D_001A9580.f4 = arg1;
        }
    } else {
        D_001A9580.f4 = 0;
    }
    if (func_0012A718(D_001A9780, 6, 0, &D_001A9580, 0x200, &D_001A9580, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    {
        s32 var1 = D_001A9580.f0;
        *arg3 = D_001A9580.f4;
        return var1;
    }
}
