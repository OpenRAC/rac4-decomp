#include "common.h"

extern s32 func_00505B20(void);
extern s32 func_00505AD8(s32);
extern void *func_004C5670(s32);
extern void func_00501498(void *);
extern s32 func_00505C90(void *);
extern void func_00497980(s32);
extern u8 D_0021F8E8;
typedef struct Type1 {
    char pad[0x10];
    s32 f10;
    char pad14[0xB1C];
} Type1;
extern Type1 D_0030B9D8[];

/* Reset the selected descriptor, restore the slot and mark its state pending. */
void func_004C81B0(s32 index)
{
    s32 saved = func_00505B20();
    func_00505AD8(index);
    func_00501498(func_004C5670(index));
    func_00505C90(func_004C5670(index));
    func_00505AD8(saved);
    if (!D_0021F8E8)
        func_00497980(5);
    else
        D_0021F8E8 = 0;
    D_0030B9D8[index].f10 |= 4;
}
