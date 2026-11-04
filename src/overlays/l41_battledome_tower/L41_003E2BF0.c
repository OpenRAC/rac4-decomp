#include "common.h"
void *func_L41_003E2B38();                          /* extern */

void func_L41_003E2BF0(void) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    temp_v0 = func_L41_003E2B38();
    if (temp_v0 != NULL) {
        temp_v0_2 = (*(void **)((u8 *)(temp_v0) + 0xAC));
        if (temp_v0_2 != NULL) {
            temp_v0_3 = (*(void **)((u8 *)(temp_v0_2) + 0x10));
            if (temp_v0_3 != NULL) {
                temp_v0_4 = (*(void **)((u8 *)(temp_v0_3) + 0xAC));
                if (temp_v0_4 != NULL) {
                    (*(f32 *)((u8 *)(temp_v0_4) + 0x1C)) = -1.0f;
                }
            }
        }
    }
}
