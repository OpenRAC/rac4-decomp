/* cflags: -mno-split-addresses */
#include "common.h"

extern u32 D_0021EA84;
extern u8 *D_00222454;
extern void func_L00_005DB7C0(void);
extern void *func_L00_005DEBD0(s32, s32, s32);
s32 D_0021EA50 = 0;
s32 D_0021EA54 = 0;

/* Finds the first 0x100-byte record below D_0021EA84 whose id at 0xBC is 0x20A3, then calls its helper and runs the tail. */
void func_L00_005DB640(void) {
    u8 *rec;

    for (rec = D_00222454; (u32)rec < D_0021EA84; rec += 0x100) {
        if (*(s16 *)(rec + 0xBC) == 0x20A3) {
            D_0021EA50 = (s32)rec;
            break;
        }
    }
    if (D_0021EA50 != 0) {
        D_0021EA54 = (s32)func_L00_005DEBD0(*(s16 *)((u8 *)D_0021EA50 + 0xBC), 0x10, 0x1C);
    }
    func_L00_005DB7C0();
}
