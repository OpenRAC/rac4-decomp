#include "common.h"
extern void func_004E1A58(void *, s32);
void func_L01_004FA510(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0xAC);
    u8 *q;
    s32 i;
    u8 **pp;
    if (arg1 != 0) {
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(u8 **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
    } else {
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_004E1A58(arg0, 1);
    }
    q = *(u8 **)(p + 0x228);
    if (q != 0) {
        pp = (u8 **)(*(u8 **)(q + 0xAC) + 0xD0);
        for (i = 3; i >= 0; i--) {
            if (*pp != 0) {
                if (arg1 != 0) {
                    *(u16 *)(*pp + 0x34) &= 0xFFBE;
                    *(u16 *)(*pp + 0x34) |= *(u16 *)(*(u8 **)(*pp + 0x24) + 0x44) & 0x1000;
                    *(s32 *)(*pp + 0x98) = *(s32 *)(*(u8 **)(*pp + 0x24) + 0x10);
                } else {
                    *(u16 *)(*pp + 0x34) |= 0x41;
                    *(u16 *)(*pp + 0x34) &= 0xEFFF;
                    *(s32 *)(*pp + 0x98) = 0;
                    func_004E1A58(*pp, 1);
                }
            }
            pp++;
        }
    }
}
