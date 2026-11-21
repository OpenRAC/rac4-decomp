#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_00505B70(s32 index, s32 handle);
extern void *func_0054A980(s32 arg0);
extern s32 func_0054AA00(void);
extern void *func_0054AA30(void);
extern s32 func_0054AAD8(s32 arg0);
extern s32 D_0021DE10;
extern s32 D_0021F198;
extern s32 D_221768;

/* Points slot 0xA of the handle group at the entry for the current game state. */
void func_004B57C0(void) {
    s32 mode;
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;
    s32 *temp_s0;
    s32 *temp_s0_2;

    func_00501638(&D_221768, 0x1A, -1);
    func_00505B70(0xD, D_221768);
    if (D_0021DE10 == 1 || D_0021DE10 == 0x15) {
        mode = D_0021F198;
        if (mode == 13) {
            var_s1 = 0x363D;
        } else if (mode == 17) {
            var_s1 = 0x363E;
        } else if (mode == 21) {
            var_s1 = 0x363F;
        } else {
            var_s1 = ((mode ^ 0x1C) != 0) ? 0 : 0x3640;
        }
        var_s0 = func_004A1A60(&D_221768, 4);
        var_a0 = var_s1;
        goto block_12;
    }
    temp_s0 = (s32 *)func_0054A980(func_0054AAD8(D_0021DE10));
    if (temp_s0[4] == func_0054AA00()) {
        var_s0 = func_004A1A60(&D_221768, 4);
        var_a0 = temp_s0[1];
block_12:
        func_00505238(var_s0, func_0045E038(var_a0));
        func_00504F68(func_004A1A60(&D_221768, 0xA), 0);
        return;
    }
    temp_s0_2 = (s32 *)func_0054AA30();
    var_s1 = func_004A1A60(&D_221768, 4);
    func_00505238(var_s1, func_0045E038(temp_s0_2[2]));
    var_s1 = func_004A1A60(&D_221768, 0xA);
    func_00505238(var_s1, func_0045E038(temp_s0_2[4]));
    func_00504F68(func_004A1A60(&D_221768, 0xA), 1);
}
