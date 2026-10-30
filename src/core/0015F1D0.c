#include "common.h"

extern s32 func_01EC94C0(void *arg0);

// If arg2 is not -2 and func_01EC94C0 returns 0 for a local slot, sets bit arg2 in the word at +0xB4 of the object at +0x1C of that slot's pointer.
void func_0015F1D0(s32 arg0, s32 arg1, s32 arg2) {
    void *obj;
    u8 *sub;

    if (arg2 != -2) {
        obj = 0;
        if (func_01EC94C0(&obj) == 0) {
            sub = *(u8 **)((u8 *)obj + 0x1C);
            *(s32 *)(sub + 0xB4) = *(s32 *)(sub + 0xB4) | (1 << arg2);
        }
    }
}
