/* cflags:  -Wuninitialized -Wa,-G0 */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;

M2C_UNK func_00414628(void *, s32);                         /* extern */
s32 func_0043E758(void *);                          /* extern */
M2C_UNK func_0046C6B0(void *);                      /* extern */
s32 func_00472E40(M2C_UNK);                         /* extern */
void func_00474368(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 D_0021DE98;
extern s32 D_0022038C;

void func_L01_003D29E0(void *arg0) {
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_4;
    void *temp_3;

    if (D_0022038C != 0) {
        func_00414628(arg0, D_0022038C);
    }
    temp_3 = M2C_FIELD(arg0, void **, 0xB8);
    if ((temp_3 != NULL) && ((temp_4 = M2C_FIELD(temp_3, u8 *, 0x20), (temp_4 == 0xFE)) || (temp_4 == 0xFD) || ((u8) M2C_FIELD(temp_3, u8 *, 0x30) < (u8) M2C_FIELD(arg0, u8 *, 0x30)))) {
        M2C_FIELD(arg0, void **, 0xB8) = NULL;
    }
    temp_3_2 = M2C_FIELD(arg0, u8 *, 0x20);
    switch (temp_3_2) {                             /* irregular */
    case 0:
        func_0043E758(arg0);
        if ((((u32) D_0021DE98 - 0x256BU) >= 2U) && ((func_0043E758(arg0) != 0) || ((*(f32 *)0x222C8C > 0.95f) && (func_00472E40(0xA) == 0)))) {
            func_00474368(arg0, 1, -1);
            M2C_FIELD(arg0, u16 *, 0x34) = (u16) (M2C_FIELD(arg0, u16 *, 0x34) | 0x2800);
            return;
        }
        return;
    case 1:
        func_0043E758(arg0);
        temp_3_3 = M2C_FIELD(arg0, u8 *, 0x23);
        if (temp_3_3 < 2U) {
            func_0046C6B0(arg0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x23) = (u8) (temp_3_3 - 2);
        break;
    }
}
