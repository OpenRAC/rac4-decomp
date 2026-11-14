#include "common.h"

extern s32 func_L00_005BC980(void *p);
extern void func_L00_006B8970(void *);
extern s32 func_L00_006ED020(void *);
extern s32 func_L00_006ED0E8(u8 *arg0);
s32 D_002206B4 = 0;

// Runs the three checks on the object, then either counts D_002206B4 down through func_L00_005BC980 and flags the object, or sets the counter to 0xF.
void func_L00_006ED170(u8 *arg0) {
    if (func_L00_006ED0E8(arg0) != 0 && func_L00_006ED020(arg0) != 0 && (*(s32 *)(*(u8 **)(arg0 + 0x2F00) + 0x1A0) & 0x10) != 0) {
        func_L00_005BC980(&D_002206B4);
        if (D_002206B4 <= 0) {
            *(s16 *)(arg0 + 0x3BA) = 3;
            func_L00_006B8970(arg0);
        }
    } else {
        D_002206B4 = 0xF;
    }
}
