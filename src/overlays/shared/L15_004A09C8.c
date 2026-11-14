#include "common.h"

extern void func_L01_00627BD8(u32);

// Clear the linked flag at +0x1AC and release the handle at +0x1A8 if set.
void func_L15_004A09C8(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    u32 handle = *(u32 *)(linked + 0x1A8);
    linked[0x1AC] = 0;
    if (handle != 0xFFFFFFFF) {
        func_L01_00627BD8(handle);
        *(u32 *)(linked + 0x1A8) = 0xFFFFFFFF;
    }
}
