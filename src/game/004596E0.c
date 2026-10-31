#include "common.h"

extern s32 D_21DA7C;
extern s32 *D_221E20;

/* Writes four words of a display-list entry at D_221E20 and advances it by 16 bytes. */
void func_004596E0(void) {
    D_221E20[0] = 0x30000009;
    D_221E20[1] = (D_21DA7C + 0xC0) & 0x0FFFFFFF;
    D_221E20[2] = 0;
    D_221E20[3] = 0x50000009;
    D_221E20 += 4;
}
