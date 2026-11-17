#include "common.h"

extern void func_L00_007107F0(void *arg0, void *arg1);

/* copies counts and two 32-entry tables from the descriptor, resets state and calls the method at 0xE8 */
void func_L00_00715788(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 count;

    func_L00_007107F0(arg0, arg1);
    *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg1 + 0x40);
    count = *(s32 *)(arg1 + 0x44);
    *(s32 *)(arg0 + 0x68) = count;
    if (count > 0x20) {
        *(s32 *)(arg0 + 0x68) = 0x20;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0x68); i++) {
        if (*(s32 **)(arg1 + 0x48) != 0) {
            ((s32 *)(arg0 + 0x6C))[i] = (*(s32 **)(arg1 + 0x48))[i];
        } else {
            ((s32 *)(arg0 + 0x6C))[i] = 0;
        }
        if (*(u32 **)(arg1 + 0x4C) != 0) {
            ((u32 *)(arg0 + 0xEC))[i] = (*(u32 **)(arg1 + 0x4C))[i];
        } else {
            ((u32 *)(arg0 + 0xEC))[i] = 0xFFFFFFFF;
        }
    }
    *(s32 *)(arg0 + 0xB6C) = 0;
    *(s32 *)(arg0 + 0xB74) = -1;
    *(s32 *)(arg0 + 0xB70) = 0;
    *(s32 *)(arg0 + 0xB78) = 0;
    (*(void (**)(void *, s32))(*(u8 **)(arg0 + 0x58) + 0xE8))(arg0, *(s32 *)(arg1 + 0x50));
    *(s32 *)(arg0 + 0xF80) = 0;
}
