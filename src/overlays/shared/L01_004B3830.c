#include "common.h"

extern void func_L00_005F1520(s32);
void func_L01_004B35E8(void *);

// Set the linked object's timers and flag, bump its counter, then notify.
void func_L01_004B3830(void *arg0) {
    u8 *linked = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 count = linked[0x687];

    *(s16 *)(linked + 0x67C) = 0x14;
    *(s16 *)(linked + 0x67E) = -1;
    *(s32 *)(linked + 0x50) |= 0x40;
    if (count < 0xFF) {
        linked[0x687] = count + 1;
    }
    func_L00_005F1520((s32)arg0);
    func_L01_004B35E8(arg0);
}
