#include "common.h"

void func_L00_00778508(void *object, void *queue);

void func_L00_00777B98(void *object) {
    (*(s8 *)((s8 *)(object) + (0))) = 0;
    (*(s32 *)((s8 *)(object) + (4))) = -1;
    (*(s32 *)((s8 *)(object) + (8))) = -1;
    (*(s8 *)((s8 *)(object) + (0xC))) = 0;
    (*(s8 *)((s8 *)(object) + (0xD))) = 0;
    func_L00_00778508((*(void **)((s8 *)(object) + (0x20))), (u8 *)object + 0x14);
}
