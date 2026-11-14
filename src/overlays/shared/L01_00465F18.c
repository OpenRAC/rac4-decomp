#include "common.h"

extern void func_L01_00465ED0(void *arg0, s32 arg1, s32 arg2, s16 arg3);
extern void func_L01_00465EF0(u8 *object, s32 slot);

// Re-store the slot's own values through func_L01_00465ED0, then clear the slot.
void func_L01_00465F18(u8 *object, s32 arg1, s32 slot) {
    u8 *base = *(u8 **)(object + 0xAC);
    s32 *p32 = (s32 *)(base + slot * 4 + 0x20);
    s16 *p16 = (s16 *)(base + slot * 2 + 0x10);
    func_L01_00465ED0(object, arg1, *p32, *p16);
    func_L01_00465EF0(object, slot);
}
