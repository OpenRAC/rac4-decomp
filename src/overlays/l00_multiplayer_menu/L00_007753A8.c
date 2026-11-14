#include "common.h"

extern void func_007751B0(void *);
extern void func_L00_00775010(s32);

// Updates the object's state flags on completion and calls its callback.
void func_L00_007753A8(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    void (*callback)(s32, s32, s32);

    func_007751B0(arg3);
    if (arg2 == 0) {
        if (*(u32 *)arg3 & 1) {
            *(u32 *)arg3 = (*(u32 *)arg3 & ~1) | 2;
        }
        if ((*(u32 *)arg3 & 0x20) == 0) {
            *(u32 *)arg3 |= 0x22;
        }
    }
    func_L00_00775010(*(s32 *)(arg3 + 0x14));
    callback = *(void (**)(s32, s32, s32))(arg3 + 0x18);
    if (callback != 0) {
        callback(arg2, *(s32 *)(arg3 + 0xC), *(s32 *)(arg3 + 0x1C));
    }
}
