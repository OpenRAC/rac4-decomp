#include "common.h"

extern s32 D_0021DE40;
extern void func_L01_0044BBA0(void *object, s32 value, f32 timer);

s32 func_L01_0044B088(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    s32 period = *(s16 *)(linked + 0x138);
    f32 period_f;
    s32 first;
    s32 second;

    if (period != -1) {
        period_f = (f32)period;
        period = D_0021DE40 % period;
        first = (s32)(period_f * *(f32 *)(linked + 0x130));
        second = (s32)(period_f * *(f32 *)(linked + 0x134));
        if (period >= first && period < second) {
            func_L01_0044BBA0(object, 4, 0.0f);
            return 1;
        }
        if ((period < first && (s32)((u32)first - 75u) < period)
            || (second < period
                && (s32)((u32)*(s16 *)(linked + 0x138)
                         + (u32)first - 75u) < period)) {
            if (D_0021DE40 % 24 < 12) {
                *(u32 *)((u8 *)object + 0x60) = 0xFF0000FF;
            }
        }
    }
    return 0;
}
