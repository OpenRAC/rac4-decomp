#include "common.h"

extern s32 func_L00_005C9F50(s32);
void func_L00_0071B8E8(void *, s32, s32);

/* Calls method +0x20 of the vtable of the object at +0x128 with (4, 0), then method +0x28 with func_L00_005C9F50(0xF8C), then func_L00_0071B8E8(arg0, 0x1E, 0). */
void func_L00_007391D8(void *arg0)
{
    u8 *vt;

    ((void (**)(void *, s32, s32))(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x128) + 0x58) + 0x20))[0](*(u8 **)((u8 *)arg0 + 0x128), 4, 0);
    vt = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x128) + 0x58);
    ((void (**)(void *, s32))(vt + 0x28))[0](*(u8 **)((u8 *)arg0 + 0x128), func_L00_005C9F50(0xF8C));
    func_L00_0071B8E8(arg0, 0x1E, 0);
}
