#include "common.h"
typedef struct {
    u8 prefix[0x2F10];
    s32 category;
} Player;
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32);
extern void func_00497980(s32);
extern s32 func_004B5B20(s32);
extern s32 D_001711D0[];
extern s32 D_00171D50[][4], D_00171E00[][10];
s32 func_004B77F0(void)
{
    s32 context = func_00505B20();
    s32 category = func_00510BE8(context)->category;
    s32 option = D_001711D0[category];
    s32 *source = &D_00171E00[option][category];
    s32 *dest = &D_00171D50[option][context];
    s32 value = (*source & 1) ^ 1;
    *source = value;
    *dest = value;
    func_00497980(16);
    return func_004B5B20(context);
}
