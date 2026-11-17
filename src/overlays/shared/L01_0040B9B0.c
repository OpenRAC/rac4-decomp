#include "common.h"

extern s32 D_00395320[][6];
/* If the linked block has an index, copy it to +0x68 and clear its table entry. */
void func_L01_0040B9B0(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    if (*(s32 *)(linked + 0xB4) != -1) {
        object[0x68] = *(s32 *)(linked + 0xB4);
        D_00395320[*(s32 *)(linked + 0xB8)][*(s32 *)(linked + 0xB4)] = 0;
    }
}
