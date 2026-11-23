/* Not matching yet: PAL WIP; level_01 .text 0x004B0BD8, 116B. Not part of the build. */
/*
 * Prefix: native forms slotbase171BE9 directly intoa2 with indexv1/freeslota1. t02 retains real
 * profilebase171BC0 ina3 then forms a2=profile+29, indexa1/freeslotv1. At+10 t02 ADDIUslotsbase
 * replaces native indexedADDU; at+14 t02 indexedADDU replaces nativeNOP. No memory operation is
 * missing; native load delay is not reproduced.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 2dd617e28da6cb08c0c00384bf1dc64b141ef83902082b04361cdd88810dfe19
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004B0BD8 nonmatching/pal/l01_dreadzone_station/func_L01_004B0BD8.c --diff
 */
#include "common.h"

extern s32 D_00171B40[];

s32 func_L01_004B0BD8(s32 key)
{
    u8 *profile = (u8 *)D_00171B40;
    u8 *slots = profile + 0x29;
    s32 freeSlot = -1;
    s32 i = 0;

    do {
        u8 entry = slots[i];
        if (entry == key)
            return 1;
        if (entry == 0) {
            freeSlot = i;
            i = 4;
        }
        i++;
    } while (i < 4);
    if (freeSlot == -1)
        return 0;
    profile[freeSlot + 0x29] = (u8)key;
    return 1;
}
