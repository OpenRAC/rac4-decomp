#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_00506B70(s32);
extern void *func_004C6498(s32);
extern void func_00502508(void *);
extern s32 func_00506D28(void *);
extern void func_004985F0(s32);
extern u8 D_0021F988;
typedef struct Type1 {
    char pad[0x10];
    s32 f10;
    char pad14[0xB1C];
} Type1;
extern Type1 D_0030B9D8[];

/* Reset the selected descriptor, restore the slot and mark its state pending. */
void func_004C8FD8(s32 index)
{
    s32 saved = func_00506BB8();
    func_00506B70(index);
    func_00502508(func_004C6498(index));
    func_00506D28(func_004C6498(index));
    func_00506B70(saved);
    if (!D_0021F988)
        func_004985F0(5);
    else
        D_0021F988 = 0;
    D_0030B9D8[index].f10 |= 4;
}
