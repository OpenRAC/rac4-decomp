#include "common.h"

extern u8 D_00243850[];
extern s32 D_00242D00[];
extern u8 D_001D2280[];
extern s32 func_004E2B60(s32, s32, s32, s32, s32);
extern s32 func_004E0E28(s32);

/* Register an indexed entry when its capacity permits it. */
s32 func_004E3078(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 entry = D_00242D00[D_00243850[arg4]];
    s32 base;
    s32 result;
    s32 record;
    if (entry == 0) {
        return -1;
    }
    base = *(s32 *)(entry + 0x28);
    if (base == 0 || arg0 >= *(u8 *)(entry + 0xD)) {
        return -1;
    }
    result = func_004E2B60(base + (arg0 << 5), arg1, 0, arg3, 0x400);
    if (result >= 0) {
        record = (s32)D_001D2280 + (result << 7);
        *(s32 *)(record + 0x2DC) = arg2;
        *(s16 *)(record + 0x2CA) = arg0;
        *(s32 *)(record + 0x308) = arg4;
    }
    return func_004E0E28(result);
}
