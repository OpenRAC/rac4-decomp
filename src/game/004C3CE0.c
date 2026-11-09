#include "common.h"

extern s32 func_004978C0(s32);
extern void func_00497980(s32);
extern void func_0049C328(s32, s32, s32);
extern void func_0049C390(s32, s32);
extern void func_004C34D8(void);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32);
extern s32 func_00549CA0(s32, s32);
extern s32 func_0054A0C0(s32, s32);
extern u8 D_0030B7F8[];

s32 func_004C3CE0(void) {
    s32 i = 0;
    s32 found = 0;
    s32 index = func_00505B20();
    u8 *entry = D_0030B7F8 + index * 0x74;
    void *player = func_00510BE8(index);
    s32 item = func_004978C0(*(s32 *)(entry + 0xC));
    *(s32 *)(entry + 0x18) = -1;
    *(u8 *)(entry + 0x62) = 1;
    for (; i < 8; i++) {
        if (func_00549CA0(*(s32 *)((u8 *)player + 0x26E4), i + 1) > 0 && func_0054A0C0(item, i + 1) != 0) {
            *(s32 *)(entry + 0x18) = i;
            break;
        }
    }
    if (*(s32 *)(entry + 0x18) >= 0) {
        found = 1;
        *(s32 *)entry = 2;
    }
    if (found) {
        func_00497980(0x13);
        if (*(u8 *)(entry + 0x62)) {
            func_0049C328(index, 3, 1);
            func_0049C390(index, 2);
        } else {
            func_0049C328(index, 2, 1);
            func_0049C390(index, 3);
        }
        func_004C34D8();
    } else {
        func_00497980(4);
    }
    return found;
}
