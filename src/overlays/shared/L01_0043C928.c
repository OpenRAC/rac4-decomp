#include "common.h"

extern s32 func_L00_005E60A0(s32);
extern u8 *func_L01_0043C8C8(void *arg0, s32 arg1);

// Activate the object's first and/or second linked ids, randomly when both are flagged.
void func_L01_0043C928(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0xAC);
    if (s[0x1C0] != 0) {
        if (s[0x1C1] != 0) {
            switch (func_L00_005E60A0(3)) {
            case 0:
                func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1B8));
                break;
            case 1:
                func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1B8));
                func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1BC));
                break;
            case 2:
                func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1BC));
                break;
            }
        } else {
            func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1B8));
        }
    } else if (s[0x1C1] != 0) {
        func_L01_0043C8C8(arg0, *(s32 *)(s + 0x1BC));
    }
}
