/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_001294F0(char *fmt, ...);
extern s32 func_00156120(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern char D_00195858[];
extern char D_00195890[];

// Rounds the two sizes up to 64 bytes and checks them against the room at arg0 + 0x30: reports through func_001294F0 and returns -0x21F when they do not fit, else forwards to func_00156120.
s32 func_01E9B788(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s1 = (arg3 + 0x3F) & ~0x3F;
    s32 s0 = (arg4 + 0x3F) & ~0x3F;
    s32 room = *(s32 *)((u8 *)arg0 + 0x30);

    if (room < s1 || room < s0) {
        func_001294F0(D_00195858);
        func_001294F0(D_00195890, arg1, s1, s0, room);
        return -0x21F;
    }
    return func_00156120(arg0, arg1, 0, arg2, s1, arg2, s0, 0, 0);
}
