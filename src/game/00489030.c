#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type2;

typedef struct {
    u8 pad0[0xD81C];
    s32 fD81C;
    Type2 fD820[1];
} Type1;

extern void func_00159258(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s64 arg11);
extern Type1 D_1C2040[];
extern s32 D_206948[];
extern void func_00489DD8(void);

/* Starts a transfer of table entry arg0 once the shared panel state is idle, for arg0 >= 0. */
void func_00489030(s32 arg0, s32 arg1, s32 arg2) {
    u8 *st;
    Type1 *bank;
    s32 lo;
    s64 start;
    s64 end;

    if (arg0 >= 0) {
        st = (u8 *)D_206948;
        if (*(s32 *)(st + 0x44) == 0) {
            bank = D_1C2040;
            lo = bank->fD820[arg0].f0;
            if (lo != 0) {
                *(u32 *)(st + 0x44) = 0xFFFFFFFFu;
                *(s16 *)(st + 0x4E) = 1;
                *(s32 *)(st + 0x58) = 10;
                *(s32 *)(st + 0x5C) = 0xBB80;
                *(s16 *)(st + 0x4C) = arg1;
                *(s16 *)(st + 0x48) = arg0;
                *(s16 *)(st + 0x4A) = arg2;
                *(s16 *)(st + 0x54) = 0;
                start = lo + bank->fD81C;
                end = bank->fD820[arg0 + 1].f0 + bank->fD81C;
                func_00159258(start, end, 0, 0, (s16)arg2, 0, 1, 0, 0, 0, (s32)func_00489DD8, (s64)(u32)(st + 0x44));
            }
        }
    }
}
