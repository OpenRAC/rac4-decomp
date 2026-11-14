#include "common.h"

extern void func_L00_00717D98(u32 arg0);
extern s32 D_1EE600[];

/* Clears the 0x294 flag and the 0x264 slot of each used entry whose 0x5C0-byte record has bit 0x10 in its 0x1A8 field. */
void func_L00_00747908(void *arg0)
{
    u8 *owner = (u8 *)arg0;
    s32 *slot = (s32 *)(owner + 0x264);
    u8 *flags = owner + 0x294;
    u8 *tbl = (u8 *)D_1EE600;
    s32 stride = 0x5C0;
    s32 none = -1;
    s32 v;
    u32 i = 0;

    do {
        v = slot[0];
        if (~v != 0 && i != 0 && (*(s32 *)(tbl + v * stride + 0x1A8) & 0x10)) {
            flags[i] = 0;
            slot[0] = none;
            func_L00_00717D98(i);
            if (owner[0x299] != 0) {
                slot[8] = 0;
            }
        }
        i += 1;
        slot++;
    } while (i < 4);
}
