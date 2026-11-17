#include "common.h"

extern void func_L00_005B0038(void *, void *, void *);
extern s32 func_L00_005E6058(void *, s32, s32);
extern void func_L02_003C6090(void *object);
extern void func_L02_003C6480(void);
extern u8 *D_0021E6D8;
extern s32 D_222510;
extern u8 D_22CD40[];
extern s32 D_2664C0[];

// Handle the linked object's state checks and queue the follow-up call.
void func_L02_003C56E8(void *object) {
    s32 *linked = *(s32 **)((u8 *)object + 0xAC);
    u8 *state;
    if (linked[0x5C / 4] != -1 && func_L00_005E6058(D_22CD40, linked[0x5C / 4], 0) == 0) return;
    state = D_0021E6D8;
    *(s16 *)(state + 0x3C6) = 3;
    if (*((u8 *)object + 0x20) == 0) func_L02_003C6090(object);
    if (D_2664C0[0] != linked[0x50 / 4]) return;
    if (func_L00_005E6058(D_22CD40, linked[0x54 / 4], 0) != 0) return;
    if (func_L00_005E6058(D_22CD40, linked[0x58 / 4], 0) != 0) return;
    func_L00_005B0038(&D_222510, (void *)func_L02_003C6480, object);
}
