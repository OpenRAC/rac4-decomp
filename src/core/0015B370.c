#include "common.h"

extern u8 D_00172160[];
extern s32 func_0015A750(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_0015B808(void);
extern void func_0015C730(void);
extern u8 func_0015C770(void);
extern void func_0015E7A8(void);
extern s32 func_00161128(void);
extern u8 func_00161320(void);
extern void func_00161AE8(void);
extern s32 func_01E9E838(s32 arg0);
extern s32 func_01ED5D30(s8 *arg0);
extern s32 func_01ED7590(void *);
extern s32 func_01ED75F0(void *);

/* Reset-step of the D_00172160 state machine: runs the setup calls, then moves state 0xA to 5. */
void func_0015B370(void) {
    s8 buf[0x80];

    if (func_00161320() != 0) {
        if (D_00172160[0x2D5] != 0) {
            func_0015B808();
            *(s32 *)(D_00172160 + 0x60C) = 3;
            func_0015B548(func_01ED7590(D_00172160 + 0x490));
            func_0015B558();
            *(s32 *)(buf + 0x78) = 0;
            buf[0x58] = 0;
            buf[0x18] = 0;
            func_01ED5D30(buf);
            *(s32 *)(buf + 0x14) = func_00161128();
            func_0015B548(func_01ED75F0(buf));
            func_0015B558();
        }
    }
    D_00172160[0x265] = 0;
    func_00161AE8();
    if (*(s32 *)D_00172160 == 0xA) {
        func_01E9E838(*(s32 *)(D_00172160 + 8));
        *(s32 *)D_00172160 = 7;
        func_0015A750();
        D_00172160[0x250] = 0;
        *(s32 *)D_00172160 = 5;
        D_00172160[0x251] = 0;
        if (func_0015C770() == 0) {
            *(s32 *)(D_00172160 + 0x10) = -1;
        }
        *(s32 *)(D_00172160 + 4) = 1;
        *(s32 *)(D_00172160 + 8) = 0;
        *(s32 *)(D_00172160 + 0x1C) = 0;
        *(s32 *)(D_00172160 + 0x20) = 0;
        *(s32 *)(D_00172160 + 0x3C) = 0;
        if (func_0015C770() == 0) {
            func_0015E7A8();
        }
        func_0015C730();
    }
}
