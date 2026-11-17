#include "common.h"

extern void func_0069CC48(void *, s32, s32);
extern s32 func_0069D5D8(s32 handle, u32 resource);
extern void func_007122C8(void *);

// Switches the active slot to arg1 and returns the result of the new slot's call.
s32 func_L00_00712458(void *arg0, s32 arg1) {
    s32 temp;

    if (*(s32 *)((u8 *)arg0 + 0x60) == arg1) {
        return 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x64) == -1) {
        return 0;
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) == -1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x60) = arg1;
    if (*(u8 *)((u8 *)arg0 + 0x6C) != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x78) == 0) {
            *(u8 *)((u8 *)arg0 + 0x78) = 1;
            temp = *(s32 *)((u8 *)arg0 + 0x74) + 1;
            *(s32 *)((u8 *)arg0 + 0x74) = temp % 2;
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x64) != -1) {
        func_0069CC48(*(void **)((u8 *)arg0 + 0x64), 0x8000, *(u8 *)((u8 *)arg0 + 0x6C) ^ 1);
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) != -1) {
        func_0069CC48(*(void **)((u8 *)arg0 + 0x68), 0x8000, *(u8 *)((u8 *)arg0 + 0x6C) ^ 1);
    }
    func_007122C8(arg0);
    return func_0069D5D8(*(s32 *)((u8 *)arg0 + (*(s32 *)((u8 *)arg0 + 0x74) << 2) + 0x64),
                         *(s32 *)((u8 *)arg0 + 0x60) + 1);
}
