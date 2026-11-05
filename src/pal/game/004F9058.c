#include "common.h"
typedef struct State {
    u8 pad0[0x50];
    s32 count;
    u8 pad54[3];
    u8 enabled;
    u8 pad58[10];
    s8 mode;
} State;
extern u8 D_003DC090[];
u8 *D_00220A94 = D_003DC090;
extern u64 D_0020C740[];
extern s32 D_0021DF94, D_0021DFA0, D_0021DF54;
extern s32 D_00222074;
extern void func_004F8B18(u64 **, s32, s32);
extern void func_004F8AC8(u64 **, s32, s32);
void func_004F9058(void)
{
    u64 *begin = D_0020C740;
    u64 *cursor = begin;
    s32 i;
    if (!D_00220A94[0x57] && *(s8 *)(D_00220A94 + 0x62) == -1) {
        D_0021DF54 = 0;
        D_00222074 = D_0021DF94;
        return;
    }
    *cursor++ = 0x1000000000000005ULL;
    *cursor++ = 0xE;
    *cursor++ = 0;
    *cursor++ = 0x3F;
    *cursor++ = 0xA0000000A0ULL;
    *cursor++ = 0x19;
    *cursor++ = 0x100000000ULL;
    *cursor++ = 0x4F;
    *cursor++ = 0x60;
    *cursor++ = 0x15;
    *cursor++ = 5;
    *cursor++ = 9;
    *(s32 *)(D_00220A94 + 0x50) = *(s32 *)(D_00220A94 + 0x50) < 5 ? *(s32 *)(D_00220A94 + 0x50) : 4;
    if (*(s32 *)(D_00220A94 + 0x50) == 4) {
        func_004F8B18(&cursor, D_0021DF94, D_0021DFA0);
        D_00222074 = D_0021DFA0;
    } else {
        for (i = 0; i < *(s32 *)(D_00220A94 + 0x50); ++i)
            func_004F8AC8(&cursor, D_0021DF94, D_0021DFA0);
        D_00222074 = D_0021DF94;
    }
    D_0021DF54 = (s32)((u32)cursor - (u32)begin);
}
