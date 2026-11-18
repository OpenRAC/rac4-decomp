#include "common.h"

extern void func_00449A28(void *, void *, void *);
extern s32 func_00472DF8(void *, s32, s32);
extern void func_L02_003C6408(void *object);
extern void func_L02_003C67F8(void);
extern u8 *D_0021E758;
extern s32 D_00222610;
extern u8 D_0022CE40[];
extern s32 D_002665C0[];

// Handle the linked object's state checks and queue the follow-up call.
void func_L02_003C5A60(void *object) {
    s32 *linked = *(s32 **)((u8 *)object + 0xAC);
    u8 *state;
    if (linked[0x5C / 4] != -1 && func_00472DF8(D_0022CE40, linked[0x5C / 4], 0) == 0) return;
    state = D_0021E758;
    *(s16 *)(state + 0x3C6) = 2;
    if (*((u8 *)object + 0x20) == 0) func_L02_003C6408(object);
    if (D_002665C0[0] != linked[0x50 / 4]) return;
    if (func_00472DF8(D_0022CE40, linked[0x54 / 4], 0) != 0) return;
    if (func_00472DF8(D_0022CE40, linked[0x58 / 4], 0) != 0) return;
    func_00449A28(&D_00222610, (void *)func_L02_003C67F8, object);
}
