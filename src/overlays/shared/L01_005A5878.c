/* cflags: -mno-split-addresses */
#include "common.h"
typedef int u128 __attribute__((mode(TI)));
extern u8 *func_005A5278(void);
extern s32 func_L01_005A5790(s32);
extern s32 func_L01_00550790(s32, s32, s32, s32, s32, s32, s32);
extern void *func_00595D00(void *);
extern u8 D_00222B20[];

s32 func_L01_005A5878(u8 *arg0) {
    u8 *base = func_005A5278();
    u8 *owner = *(u8 **)(arg0 + 0xAC);
    void *entry;
    if (func_L01_005A5790(*(u8 *)(owner + 0x672)) != 0) {
        *(u128 *)(arg0 + 0x10) = *(u128 *)(base + *(u8 *)(owner + 0x672) * 0x10 + 0xB0);
        func_L01_00550790((s32)D_00222B20, (s32)arg0, (s32)(arg0 + 0x10), (s32)(arg0 + 0xF0), (s32)(owner + 0x6C8), *(s32 *)(owner + 0x6C8) != 0, 0);
        entry = func_00595D00(arg0);
        if (entry != 0) *(s32 *)((u8 *)entry + 4) |= 0x800;
        return 1;
    }
    return 0;
}
