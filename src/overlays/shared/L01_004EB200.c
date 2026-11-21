#include "common.h"

extern void func_L00_0066CCE8(void *, s32);

/* Sets or clears the flag bits of this object and of the entries of the table in its owner's child. */
void func_L01_004EB200(void *arg0, s32 arg1) {
    s32 i;
    s32 val;
    void **slot;
    void *owner;
    void *child;
    void *elem;
    void *p;
    s32 flags;

    owner = *(void **)((u8 *)arg0 + 0xAC);
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16)((*(u16 *)((u8 *)arg0 + 0x34) | 0x41) & 0xEFFF);
        func_L00_0066CCE8(arg0, 1);
        *(u16 *)((u8 *)arg0 + 0x34) = (u16)(*(u16 *)((u8 *)arg0 + 0x34) | 2);
    } else {
        flags = *(u16 *)((u8 *)arg0 + 0x34);
        p = *(void **)((u8 *)arg0 + 0x24);
        flags &= 0xFFBE;
        *(u16 *)((u8 *)arg0 + 0x34) = flags;
        flags = flags | (*(u16 *)((u8 *)p + 0x44) & 0x1000);
        *(u16 *)((u8 *)arg0 + 0x34) = flags;
        flags = flags & 0xFFFD;
        val = *(s32 *)((u8 *)p + 0x10);
        *(u16 *)((u8 *)arg0 + 0x34) = flags;
        *(s32 *)((u8 *)arg0 + 0x98) = val;
    }

    child = *(void **)((u8 *)owner + 0x2F4);
    if (child != NULL) {
        slot = (void **)((u8 *)*(void **)((u8 *)child + 0xAC) + 0xD0);
        for (i = 3; i >= 0; i--) {
            elem = *slot;
            if (elem != NULL) {
                if (arg1 != 0) {
                    void *e0;
                    *(u16 *)((u8 *)elem + 0x34) = (u16)(*(u16 *)((u8 *)elem + 0x34) | 0x41);
                    e0 = *slot;
                    *(u16 *)((u8 *)e0 + 0x34) = (u16)(*(u16 *)((u8 *)e0 + 0x34) & 0xEFFF);
                    *(s32 *)((u8 *)*slot + 0x98) = 0;
                    func_L00_0066CCE8(*slot, 1);
                } else {
                    void *e1;
                    void *e2;
                    *(u16 *)((u8 *)elem + 0x34) = (u16)(*(u16 *)((u8 *)elem + 0x34) & 0xFFBE);
                    e1 = *slot;
                    *(u16 *)((u8 *)e1 + 0x34) = (u16)(*(u16 *)((u8 *)e1 + 0x34) | (*(u16 *)((u8 *)*(void **)((u8 *)e1 + 0x24) + 0x44) & 0x1000));
                    e2 = *slot;
                    *(s32 *)((u8 *)e2 + 0x98) = *(s32 *)((u8 *)*(void **)((u8 *)e2 + 0x24) + 0x10);
                }
            }
            slot++;
        }
    } else {
        if (*(s32 *)((u8 *)owner + 0x358) != 0) {
            if (arg1 != 0) {
                *(s32 *)((u8 *)arg0 + 0x98) = 0;
                *(u16 *)((u8 *)arg0 + 0x34) = (u16)((*(u16 *)((u8 *)arg0 + 0x34) | 0x41) & 0xEFFF);
                func_L00_0066CCE8(arg0, 1);
                return;
            }
            flags = *(u16 *)((u8 *)arg0 + 0x34);
            p = *(void **)((u8 *)arg0 + 0x24);
            flags &= 0xFFBE;
            *(u16 *)((u8 *)arg0 + 0x34) = flags;
            flags = flags | (*(u16 *)((u8 *)p + 0x44) & 0x1000);
            *(u16 *)((u8 *)arg0 + 0x34) = flags;
            *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)p + 0x10);
        }
    }
}
