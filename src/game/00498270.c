#include "common.h"
typedef struct {
    u8 gap[6];
    s16 primary, secondary;
} Descriptor;
typedef struct {
    u8 gap[0x26E4];
    void *inventory;
} Hero;
typedef struct {
    char text[64];
} Buffer;
extern Buffer D_002F31B8[];
extern const char D_0021F590[];
extern Descriptor *func_00548D28(s32, s32);
extern const char *func_0045E038(s32);
extern Hero *func_00510BE8(s32);
extern s32 func_00547D58(void *, s32), func_0011D920(char *, const char *, ...);
const char *func_00498270(s32 index, s32 item, s32 numbered, s32 primary, s32 minimum)
{
    const char *result = (D_002F31B8 + index)->text;
    const char *text;
    Hero *hero;
    s32 level;
    if (primary)
        text = func_0045E038(func_00548D28(item, 0)->primary);
    else
        text = func_0045E038(func_00548D28(item, 0)->secondary);
    hero = func_00510BE8(index);
    level = 0;
    if (hero && hero->inventory)
        level = func_00547D58(hero->inventory, item);
    if (level >= minimum) {
        if (numbered)
            func_0011D920((char *)result, D_0021F590, text, level + 1);
        else
            result = text;
    } else
        result = text;
    return result;
}
