#include "common.h"

extern s32 D_307254[];
extern s32 func_004983E8(s32);
extern void func_0049FB78(s32 arg0);

/* Dispatches on mode 6 to the callback of the 512-byte entry arg0. */
void func_0049F928(s32 arg0) {
    u8 *p = (u8 *)D_307254 + (arg0 << 9);
    s32 flag = 0;
    void (*cb)(s32);

    switch (func_004983E8(6)) {
    case 1:
        cb = *(void (**)(s32))(*(s32 *)(p + 0x2C) * 0xC + *(s32 *)(p + 0x3C) + 8);
        if (cb) cb(0);
        break;
    case 13:
        cb = *(void (**)(s32))(p + 0x40);
        if (cb) cb(1);
        break;
    case 2:
        cb = *(void (**)(s32))(p + 0x40);
        if (cb) cb(0);
        break;
    case 5:
        flag = 1;
    case 6:
        func_0049FB78(flag);
        break;
    }
}
