/* cflags: -G0 -Wuninitialized -G8 */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

s32 func_0045E850(M2C_UNK);                         /* extern */
void func_004A0F28(s32, s32);                         /* extern */
void func_004B6CE8(s32);                         /* extern */
void func_004B6D08(s32, s32, s32, s32); /* extern */
typedef int (*Callback)();
M2C_UNK func_004B6D60(s32, Callback, s32);         /* extern */
extern u8 D_00171BE6[];
u8 D_0021F889 = 0;
typedef struct { u8 pad[12]; s32 value; u8 tail[488]; } Record;
extern Record D_003099F0[];
extern int func_004B7B48();
extern int func_004B81D8();
extern int func_004B8448();
extern int func_004B84A8();
extern int func_004B8500();
extern int func_004B8558();

void func_004B7630(s32 arg0) {
    M2C_UNK var_16;

    var_16 = 0;
    func_004A0F28(arg0, D_003099F0[arg0].value);
    func_004B6CE8(arg0);
    func_004B6D08(arg0, func_0045E850(0x235F), (s32)&func_004B81D8, 1);
    func_004B6D08(arg0, func_0045E850(0x31D5), (s32)&func_004B8558, 1);
    func_004B6D08(arg0, func_0045E850(0x31D4), (s32)&func_004B84A8, 1);
    if ((D_00171BE6[0] != 0) || (D_0021F889 != 0)) {
        var_16 = 1;
    }
    func_004B6D08(arg0, func_0045E850(0x3264), (s32)&func_004B8500, var_16);
    func_004B6D08(arg0, func_0045E850(0x31D3), (s32)&func_004B8448, var_16);
    func_004B6D08(arg0, func_0045E850(0x362D), (s32)&func_004B7B48, 1);
    func_004B6D60(arg0, &func_004B7B48, func_0045E850(0x31CF));
}
