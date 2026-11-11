#include "common.h"

extern void func_00453FE8(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x470 - 0x54]; } S_0043A9D0;
extern S_0043A9D0 D_00229D80[];
extern u8 D_0022B310[];
extern u8 D_00234010[];

/* PAL: from rac3-decomp's func_00382A80 */
void func_0043A9D0(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;
    temp_s2 = (arg0 * 0xB0) + D_0022B310;
    { S_0043A9D0 *p = &D_00229D80[arg0]; func_00453FE8(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_00234010;
    func_00453FE8(temp_s0, temp_s1 + (D_00234010 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
