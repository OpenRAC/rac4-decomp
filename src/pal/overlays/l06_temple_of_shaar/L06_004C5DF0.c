/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_0045E1E0(s32, s32, s32);               /* extern */
void *func_0046DD08(s32, s32, s32);                 /* extern */
extern s32 D_00222694;

void func_L06_004C5DF0(void *arg0) {
    s32 (*temp_2)(void *);
    s32 (*temp_2_2)(void *);
    s32 temp_3;
    s32 temp_4_2;
    void *temp_16;
    void *temp_17;
    void *temp_18;
    void *temp_19;
    void *temp_4;

    temp_4 = (*(void **)((u8 *)(arg0) + (0xAC)));
    temp_3 = (*(s32 *)((u8 *)(temp_4) + (0)));
    if ((temp_3 != -1) && (temp_4_2 = (*(s32 *)((u8 *)(temp_4) + (4))), (temp_4_2 != -1))) {
        temp_18 = D_00222694 + (temp_3 << 8);
        temp_19 = D_00222694 + (temp_4_2 << 8);
        temp_16 = func_0046DD08((*(s16 *)((u8 *)(temp_18) + (0xBC))), 20, 8);
        temp_17 = func_0046DD08((*(s16 *)((u8 *)(temp_19) + (0xBC))), 20, 8);
        if ((temp_16 == NULL) || (temp_2 = (*(s32 (**)(void *))((u8 *)(temp_16) + (4))), (temp_2 == NULL)) || (temp_2(temp_18) == 0)) {
            if (temp_17 != NULL) {
                temp_2_2 = (*(s32 (**)(void *))((u8 *)(temp_17) + (4)));
                if (temp_2_2 != NULL) {
                    if (temp_2_2(temp_19) != 0) {
                        goto block_8;
                    }
                }
            }
        } else {
block_8:
            func_0045E1E0(13087, 1898, 2);
        }
    }
}
