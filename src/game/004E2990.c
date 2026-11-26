#include "common.h"

extern s32 D_1DFA70[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Entry3;

extern Entry3 D_323680[];
extern void func_00453718(void *, const void *, u32);

s32 func_004E2990(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 idx;
    s32 ret;
    s32 off;

    off = arg2 << 4;
    if (D_1DFA70[1] - (D_1DFA70[12] - D_1DFA70[0]) < off) {
        return -1;
    }
    if (D_1DFA70[13] == 0x40) {
        return -2;
    }
    func_00453718((void *)D_1DFA70[12], (const void *)arg0, (u32)(arg1 << 4));
    idx = D_1DFA70[13];
    ret = idx;
    idx++;
    D_323680[ret].unk0 = D_1DFA70[12];
    D_323680[ret].unk4 = arg2;
    D_323680[ret].unk8 = arg3;
    D_1DFA70[13] = idx;
    D_1DFA70[12] += off;
    return ret;
}
