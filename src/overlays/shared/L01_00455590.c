#include "common.h"

extern void func_L00_005BCAE0(void *, s32, s32);
extern void func_L00_006068B0();
typedef struct {
    u8 pad0[0x18];
    s32 f18[3][4];
    s32 f48[3][4];
} Type1;
extern s32 D_1711D0[];
extern Type1 D_171D38[];
extern s32 D_171E00[][10];
extern s32 D_171E78[][10];
typedef int u128 __attribute__((mode(TI)));

/* Records the object's two flags in three tables by slot, calls two helpers, then clears the 128-bit field at +0x120 and the byte at +0x2ED3. */
void func_L01_00455590(u8 *arg0)
{
    u8 *s;
    Type1 *d38;

    s = *(u8 **)(arg0 + 0xAC);
    d38 = D_171D38;
    *(s32 *)(*(u8 **)(s + 0x48) + 0x2F00) = *(s32 *)(s + 0x4C);
    D_1711D0[*(s32 *)(*(u8 **)(s + 0x48) + 0x2F10)] = s[0x3E];
    D_171E78[D_1711D0[*(s32 *)(*(u8 **)(s + 0x48) + 0x2F10)]][s[0x3C]] =
        (u32)*(s32 *)(s + 0x68) >> 31;
    d38->f48[D_1711D0[*(s32 *)(*(u8 **)(s + 0x48) + 0x2F10)]][s[0x3C]] =
        (u32)*(s32 *)(s + 0x68) >> 31;
    D_171E00[D_1711D0[*(s32 *)(*(u8 **)(s + 0x48) + 0x2F10)]][s[0x3C]] =
        (u32)*(s32 *)(s + 0x6C) >> 31;
    d38->f18[D_1711D0[*(s32 *)(*(u8 **)(s + 0x48) + 0x2F10)]][s[0x3C]] =
        (u32)*(s32 *)(s + 0x6C) >> 31;
    func_L00_006068B0(*(s32 *)(*(u8 **)(s + 0x48) + 0x2F00));
    func_L00_005BCAE0((void *)(*(s32 *)(*(u8 **)(s + 0x48) + 0x2F00) + 0x354), 0, 0x1C);
    func_L00_005BCAE0((void *)(*(s32 *)(*(u8 **)(s + 0x48) + 0x2F00) + 0x1E0), 0, 0x78);
    *(u128 *)(*(u8 **)(s + 0x48) + 0x120) = 0;
    *(u8 *)(*(u8 **)(s + 0x48) + 0x2ED3) = 0;
}
