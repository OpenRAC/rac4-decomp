#include "common.h"

extern s32 func_00505B20(void);
extern s32 func_004A1A60(s32 *, s32);
extern void func_0049C158(s32, s32, s32, s32);
typedef struct Type1 {
    char pad[0x14];
    s32 f14;
    char pad18[8];
} Type1;
extern Type1 D_003D2618[];
extern s32 D_002218F8;

/* Apply the selected record's handle to the current slot. */
void func_004CAEC8(s32 index)
{
    s32 slot = func_00505B20();
    s32 handle = func_004A1A60(&D_002218F8, D_003D2618[index].f14);
    func_0049C158(slot, 0, handle, 0);
}
