#include "common.h"
extern char D_00220BB0[];
extern s32 func_0011AE00(const void *, const void *, u32);

u32 func_00503A40(const u8 *text)
{
    u32 result = 0;
    s32 shift = 5;
    s32 i;
    if (func_0011AE00(D_00220BB0, text, 7) == 0) {
        text += 7;
        for (i = 0; i < 9; i++) {
            u8 digit;
            if (shift < 0)
                break;
            if (text[i] == '.')
                continue;
            digit = text[i] - '0';
            if (digit < 10) {
                result |= (u32)digit << (shift * 4);
                shift--;
            } else {
                result = 0;
                break;
            }
        }
    }
    return result;
}
