#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern void func_0049CE90(s32, s32, s32, s32);
typedef struct Type1 {
    char pad[0x14];
    s32 f14;
    char pad18[8];
} Type1;
extern Type1 D_003D2688[];
extern s32 D_002219F8;

/* Apply the selected record's handle to the current slot. */
void func_004CBD68(s32 index)
{
    s32 slot = func_00506BB8();
    s32 handle = func_004A2798(&D_002219F8, D_003D2688[index].f14);
    func_0049CE90(slot, 0, handle, 0);
}
