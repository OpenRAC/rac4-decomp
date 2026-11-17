#include "common.h"

extern s32 func_0069D6C0(s32 handle, u32 value);
extern void func_L00_007162A0(void *);

// Stores the word at 0xF80, passes each handle to func_0069D6C0 with 2, then refreshes.
s32 func_L00_00715FB8(void *arg0, s32 arg1) {
    s32 i;

    *(s32 *)((u8 *)arg0 + 0xF80) = arg1;
    for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x68); i++) {
        func_0069D6C0(*(s32 *)((u8 *)arg0 + 0x6C + i * 4), 2);
    }
    func_L00_007162A0(arg0);
    return 1;
}
