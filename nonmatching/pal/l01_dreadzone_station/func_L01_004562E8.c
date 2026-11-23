/* Not matching yet: PAL WIP; level_01 .text 0x004562E8, 296B. Not part of the build. */
/*
 * Native has two complete MULT/store/reload/config-store kernels and separate mode-owned return
 * regions. The two tested normal control families retain one common kernel and fold config field
 * addends into selected bases.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: c3217249bc8bc9fc67c4234d39dd7d27e6d6b1939f7513782a19ad10c07f6063
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004562E8 nonmatching/pal/l01_dreadzone_station/func_L01_004562E8.c --diff
 */
#include "common.h"

extern s32 D_00171250[];
extern s32 D_00171EF8[][10];
extern s32 D_00171E80[][10];
extern u8 D_00171DB8[];

/* Store the requested state fields, then reset the selected inactive mode. */
void func_L01_004562E8(void *object, s32 mode, s16 value, s8 kind)
{
    u8 *state = *(u8 **)((u8 *)object + 0xAC);
    *(s16 *)(state + 0x40) = value;
    *(s8 *)(state + 0x3F) = kind;

    if (mode == 1 && *(s32 *)(state + 0x68) == 0) {
        u8 *player = *(u8 **)(state + 0x48);
        u32 index = (u32)*(s32 *)(player + 0x2F10);
        u32 slot = state[0x3C];
        u32 row = (u32)*(s32 *)((u8 *)D_00171250 + (index << 2));
        *(s32 *)((u8 *)D_00171EF8 + row * 0x28U + (slot << 2)) = 0;

        player = *(u8 **)(state + 0x48);
        slot = state[0x3C];
        index = (u32)*(s32 *)(player + 0x2F10);
        row = (u32)*(s32 *)((u8 *)D_00171250 + (index << 2));
        *(s32 *)(D_00171DB8 + row * 0x10U + (slot << 2) + 0x48) = 0;
        return;
    }

    if (mode == 2 && *(s32 *)(state + 0x6C) == 0) {
        u8 *player = *(u8 **)(state + 0x48);
        u32 index = (u32)*(s32 *)(player + 0x2F10);
        u32 slot = state[0x3C];
        u32 row = (u32)*(s32 *)((u8 *)D_00171250 + (index << 2));
        *(s32 *)((u8 *)D_00171E80 + row * 0x28U + (slot << 2)) = 0;

        player = *(u8 **)(state + 0x48);
        slot = state[0x3C];
        index = (u32)*(s32 *)(player + 0x2F10);
        row = (u32)*(s32 *)((u8 *)D_00171250 + (index << 2));
        *(s32 *)(D_00171DB8 + row * 0x10U + (slot << 2) + 0x18) = 0;
    }
}
