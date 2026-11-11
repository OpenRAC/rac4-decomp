#include "common.h"

extern s32 func_004A1730(void *);
extern void func_004CED70(void);
extern void func_004CEDB0(void);
extern void func_004CEE70(void);
extern void func_004CEFB0(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern u8 D_0030F820[];

void func_004CEB68(s32 arg0) {
    u8 *entry = D_0030F820 + func_00505B20() * 0x103C;
    switch (*(s32 *)entry) {
    case 1:
        *(s32 *)entry = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    case 0:
        func_004CEFB0();
        break;
    }
    if (*(s32 *)(entry + 8) & 1) {
        func_004CED70();
    }
    if (*(s32 *)(entry + 8) & 2) {
        func_004CEDB0();
    }
    func_004A1730(entry + 0xF90);
    if (*(s32 *)(entry + 8) & 4) {
        func_004CEE70();
    }
}
