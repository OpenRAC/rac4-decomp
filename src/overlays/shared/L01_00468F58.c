#include "common.h"
void func_L01_00468FB0(void *, s16);             /* extern */
s16 func_L01_004690D8();                            /* extern */

void func_L01_00468F58(void *arg0) {
    void *temp_s0;

    temp_s0 = (*(void **)((u8 *)(arg0) + 0xAC));
    (*(s8 *)((u8 *)(temp_s0) + 0x504)) = 0;
    if ((*(s16 *)((u8 *)(temp_s0) + 0x4FE)) == -1) {
        (*(s16 *)((u8 *)(temp_s0) + 0x4FE)) = func_L01_004690D8();
    }
    func_L01_00468FB0(arg0, (*(s16 *)((u8 *)(temp_s0) + 0x4FE)));
}
