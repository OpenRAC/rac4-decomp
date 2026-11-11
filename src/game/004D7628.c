#include "common.h"

typedef void (*Fn_004D7628)(s32);

extern void func_0045DE88(void);
extern Fn_004D7628 *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_004A1730(void *);
extern void func_004D7738(void);
extern void func_004D78F0(void);
extern void func_004D7BC0(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern u8 D_0031E898[];
extern s32 D_0021FC14;

void func_004D7628(s32 arg0) {
    u8 *p;
    s32 state;
    Fn_004D7628 *fp;

    p = D_0031E898 + func_00505B20() * 0x528;
    state = *(s32 *)p;
    switch (state) {
    case 0:
        *(s32 *)p = 2;
        break;
    case 1:
        func_0045DE88();
        func_005014B0(arg0);
        break;
    case 2:
        func_004D7738();
        break;
    }
    if (*(s32 *)(p + 4) & 1) {
        func_004D7BC0();
    }
    func_004A1730(p + 0x4BC);
    if (*(s32 *)(p + 4) & 2) {
        func_004D78F0();
    }
    if (state == 0) {
        fp = func_0046D428(0x26CA, 0, 4);
        if (fp != 0) {
            if (*fp != 0) {
                (*fp)(D_0021FC14);
            }
        }
    }
}
