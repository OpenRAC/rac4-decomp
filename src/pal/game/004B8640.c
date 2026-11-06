#include "common.h"
typedef struct {
    u8 prefix[0x2F10];
    s32 category;
} Player;
extern s32 func_00506BB8(void);
extern Player *func_00511CC0(s32);
extern void func_004985F0(s32);
extern s32 func_004B6950(s32);
extern s32 D_00171250[];
extern s32 D_00171E00[][4], D_00171EF8[][10];
s32 func_004B8640(void)
{
    s32 context = func_00506BB8();
    s32 category = func_00511CC0(context)->category;
    s32 option = D_00171250[category];
    s32 *source = &D_00171EF8[option][category];
    s32 *dest = &D_00171E00[option][context];
    s32 value = (*source & 1) ^ 1;
    *source = value;
    *dest = value;
    func_004985F0(16);
    return func_004B6950(context);
}
