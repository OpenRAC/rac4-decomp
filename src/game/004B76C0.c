#include "common.h"

/* Cycles the selected slot setting and refreshes its dependent labels. */
typedef struct {
    char pad[0x2F10];
    s32 slot;
} Player;
extern s32 D_001711D0[];
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32);
extern void func_00497980(s32);
extern void func_004B59B8(s32), func_004B5A60(s32), func_004B5B20(s32), func_004B5BE0(s32), func_004B5CA0(s32);
void func_004B76C0(void)
{
    s32 index = func_00505B20();
    s32 *p = &D_001711D0[func_00510BE8(index)->slot];
    *p = (*p + 1) % 3;
    func_00497980(16);
    func_004B59B8(index);
    func_004B5A60(index);
    func_004B5B20(index);
    func_004B5BE0(index);
    func_004B5CA0(index);
}
