/* cflags: @ee29 -O2 -G8 */
#include "common.h"

// Complex shift and register operation with conditional function calls
extern s64 func_0013EC48(void *);
extern void func_0013EFD8(void *);

u32 func_0013EEB0(void *arg0, s32 arg1) {
    s32 temp_v1;

    if (*(s32 *)((u8 *)arg0 + 0x828) != 0 || *(s32 *)((u8 *)arg0 + 0x84C) < arg1) {
        func_0013EFD8(arg0);
        *(volatile s32 *)0x10002000 = 0x40000000;
        *(s32 *)((u8 *)arg0 + 0x828) = 0;
        *(s32 *)((u8 *)arg0 + 0x82C) = 0x40000000;
        *(s32 *)((u8 *)arg0 + 0x848) = (s32)func_0013EC48(arg0);
        *(s32 *)((u8 *)arg0 + 0x84C) = 0x20;
    }

    temp_v1 = *(s32 *)((u8 *)arg0 + 0x848);
    return (u32)temp_v1 >> (-arg1);
}
