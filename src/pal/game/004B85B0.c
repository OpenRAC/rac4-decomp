#include "common.h"

/* Cycles the selected slot setting and refreshes its dependent labels. */
typedef struct {
    char pad[0x2F10];
    s32 slot;
} Player;
extern s32 D_00171250[];
extern s32 func_00506BB8(void);
extern Player *func_00511CC0(s32);
extern void func_004985F0(s32);
extern void func_004B68A8(s32), func_004B6950(s32), func_004B6A10(s32), func_004B6AD0(s32), func_004B6B90(s32);
void func_004B85B0(void)
{
    s32 index = func_00506BB8();
    s32 *p = &D_00171250[func_00511CC0(index)->slot];
    *p = (*p + 1) % 3;
    func_004985F0(16);
    func_004B68A8(index);
    func_004B6950(index);
    func_004B6A10(index);
    func_004B6AD0(index);
    func_004B6B90(index);
}
