#include "common.h"

extern s32 D_0039D140[][6];
/* If the linked block has an index, copy it to +0x68 and clear its table entry. */
void func_L01_00479FE8(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    if (*(s32 *)(linked + 164) != -1) {
        object[0x68] = *(s32 *)(linked + 164);
        D_0039D140[*(s32 *)(linked + 168)][*(s32 *)(linked + 164)] = 0;
    }
}
