#include "common.h"

extern u8 *func_L00_005DD000(s32, s32);
extern s32 func_L00_005E60A0(s32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

typedef int u128 __attribute__((mode(TI)));

// Spawn an object holding up to 15 randomly chosen entries from a list.
u8 *func_L01_0042E9D0(s32 n, s32 **list, s32 chance, s32 b, s32 c, f32 f0, f32 f1) {
    u8 *obj;
    u8 *st;
    s32 i;
    s32 ff;
    obj = func_L00_005DD000(0x1CD7, 0x50);
    if (obj == 0) return 0;
    if (n == 0 || list == 0 || *list == 0) return 0;
    st = *(u8 **)(obj + 0xAC);
    i = 0;
    *(u128 *)(obj + 0x10) = *(u128 *)((u8 *)*list + 0x10);
    ff = 0xFF;
    *(s16 *)(obj + 0x32) = ff;
    obj[0x30] = ff;
    *(f32 *)(st + 0x40) = f0;
    st[0x48] = b;
    st[0x49] = c;
    *(f32 *)(st + 0x44) = f1;
    st[0x4A] = 0;
    st[0x4B] = 0;
    if (n > 0) {
        do {
            if (*list != 0 && func_L00_005E60A0(0x64) < chance) {
                s32 cnt;
                *(s32 **)((u32)st + (*(s16 *)(st + 0x3C) << 2)) = *list;
                cnt = *(u16 *)(st + 0x3C) + 1;
                *(s16 *)(st + 0x3C) = cnt;
                if (!((s16)cnt < 0xF)) break;
            }
            i++;
            list++;
        } while (i < n);
    }
    func_L01_00591BD8(obj, 0, -1);
    return obj;
}
