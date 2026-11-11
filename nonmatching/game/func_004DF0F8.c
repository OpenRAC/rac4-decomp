/* Not matching yet: BYTES 67/448 (tools/try_func.py func_004DF0F8 --diff). Not part of the build. */
/* Note: this draft reads the scratchpad through a hardcoded address cast, which landing forbids; a landable version needs another shape. */
#include "common.h"

void func_004DF848(void);
s32 func_004DF8F0(s32, s32, s32, s32);
s32 func_004DFAE8(s32, s32, s32, s32, s32);
void func_004DFDD8(void *, s32, s32);
void func_004FE4A0(void);
void func_004FE4D8(void);
extern s32 D_00171750[];
extern s32 D_001717C0[];
extern s32 D_002209B8;
extern s32 D_00221E20;

void func_004DF0F8(s16 *arg0) {
    u8 *flags;
    u8 *ent;
    s32 alt;
    s32 drawn;
    s32 prev;
    s32 i;
    s32 base;
    s32 a;
    s32 b;

    if (arg0[0] == 0) {
        return;
    }
    ent = (u8 *)arg0 + 0x10;
    func_004FE4A0();
    func_004DFDD8(ent, arg0[0], 0x70003F00);
    func_004DF848();
    flags = (u8 *)0x70003F00;
    alt = (*(u16 *)((u8 *)arg0 + 2) >> 1) & 1;
    *(s32 *)D_00221E20 = 0x30000007;
    drawn = 0;
    *(s32 *)(D_00221E20 + 8) = 0;
    *(s32 *)(D_00221E20 + 0xC) = 0x50000007;
    if (alt) {
        *(s32 *)(D_00221E20 + 4) = (s32)D_001717C0;
    } else {
        *(s32 *)(D_00221E20 + 4) = (s32)D_00171750;
    }
    D_00221E20 += 0x10;
    prev = -1;
    for (i = 0; i < arg0[0]; i++) {
        if (*flags == 0) {
            base = *(s32 *)(ent + 0x10);
            b = base + *(s16 *)(ent + 0x1A);
            a = base + *(s16 *)(ent + 0x1C);
            if (func_004DF8F0(base + *(s16 *)(ent + 0x18), 0x70000000, *(s16 *)(ent + 0x14), *(s16 *)(ent + 0x1A)) == 0) {
                drawn = 1;
                prev = func_004DFAE8(*(s16 *)(ent + 0x16), a, b, 0x70000000, prev);
            }
        }
        ent += 0x20;
        flags++;
    }
    func_004FE4D8();
    if (alt && drawn) {
        D_002209B8 |= 4;
    }
}
