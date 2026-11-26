/* Not matching yet: BYTES 4/216 (tools/try_func.py func_01EA2750 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x84]; s32 f84; } Iface;
extern Iface *D_00167F40;
extern void func_0011A518(void *a0, s32 a1, s32 a2);
extern s32 func_01E9E710(void *a0);
extern u32 func_01EA9BC8(void);

s32 func_01EA2750(u8 *a0) {
    if (a0 == 0) {
        return 0x17;
    }
    func_0011A518(a0, 0, 0x164);
    *(s32 *)(a0 + 0x4) = 0x100;
    *(s32 *)(a0 + 0x8) = 0;
    if (D_00167F40 != 0) {
        *(s32 *)(a0 + 0x148) = D_00167F40->f84 + 1;
    } else {
        *(s32 *)(a0 + 0x148) = func_01EA9BC8() % 1000 + 0x1770;
    }
    *(s32 *)(a0 + 0xA4) = 0;
    *(s32 *)(a0 + 0xAC) = 0;
    *(s32 *)(a0 + 0xB4) = 0;
    *(s32 *)(a0 + 0xBC) = 0;
    *(s32 *)(a0 + 0xC4) = 0;
    *(s32 *)(a0 + 0xC8) = 0;
    *(s32 *)(a0 + 0x14C) = 0;
    *(s32 *)(a0 + 0x150) = 0;
    *(s32 *)(a0 + 0x158) = 1;
    *(s32 *)(a0 + 0x154) = 0;
    *(s32 *)(a0 + 0x15C) = 0x2000;
    *(s32 *)(a0 + 0x160) = 0x2000;
    func_01E9E710(a0 + 0xD4);
    *(s32 *)a0 = 1;
    return 0;
}
