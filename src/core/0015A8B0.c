#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_00127A08(s32 microseconds);
extern void func_0015B498();
extern s32 func_0015DA28(void);
extern s32 func_01E9E0C0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_01E9E3E0(void *arg0);
extern s32 func_01E9E798(void);
extern s32 func_01E9E918(s32 arg0, s32 arg1);
extern s32 func_01E9EB08(s32 arg0, s32 arg1);
extern void func_0015B2C8(void);
extern void func_0015C2D8(void);
extern void func_0015C6B0(void);
extern u8 D_00172160[];
s8 D_0021DFA4 = 0;

// Clears the state block at D_00172160 and runs one step of its state machine; returns 1 when it stops early.
s32 func_0015A8B0(void) {
    s32 frame[24];
    s32 i;
    s32 v;
    s32 r;
    s32 a;
    s32 b;
    s32 *p;
    s32 *q;

    D_0021DFA4 = 0;
    D_00172160[0x7F8] = 0;
    D_00172160[0x6C8] = 0;
    *(s32 *)(D_00172160 + 0x7F4) = 0;
    for (i = 0; i < 10; i++) {
        p = (s32 *)(D_00172160 + 0x7CC) + i;
        q = (s32 *)(D_00172160 + 0x6A0) + i;
        *q = 0;
        *p = 0;
    }
    if (*(s32 *)D_00172160 >= 0xA) {
        return 0;
    }
    v = *(s32 *)(D_00172160 + 0x258);
    if (v == 1) {
        D_00172160[0x265] = v;
        *(s32 *)D_00172160 = 0xA;
        *(s32 *)(D_00172160 + 0x10) = 0;
        func_0015B498();
        return 0;
    }
    func_01E9E3E0(frame);
    frame[1] = *(s32 *)(D_00172160 + 8);
    frame[5] = 5;
    frame[7] = 2;
    frame[8] = (s32)func_0015B2C8;
    frame[10] = (s32)func_0015C2D8;
    frame[12] = (s32)func_0015C6B0;
    frame[6] = 0;
    func_0011AFC8((char *)(frame + 2), (char *)(D_00172160 + 0xFE), 0xC);
    if (func_01E9EB08((s32)frame, (s32)(frame + 0x14)) != 0) {
        return 1;
    }
    *(s32 *)D_00172160 = 9;
    do {
        func_00127A08(0x1F4);
        r = func_01E9E798();
        if (r != 0 && r != 0xC) {
            func_0015DA28();
            return 1;
        }
    } while (*(s32 *)D_00172160 == 9);
    if (*(s32 *)D_00172160 != 0xA) {
        return 1;
    }
    func_0015B498();
    a = 0x5A;
    if (D_00172160[0x262]) {
        a = 0;
    }
    b = 0x5A;
    if (D_00172160[0x262]) {
        b = 0;
    }
    if (func_01E9E0C0(*(s32 *)(D_00172160 + 8), a, b) != 0) {
        return 1;
    }
    func_01E9E918(*(s32 *)(D_00172160 + 8), 0);
    return 0;
}
