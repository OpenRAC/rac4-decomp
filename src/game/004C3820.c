#include "common.h"
typedef struct {
    s32 a, b, c, selection;
    char tail[0x64];
} State;
extern State D_0030B7F8[];
extern s32 func_00505B20(void), func_004978C0(s32);
extern char *func_00510BE8(s32);
extern s32 func_0054A7E0(void *, s32), func_00549B38(void *, s32), func_0054A190(s32, s32);
extern u32 func_00498918(s32, s32);
u32 func_004C3820(s32 choice)
{
    s32 index = func_00505B20();
    State *s = D_0030B7F8 + index;
    char *p = func_00510BE8(index);
    s32 item = func_004978C0(s->selection);
    if (func_0054A7E0(*(void **)(p + 0x26E4), item) == choice)
        return func_00498918(4, 3);
    if (!choice || (func_00549B38(*(void **)(p + 0x26E4), choice) && func_0054A190(item, choice)))
        return 0x80808080;
    return 0x80404040;
}
