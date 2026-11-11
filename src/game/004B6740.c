/* cflags: -G0 -Wuninitialized -G8 */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

s32 func_0045E038(M2C_UNK);
void func_004A01F0(s32, s32);
void func_004B5DF8(s32);
void func_004B5E18(s32, s32, s32, s32);
typedef int (*Callback)();
M2C_UNK func_004B5E70(s32, Callback, s32);
extern u8 D_00171B66[];
u8 D_0021F7E9 = 0;
typedef struct { u8 pad[12]; s32 value; u8 tail[488]; } Record;
extern Record D_003098F0[];
extern int D_004B6C58();
extern int D_004B72E8();
extern int D_004B7558();
extern int D_004B75B8();
extern int D_004B7610();
extern int D_004B7668();

void func_004B6740(s32 arg0) {
    M2C_UNK var_16;

    var_16 = 0;
    func_004A01F0(arg0, D_003098F0[arg0].value);
    func_004B5DF8(arg0);
    func_004B5E18(arg0, func_0045E038(0x235F), (s32)&D_004B72E8, 1);
    func_004B5E18(arg0, func_0045E038(0x31D5), (s32)&D_004B7668, 1);
    func_004B5E18(arg0, func_0045E038(0x31D4), (s32)&D_004B75B8, 1);
    if ((D_00171B66[0] != 0) || (D_0021F7E9 != 0)) {
        var_16 = 1;
    }
    func_004B5E18(arg0, func_0045E038(0x3264), (s32)&D_004B7610, var_16);
    func_004B5E18(arg0, func_0045E038(0x31D3), (s32)&D_004B7558, var_16);
    func_004B5E18(arg0, func_0045E038(0x362D), (s32)&D_004B6C58, 1);
    func_004B5E70(arg0, &D_004B6C58, func_0045E038(0x31CF));
}
