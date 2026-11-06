#include "common.h"
typedef struct {
    s32 mode;
    u8 pad[0x4B];
    u8 active;
} State;
extern State D_003D9C48;
extern s32 D_002215D0;
extern void *D_0021DE54;
u8 D_0021FBD4 = 0;
extern void func_0047F868(void), func_00489F10(s32), func_0048AB18(void *, s32), func_00502508(void *), func_004E3138(u32, s32, void *), func_00490538(void *);
extern s32 func_00158878(s32), func_0049BE58(s32), func_00157FA8(void), func_00506BB8(void), func_00506B70(s32), func_00506D28(void *);
extern void *func_004D45F0(void);
void func_004D3F70(s32 mode)
{
    s32 old;
    func_0047F868();
    func_00158878(0xCD);
    if (func_0049BE58(0) != 24)
        func_00489F10(0);
    func_0048AB18(&D_002215D0, 1);
    func_00157FA8();
    if (!D_003D9C48.active)
        D_003D9C48.mode = mode;
    old = func_00506BB8();
    func_00506B70(4);
    func_00502508(func_004D45F0());
    func_00506D28(func_004D45F0());
    func_00506B70(old);
    if (D_0021FBD4) {
        D_0021FBD4 = 0;
        func_004E3138(0xFFFFFFFFU, 0, 0);
    }
    if (D_0021DE54)
        func_00490538(D_0021DE54);
}
