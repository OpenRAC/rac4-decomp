#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct Slot {
    u128 q[0x5C];
} Slot;

extern s32 D_0021DE98;
extern s32 D_0021EC58;
extern s32 D_0021DE3C;
extern s32 D_0021E894;
extern u8 *D_00222E14;
extern u8 *D_00222E2C;
extern u8 *D_003660F8[10];
extern s32 D_00171250[];
extern Slot D_00397320[];

void func_L01_005C2048(s32);
void func_L01_0055FE88(void *, s32, s32);
void func_L01_005DBDA8(s32, s32);

// Add PAL C for func_L01_00457468
void func_L01_00457468(void) {
    u8 *m;
    u8 *pv;
    u8 *pl;
    s32 i;
    s32 idx;

    if (D_0021DE98 != 1 && D_0021DE98 != 0x15) {
        return;
    }
    if (D_0021EC58 != 8 && D_0021DE3C != 2 && D_0021DE3C != 1 && D_0021E894 != 2 && D_0021E894 != 1) {
        return;
    }
    for (m = D_00222E14; m < D_00222E2C; m += 0x100) {
        if (*(s16 *)(m + 0xBC) != 0x2120) {
            continue;
        }
        pv = *(u8 **)(m + 0xAC);
        if (*(u8 **)(pv + 0x48) == 0 || *(s32 *)(pv + 0x4C) != 0 || m[0x20] >= 0xE) {
            continue;
        }
        func_L01_005C2048(*(s32 *)(*(u8 **)(pv + 0x48) + 0x2F00));
        func_L01_0055FE88(*(u8 **)(*(u8 **)(pv + 0x48) + 0x2F00) + 0x354, 0, 0x1C);
        *(u128 *)(*(u8 **)(pv + 0x48) + 0x120) = 0;
        for (i = 0, pl = D_003660F8[0]; i < 10; pl = D_003660F8[++i]) {
            if (pl != 0) {
                *(s16 *)(pl + 0x3BA) = 0x19;
                func_L01_005DBDA8(*(s32 *)(pl + 0x2F10), 0x19);
            }
        }
        *(s32 *)(pv + 0x4C) = *(s32 *)(*(u8 **)(pv + 0x48) + 0x2F00);
        D_00397320[pv[0x3C]] = **(Slot **)(pv + 0x4C);
        *(Slot **)(*(u8 **)(pv + 0x48) + 0x2F00) = &D_00397320[pv[0x3C]];
        idx = *(s32 *)(*(u8 **)(pv + 0x48) + 0x2F10);
        pv[0x3E] = *(u8 *)&D_00171250[idx];
        if (D_00171250[*(s32 *)(*(u8 **)(pv + 0x48) + 0x2F10)] == 0) {
            D_00171250[*(s32 *)(*(u8 **)(pv + 0x48) + 0x2F10)] = 1;
        }
    }
}
