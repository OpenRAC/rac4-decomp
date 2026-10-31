#include "common.h"

extern s32 func_004978C0(s32 i);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00548DA0();

/* Fetch the record for the current owner, then call func_00548DA0 with its word at 0x26E4 and func_004978C0(arg0). */
void func_004C2F28(s32 arg0) {
    void *temp_s0;

    temp_s0 = func_00510BE8(func_00505B20());
    func_00548DA0(*(s32 *)((u8 *)temp_s0 + 0x26E4), func_004978C0(arg0));
}
