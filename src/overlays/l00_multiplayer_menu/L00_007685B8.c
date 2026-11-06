#include "common.h"
void func_L00_007685B8(void *arg0) {
    void *temp_v1;

    temp_v1 = (*(void **)((u8 *)(*(void **)0x2233A4) + 0x3C));
    (*(s8 *)((u8 *)(temp_v1) + 0x78)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x7C)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
