#include "common.h"

extern u8 *D_00222714;

void func_L00_005DD4A0(void *object);

void func_L11_00407CA0(void *object)
{
    u8 *data = *(u8 **)((u8 *)object + 0xAC);
    s32 index = *(s32 *)data;

    if (index == -1) {
        func_L00_005DD4A0(object);
    } else {
        u8 *entry = D_00222714 + ((u32)index << 8);

        *((u8 *)object + 0x20) = entry[0x20];
        *(s32 *)((u8 *)object + 0x60) =
            *(s32 *)(entry + 0x60);
    }
}
