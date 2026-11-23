#include "common.h"

void func_L01_0044BBA0(void *object, s32 value, f32 timer);
extern s32 D_0021DE40;

s32 func_L01_0044B170(void *arg0) {
    f32 temp_f1;
    s16 temp_v1;
    s32 temp_hi;
    s32 first;
    s32 second;
    void *temp_a1;

    temp_a1 = *(void **)((s8 *)arg0 + 0xAC);
    if (*(s16 *)((s8 *)temp_a1 + 0xF0) == 4) {
        temp_v1 = *(s16 *)((s8 *)temp_a1 + 0x138);
        if (temp_v1 != -1) {
            temp_f1 = (f32)temp_v1;
            temp_hi = D_0021DE40 % temp_v1;
            first = (s32)(temp_f1 * *(f32 *)((s8 *)temp_a1 + 0x130));
            second = (s32)(temp_f1 * *(f32 *)((s8 *)temp_a1 + 0x134));
            if (temp_hi < first || temp_hi >= second) {
                func_L01_0044BBA0(arg0,
                    (~*(s16 *)((s8 *)temp_a1 + 0x13A) == 0) ? 0 : 5,
                    0.0f);
                return 1;
            }
        }
    }
    return 0;
}
