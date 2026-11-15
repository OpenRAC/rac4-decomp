#include "common.h"

extern void func_L00_0066CCE8(void *, s32);

/* Sets or clears the flags on this object and on each of the four entries of its list. */
void func_L01_004E6490(u8 *arg0, s32 arg1) {
    u8 *link;
    u8 *obj;
    u8 *state;
    u8 *list;
    u8 **entry;
    u16 flags;
    s32 n;

    state = *(u8 **)(arg0 + 0xAC);
    if (arg1 != 0) {
        flags = *(u16 *)(arg0 + 0x34);
        link = *(u8 **)(arg0 + 0x24);
        flags = flags & 0xFFBE;
        *(u16 *)(arg0 + 0x34) = flags;
        flags = flags | (*(u16 *)(link + 0x44) & 0x1000);
        *(u16 *)(arg0 + 0x34) = flags;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(link + 0x10);
    } else {
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_L00_0066CCE8(arg0, 1);
    }
    list = *(u8 **)(state + 0x2F4);
    if (list != 0) {
        entry = (u8 **)(*(u8 **)(list + 0xAC) + 0xD0);
        n = 3;
        do {
            obj = *entry;
            if (obj != 0) {
                if (arg1 != 0) {
                    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFFBE;
                    *(u16 *)(*entry + 0x34) = *(u16 *)(*entry + 0x34) | (*(u16 *)(*(u8 **)(*entry + 0x24) + 0x44) & 0x1000);
                    *(s32 *)(*entry + 0x98) = *(s32 *)(*(u8 **)(*entry + 0x24) + 0x10);
                } else {
                    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x41;
                    *(u16 *)(*entry + 0x34) = *(u16 *)(*entry + 0x34) & 0xEFFF;
                    *(s32 *)(*entry + 0x98) = 0;
                    func_L00_0066CCE8(*entry, 1);
                }
            }
            n -= 1;
            entry += 1;
        } while (n >= 0);
    }
}
