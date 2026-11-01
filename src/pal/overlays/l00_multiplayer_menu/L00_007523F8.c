/* cflags: -O2 -G8 */
#include "common.h"

void *func_L00_0070DEB0(void *value);
void *func_L00_0070DF20(void *value);
void func_L00_0071F2E0(void *object);
void func_L00_0071FCE8(s32 object);
extern s8 D_00220AD0;
extern s8 D_00220AD1;

void func_L00_007523F8(void *object)
{
    u8 *self = (u8 *)object;
    void *child;

    func_L00_0070DEB0(0);
    func_L00_0070DF20(0);
    D_00220AD1 = 0;
    D_00220AD0 = 0;
    child = *(void **)(self + 0x740);
    (*(s32 (**)(void *))(*(u8 **)((u8 *)child + 0x58) + 0x140))(child);
    {
        u8 value = self[0x744];
        (*(u8 **)(self + 0x740))[0xA8] = value;
    }
    {
        u8 value = self[0x745];
        (*(u8 **)(self + 0x740))[0xA9] = value;
    }
    *(s32 *)(*(u8 **)(self + 0x740) + 0x250) = *(s32 *)(self + 0x748);
    *(s32 *)(*(u8 **)(self + 0x740) + 0x254) = *(s32 *)(self + 0x74C);
    func_L00_0071F2E0(object);
    func_L00_0071FCE8((s32)object);
}
