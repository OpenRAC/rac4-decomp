#include "common.h"
s32 func_L00_006B6F88(const u8 *owner, s32 selector, f32 *output)
{
    *output = 0.0f;
    switch (selector) {
    case 11:
        return 1;
    case 16:
    case 17:
        if (25.0f < *(const f32 *)(owner + 0x658))
            *output = -1.48352981f;
        return 1;
    }
    return 0;
}
