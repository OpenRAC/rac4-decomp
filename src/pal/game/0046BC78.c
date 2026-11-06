#include "common.h"

typedef struct {
    u8 prefix[0x20];
    s32 value;
} Config;
extern s32 func_0054C070(s32, s32);
extern Config *func_0054BF00(s32);
extern s32 func_0045D348(void);
extern s32 D_0021DE98;
extern f32 D_003DB0A0[];
extern u8 D_001F8878[];
s32 func_0046BC78(s32 world, s32 slot)
{
    s32 value = func_0054BF00(func_0054C070(world, slot))->value;
    if (func_0045D348()) {
        value = (s32)((f32)value * D_003DB0A0[(D_0021DE98 - 1) % 20]);
        value /= 1000;
        value *= 1000;
    } else {
        s32 level = D_001F8878[slot * 12 + ((world - 1) % 20) * 0x304 + 9];
        if (level >= 3)
            value = 0;
        else if (level)
            value >>= level;
    }
    return value;
}
