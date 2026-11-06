#include "common.h"

extern s32 D_0021EE54;
extern s32 D_001C20C0[];
extern u8 D_00171250[];
extern u8 D_00171DB8[];
extern s32 D_0021DE98;
extern s32 D_001719C8[];
extern void func_0045CE68(s32, void *);
extern void func_0048A6E0(s32);
extern void func_00163550(s32);
extern s32 func_001638B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_00453F30(void *, const void *, u32);
extern void func_00466940(s32);
extern void func_00466640(s32);

void func_00466A20(void) {
    u8 workspace[0x110];
    u8 *output;
    s32 arg;
    s32 value;
    s32 *state;
    if (D_0021EE54 == 1) {
        return;
    }
    output = workspace + 0x100;
    state = D_001C20C0;
    func_0045CE68(state[0x664 / 4] << 11, output);
    func_0048A6E0(1);
    func_00163550(1);
    arg = state[0x660 / 4] + state[0x64C / 4];
    func_001638B0(0, *(s32 *)output, arg, state[0x664 / 4], 0, 0, 0);
    value = *(s32 *)output;
    value += *(s32 *)(value + 0x10);
    func_00453F30(workspace, D_00171250, 0x28);
    func_00453F30(workspace + 0x30, D_00171DB8, 0xC4);
    func_00466940(value);
    func_00453F30(D_00171250, workspace, 0x28);
    func_00453F30(D_00171DB8, workspace + 0x30, 0xC4);
    D_0021DE98 = 1;
    if (D_001719C8[0x1E4 / 4] != 0) {
        D_001719C8[0x1E4 / 4] = 0;
    }
    if (*(s16 *)((u8 *)D_001719C8 + 0x18) >= 0) {
        *(s16 *)((u8 *)D_001719C8 + 0x18) = -1;
    }
    func_00466640(7);
}
