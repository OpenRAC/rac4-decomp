#include "common.h"

extern void func_00499CE0(s32 arg0);
extern void func_0049B0D8(s32 arg0);
extern void func_0049C4B0(s32 slot, s32 offset, s32 id, s32 mode);
extern void func_004C94C8(void);
extern s32 D_2218D8;
extern u8 D_30D188[];

/* Frees the five pending entries of the table at D_30D188, then calls the setup functions. */
void func_004C86A0(void) {
    u8 *base;

    func_0049C4B0(0, 0, D_2218D8, 0);
    func_004C94C8();
    base = D_30D188;
    if (*(s32 *)(base + 0x138C) != 0) {
        func_00499CE0(*(s32 *)(base + 0x138C));
        *(s32 *)(base + 0x138C) = 0;
    }
    if (*(s32 *)(base + 0x1390) != 0) {
        func_00499CE0(*(s32 *)(base + 0x1390));
        *(s32 *)(base + 0x1390) = 0;
    }
    if (*(s32 *)(base + 0x1394) != 0) {
        func_00499CE0(*(s32 *)(base + 0x1394));
        *(s32 *)(base + 0x1394) = 0;
    }
    if (*(s32 *)(base + 0x1398) != 0) {
        func_00499CE0(*(s32 *)(base + 0x1398));
        *(s32 *)(base + 0x1398) = 0;
    }
    if (*(s32 *)(base + 0x139C) != 0) {
        func_00499CE0(*(s32 *)(base + 0x139C));
        *(s32 *)(base + 0x139C) = 0;
    }
    func_0049B0D8(0);
}
