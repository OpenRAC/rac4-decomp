#include "common.h"
extern void *D_002233A4;
void func_L00_00771868(void *arg0) {
    void *temp_v1;

    temp_v1 = (*(void **)((u8 *)D_002233A4 + 0x4C));
    (*(s8 *)((u8 *)(temp_v1) + 0x24)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x28)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
