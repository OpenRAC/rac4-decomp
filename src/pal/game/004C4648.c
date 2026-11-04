#include "common.h"
typedef struct {
    s32 a, b, c, selection;
    char tail[0x64];
} State;
extern State D_0030B7F8[];
extern s32 func_00506BB8(void), func_00498518(s32);
extern char *func_00511CC0(s32);
extern s32 func_0054BD48(void *, s32), func_0054B0A0(void *, s32), func_0054B6F8(s32, s32);
extern u32 func_00499650(s32, s32);
u32 func_004C4648(s32 choice)
{
    s32 index = func_00506BB8();
    State *s = D_0030B7F8 + index;
    char *p = func_00511CC0(index);
    s32 item = func_00498518(s->selection);
    if (func_0054BD48(*(void **)(p + 0x26E4), item) == choice)
        return func_00499650(4, 3);
    if (!choice || (func_0054B0A0(*(void **)(p + 0x26E4), choice) && func_0054B6F8(item, choice)))
        return 0x80808080;
    return 0x80404040;
}
