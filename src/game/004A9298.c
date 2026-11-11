#include "common.h"

extern s32 func_004989F0(s32 kind);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004A86E0(void);
extern void func_004A8B10(s32 slot, s32 kind);
extern void func_00504F68(s32, s32);
extern s32 func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_0054A7E0(void *, s32);
extern s32 D_0020C690[][3];
extern s32 D_00221650;

// Updates the three slot widgets of the current player from its loadout entries.
void func_004A9298(void)
{
    s32 index = func_00505B20();
    u8 *obj = func_00510BE8(index);
    s32 kind = func_004A86E0();
    s32 n = func_0054A7E0(*(void **)(obj + 0x26E4), kind);

    s32 i;

    func_004A8B10(func_004A1A60(&D_00221650, 0x33), kind);
    func_00504F68(func_004A1A60(&D_00221650, 0x34), n > 0);
    func_00505328(func_004A1A60(&D_00221650, 0x34), func_004989F0(n));

    for (i = 1; i < 3; i++) {
        s32 id = i + 0x27;
        func_004A8B10(func_004A1A60(&D_00221650, i + 0x25), D_0020C690[index][i]);
        n = func_0054A7E0(*(void **)(obj + 0x26E4), D_0020C690[index][i]);
        func_00504F68(func_004A1A60(&D_00221650, id), n > 0);
        func_00505328(func_004A1A60(&D_00221650, id), func_004989F0(n));
    }
}
