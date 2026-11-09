#include "common.h"

extern void func_004DBDB8();
extern void func_004DC200();
extern void func_004DC5F8();
extern void func_004DC8B0();
extern void func_004DCAE0();
extern void func_005014B0(s32 *a0);
extern s32 func_00505B20(void);
extern u8 D_00322FC8[];

/* Step the state of the current slot, then run its flag-selected updates. */
void func_004DBCE8(s32 *arg0) {
    u8 *p;
    s32 state;

    p = D_00322FC8 + func_00505B20() * 0x168;
    state = *(s32 *)p;
    switch (state) {
    case 0:
        *(s32 *)p = 2;
        break;
    case 2:
        func_004DBDB8();
        break;
    case 1:
        func_005014B0(arg0);
        break;
    }
    if (*(s32 *)(p + 4) & 1) {
        func_004DC200();
    }
    if (*(s32 *)(p + 4) & 2) {
        func_004DC5F8();
    }
    func_004DCAE0();
    func_004DC8B0();
}
