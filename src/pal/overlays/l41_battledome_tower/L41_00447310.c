/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern void func_004E29B8(void *, s32);

void func_L41_00447310(void *object) {
    void *data;
    void *child_a;
    void *child_b;
    void *current_a;
    void *current_b;

    data = *(void **)((u8 *)object + 0xAC);
    child_a = *(void **)((u8 *)data + 0x18);
    if (child_a != NULL) {
        *(u16 *)((u8 *)child_a + 0x34) |= 0x41;
        current_a = *(void **)((u8 *)data + 0x18);
        *(u16 *)((u8 *)current_a + 0x34) &= 0xEFFF;
        *(s32 *)((u8 *)*(void **)((u8 *)data + 0x18) + 0x98) = 0;
        func_004E29B8(*(void **)((u8 *)data + 0x18), 1);
    }
    child_b = *(void **)((u8 *)data + 0x1C);
    if (child_b != NULL) {
        *(u16 *)((u8 *)child_b + 0x34) |= 0x41;
        current_b = *(void **)((u8 *)data + 0x1C);
        *(u16 *)((u8 *)current_b + 0x34) &= 0xEFFF;
        *(s32 *)((u8 *)*(void **)((u8 *)data + 0x1C) + 0x98) = 0;
        func_004E29B8(*(void **)((u8 *)data + 0x1C), 1);
    }
    *(s32 *)((u8 *)object + 0x98) = 0;
    *(u16 *)((u8 *)object + 0x34) = (*(u16 *)((u8 *)object + 0x34) | 0x41) & 0xEFFF;
    func_004E29B8(object, 1);
}
