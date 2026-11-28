#include "common.h"
#include "pal/menu_options.h"

extern s32 func_L00_00710358(s32 *values, s32 index);
extern void func_L00_007102F0(s32 index, u32 *word, s32 value);

/* Copy one indexed value into the selected packed setting. */
static inline void copy_setting(s32 *values, s32 index, u8 *settings, s32 base, s32 reverse_first_pair)
{
    u32 *word = 0;

    switch (D_L00_004B7310[index].kind) {
    case 1:
    case 10:
        break;
    case 2:
        word = (u32 *)(settings + base + (reverse_first_pair ? 4 : 0));
        break;
    case 3:
        word = (u32 *)(settings + base + (reverse_first_pair ? 0 : 4));
        break;
    case 4:
        word = (u32 *)(settings + base + 0x8);
        break;
    case 5:
        word = (u32 *)(settings + base + 0xC);
        break;
    case 6:
        word = (u32 *)(settings + base + 0x10);
        break;
    case 7:
        word = (u32 *)(settings + base + 0x14);
        break;
    case 8:
        word = (u32 *)(settings + base + 0x18);
        break;
    case 9:
        word = (u32 *)(settings + base + 0x1C);
        break;
    case 11:
        word = (u32 *)(settings + base + 0x20);
        break;
    case 12:
        word = (u32 *)(settings + base + 0x24);
        break;
    case 13:
        word = (u32 *)(settings + base + 0x28);
        break;
    case 14:
        word = (u32 *)(settings + base + 0x2C);
        break;
    case 15:
        word = (u32 *)(settings + base + 0x30);
        break;
    default:
        break;
    }
    if (word != 0) {
        func_L00_007102F0(index, word, func_L00_00710358(values, index));
    }
}

void func_L00_00710818(s32 *values, s32 index, u8 *settings)
{
    copy_setting(values, index, settings, 0x164, 1);
}

void func_L00_00710968(s32 *values, s32 index, u8 *settings)
{
    copy_setting(values, index, settings, 0x148, 0);
}
