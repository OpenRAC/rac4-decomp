#include "common.h"

void func_L00_007719E0(s32 object, u8 *arg1);

void func_L00_00770DB0(void *object) {
    (*(s32 *)((s8 *)(object) + (4))) = -1;
    (*(s8 *)((s8 *)(object) + (8))) = 0;
    (*(s32 *)((s8 *)(object) + (0xC))) = -1;
    (*(s32 *)((s8 *)(object) + (0x10))) = -1;
    (*(s8 *)((s8 *)(object) + (0x1C))) = 0;
    (*(s8 *)((s8 *)(object) + (0x24))) = 0;
    func_L00_007719E0((*(s32 *)((s8 *)(object) + (0x48))), (u8 *)object + 0x30);
}
