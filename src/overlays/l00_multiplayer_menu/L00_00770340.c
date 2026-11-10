#include "common.h"

void func_L00_00770D40(s32 object, u8 *arg1);

void func_L00_00770340(void *object) {
    (*(s32 *)((s8 *)(object) + (0x18))) = 0x2710;
    (*(s8 *)((s8 *)(object) + (0))) = 0;
    (*(s8 *)((s8 *)(object) + (0xC))) = 0;
    (*(s8 *)((s8 *)(object) + (0x14))) = 0;
    (*(s32 *)((s8 *)(object) + (0x1C))) = -1;
    (*(s8 *)((s8 *)(object) + (0x20))) = 0;
    (*(s32 *)((s8 *)(object) + (0x24))) = -1;
    (*(s32 *)((s8 *)(object) + (0x28))) = -1;
    func_L00_00770D40((*(s32 *)((s8 *)(object) + (0x48))), (u8 *)object + 0x30);
}
