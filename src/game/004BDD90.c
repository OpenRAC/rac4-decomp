#include "common.h"

extern void func_0049B148(s32 arg0, s32 arg1);
extern void func_0049C290(s32 param, s32 count);
extern void func_0049D280(s32, s32);
extern char D_30B358[];

/* Clear three gp byte flags, run func_0049D280 and func_0049C290, set the record at D_30B358 (byte 8 = 1, word 0xC = 0x1E), then call func_0049B148(0, 0). */
u8 D_0021F93A = 0;
u8 D_0021F939 = 0;
u8 D_0021F938 = 0;

void func_004BDD90(void) {
    u8 *rec;

    rec = (u8 *)D_30B358;
    D_0021F93A = 0;
    D_0021F939 = 0;
    D_0021F938 = 0;
    func_0049D280(0, 0);
    func_0049C290(0, 0);
    *(s32 *)(rec + 0xC) = 0x1E;
    rec[8] = 1;
    func_0049B148(0, 0);
}
