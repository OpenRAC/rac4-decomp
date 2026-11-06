#include "common.h"

extern void *func_0047D250(s32);
extern void func_00498C98(void *arg0);
extern s32 func_004CC978();
extern s32 func_004CCDC0(s32);
extern s32 func_004CCFD8(s32);
extern s32 func_00505B20(void);
extern void *func_00548D28(s32, s32);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_30EAA0[];

/* Looks up a per-slot value for kind arg0 from one of several tables. */
s32 func_004CC8A8(s32 arg0) {
    s32 buf[6];
    u8 *rec;

    rec = D_30EAA0 + func_00505B20() * 100;
    if (arg0 == 8) {
        buf[0] = 5;
        buf[1] = *(s32 *)(rec + 0x38);
        func_00498C98(buf);
        return buf[2];
    }
    if (arg0 == 9) {
        return func_004CC978();
    }
    if ((D_0021EDD4 != 0 || D_0021EDD8 != 1) && arg0 < 8) {
        return *(s16 *)((u8 *)func_0047D250(func_004CCDC0(arg0)) + 8);
    }
    return *(u16 *)((u8 *)func_00548D28(func_004CCFD8(arg0), 0) + 0x36);
}
