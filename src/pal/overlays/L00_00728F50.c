#include "common.h"
#include "pal/global_002234A4.h"

struct Context;
extern struct Context *D_00220DD4;

s32 func_L00_00728F50(void)
{
    u8 *profile = *(u8 **)((u8 *)D_002234A4 + 0x3C);
    s32 kind = *(s32 *)profile;
    struct Context *context = D_00220DD4;

    if (kind == -1) {
        u8 *node = *(u8 **)((u8 *)context + 0x108);
        u8 *selected = NULL;
        if (node != NULL) {
            if (node[0xA8] != 1) {
                node = NULL;
            }
            selected = node;
        }
        if (selected == NULL) {
            *(s32 *)((u8 *)context + 0x11C) = 7;
        }
        return 1;
    }

    if (profile[0x30] == 0) {
        u8 *node = *(u8 **)((u8 *)context + 0x108);
        u8 *selected = NULL;
        if (node != NULL) {
            if (node[0xA8] != 1) {
                node = NULL;
            }
            selected = node;
        }
        if (selected == NULL) {
            *(s32 *)((u8 *)context + 0x11C) = 5;
        }
        return 1;
    }
    return 0;
}
