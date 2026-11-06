#include "common.h"

extern s32 func_00505B20(void);
extern s32 func_00505AD8(s32);
extern void *func_004D7250(s32);
extern void func_00501498(void *);
extern s32 func_00505C90(void *);
extern void func_00497980(s32);
u8 D_0021FC11 = 0;

/* Reset the selected slot while preserving the active slot and notification flag. */
void func_004D73C8(s32 index)
{
    s32 saved = func_00505B20();
    func_00505AD8(index);
    func_00501498(func_004D7250(index));
    func_00505C90(func_004D7250(index));
    func_00505AD8(saved);
    if (!D_0021FC11)
        func_00497980(11);
    else
        D_0021FC11 = 0;
}
