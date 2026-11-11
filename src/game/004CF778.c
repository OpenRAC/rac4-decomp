#include "common.h"

extern s32 func_004A1730(void *);
extern void func_004CF910(void);
extern void func_004CF950(void);
extern void func_004CFA40(void);
extern void func_004CFCC0(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern u8 D_00316D00[];

void func_004CF778(s32 arg0) {
    u8 *entry = D_00316D00 + func_00505B20() * 0x9E0;
    switch (*(s32 *)entry) {
    case 1:
        *(s32 *)entry = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    case 0:
        func_004CFCC0();
        break;
    }
    if (*(s32 *)(entry + 8) & 1) {
        func_004CF910();
    }
    if (*(s32 *)(entry + 8) & 2) {
        func_004CF950();
    }
    func_004A1730(entry + 0x974);
    if (*(s32 *)(entry + 8) & 4) {
        func_004CFA40();
    }
}
