#include "common.h"

extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505238();
extern s32 func_00505328(s32 handle, u32 value);
extern u8 D_307074[];
extern u8 D_307220[];

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

/* Arms one of the per-context entries (or the fixed one for context 4): sets up two flags and a value, then bumps the entry's counter at +0x10. */
void func_0049E6B8(s32 arg0, s32 arg1) {
    u8 *target;

    if (arg0 == 4) {
        target = D_307074;
    } else {
        target = D_307220 + (arg0 << 9);
    }
    if (arg1 != 0) {
        func_00505238(((u32)arg0 << 6) + address(*(u32 *)(target + 0x10) << 1, 0x130006));
        func_00504F68(((u32)arg0 << 6) + address(*(u32 *)(target + 0x10) << 1, 0x130006), 1);
        func_00504F68(((u32)arg0 << 6) + address(*(u32 *)(target + 0x10) << 1, 0x130005), 1);
        func_00505328(((u32)arg0 << 6) + address(*(u32 *)(target + 0x10) << 1, 0x130006), 0x80808080);
        *(s32 *)(target + 0x10) = *(s32 *)(target + 0x10) + 1;
    }
}
