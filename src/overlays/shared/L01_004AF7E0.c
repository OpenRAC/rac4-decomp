#include "common.h"

extern u8 *func_006658C0(s32);
extern void func_L00_006CB868(void *, s32);
extern s32 *D_0021DDA4;
s32 D_00221DC8 __attribute__((section(".sdata"))) = 0;

s32 func_L01_004AF7E0(u8 *arg0) {
    u8 *linked = *(u8 **)(arg0 + 0xAC);
    s32 *slots;
    s32 i;

    D_00221DC8 = 0;
    if (linked[0x90] != 0) return 1;
    i = 0;
    if (*D_0021DDA4 > 0) {
        slots = (s32 *)(linked + 0x80);
        do {
            u8 *q = func_006658C0(i);
            u16 *src = (u16 *)((i << 6) + (u32)linked);
            s32 off = 0;
            s32 j;

            for (j = 0x1F; j >= 0; j--) {
                *(u16 *)(*(u32 *)(q + 0x26E4) + off + 0xA32) = *src++;
                off += 0x44;
            }
            func_L00_006CB868(q, *(s32 *)((u32)slots + (i << 2)));
            i++;
        } while (i < *D_0021DDA4);
    }
    return 1;
}
