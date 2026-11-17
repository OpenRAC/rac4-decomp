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
extern s32 D_0021EDD4;
extern void func_00489D80(void);

/* Starts a transfer of table entry arg0 when the shared panel state is busy with a set entry. */
void func_00489130(s32 arg0, s32 arg1, s32 arg2) {
    u8 *st = (u8 *)D_206948;
    u8 *p;
    Type1 *bank;
    u32 cur;
    s32 lo;
    s64 start;
    s64 end;

    if (*(s16 *)(st + 0x4E) != 9) {
        cur = *(u32 *)(st + 0x44);
        if (cur != 0 && cur != 0xFFFFFFFFu) {
            bank = D_1C2040;
            lo = bank->fD820[arg0 + 1].f0;
            if (lo != 0) {
                *(s16 *)(st + 0x4E) = 9;
                *(s16 *)(st + 0x4A) = arg2;
                *(s32 *)(st + 0x58) = 10;
                *(s32 *)(st + 0x5C) = 0xBB80;
                *(s16 *)(st + 0x48) = arg0;
                *(s16 *)(st + 0x4C) = arg1;
                *(s16 *)(st + 0x54) = 0;
                if (D_0021EDD4 == 1) {
                    start = lo + bank->fD81C;
                    end = bank->fD820[arg0].f0 + bank->fD81C;
                } else {
                    end = bank->fD820[arg0 + 2].f0 + bank->fD81C;
                    start = bank->fD820[arg0 + 3].f0 + bank->fD81C;
                }
                p = (u8 *)D_206948;
                func_00159258(start, end, 0, 0, *(s16 *)(p + 0x4A), 0, 1, cur, 0, (arg1 & 1) * 4, (s32)func_00489D80, (s64)(u32)(p + 0x44));
            }
        }
    }
}
