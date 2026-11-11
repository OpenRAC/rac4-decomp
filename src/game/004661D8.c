#include "common.h"

extern s32 D_0021EDD4;
extern s32 D_001C2040[];
extern u8 D_001711D0[];
extern u8 D_00171D38[];
extern s32 D_0021DE10;
extern s32 D_00171948[];
extern void func_0045C670(s32, void *);
extern void func_00489C28(s32);
extern void func_001634A8(s32);
extern s32 func_00163808(s32, s32, s32, s32, s32, s32, s32);
extern void func_00453718(void *, const void *, u32);
extern void func_004660F8(s32);
extern void func_00465DF8(s32);

void func_004661D8(void) {
    u8 workspace[0x110];
    u8 *output;
    s32 arg;
    s32 value;
    s32 *state;
    if (D_0021EDD4 == 1) {
        return;
    }
    output = workspace + 0x100;
    state = D_001C2040;
    func_0045C670(state[0x664 / 4] << 11, output);
    func_00489C28(1);
    func_001634A8(1);
    arg = state[0x660 / 4] + state[0x64C / 4];
    func_00163808(0, *(s32 *)output, arg, state[0x664 / 4], 0, 0, 0);
    value = *(s32 *)output;
    value += *(s32 *)(value + 0x10);
    func_00453718(workspace, D_001711D0, 0x28);
    func_00453718(workspace + 0x30, D_00171D38, 0xC4);
    func_004660F8(value);
    func_00453718(D_001711D0, workspace, 0x28);
    func_00453718(D_00171D38, workspace + 0x30, 0xC4);
    D_0021DE10 = 1;
    if (D_00171948[0x1E4 / 4] != 0) {
        D_00171948[0x1E4 / 4] = 0;
    }
    if (*(s16 *)((u8 *)D_00171948 + 0x18) >= 0) {
        *(s16 *)((u8 *)D_00171948 + 0x18) = -1;
    }
    func_00465DF8(7);
}
