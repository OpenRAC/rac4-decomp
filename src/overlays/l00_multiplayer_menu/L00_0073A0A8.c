#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_L00_0073A230(void *arg0, s32 arg1);
extern s32 func_L00_007698F0(u8 *arg0);
extern s32 D_002233A4;

// Rebuilds the choice list at +0xD04 from the table of the current entry when the selection at +0x83C changes.
void func_L00_0073A0A8(u8 *a0) {
    u8 *cur;
    u8 *tab;
    u8 *ent;
    u8 **slot;
    s32 i;
    s32 cnt;
    s32 lim;
    s32 sel;
    s32 v;

    cur = *(u8 **)((u8 *)D_002233A4 + 0x3C);
    tab = NULL;
    if (*(u8 *)(cur + 0x3D0) != 0) {
        if (*(s32 *)(cur + 0x3D4) >= 0) {
            tab = cur + (*(s32 *)(cur + 0x3D4) * 0xC + 0x3E8);
        }
    }
    if (*(s32 *)cur == -1) {
        *(s32 *)(a0 + 0x840) = 0;
        return;
    }
    if (*(u8 *)(a0 + 0x838) != 0 && *(u8 *)(cur + 0x3D8) == 0) {
        *(s32 *)(a0 + 0x83C) = *(s32 *)(cur + 0x3E0);
        func_L00_007698F0(cur);
        *(u8 *)(a0 + 0x838) = 0;
    }
    if (tab != NULL && *(s32 *)(cur + 0x3E0) != *(s32 *)(a0 + 0x83C)) {
        *(s32 *)(a0 + 0x83C) = *(s32 *)(cur + 0x3E0);
        i = 0;
        cnt = 0;
        v = *(s32 *)(tab + 4);
        lim = v;
        if (v > 0x40) {
            lim = 0x40;
        }
        *(s32 *)(a0 + 0x840) = lim;
        sel = *(s32 *)(*(u8 **)((u8 *)D_002233A4 + 0x34));
        if (lim > 0) {
            slot = (u8 **)(a0 + 0xD04);
            do {
                ent = ((u8 **)*(u8 **)(tab + 8))[i];
                if (func_L00_0073A230(a0, *(s32 *)(ent + 0x1C)) == 0 && *(s32 *)(ent + 0x1C) != sel && *(s32 *)(ent + 0x140) != 0) {
                    cnt += 1;
                    func_0011AFC8(*slot, ent + 0x20, 0xE);
                    (*slot)[0xE] = 0;
                    *(s32 *)((u8 *)slot - 0x4C0) = *(s32 *)(ent + 0x1C);
                    slot += 1;
                }
                i += 1;
            } while (i < *(s32 *)(a0 + 0x840));
        }
        *(s32 *)(a0 + 0x840) = cnt;
    }
}
