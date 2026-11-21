#include "common.h"

extern s32 func_00472560(s32 a0);
extern void func_00522868(void *arg0, s32 arg1);
extern void func_00522AF8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00525E30();
extern s32 func_00546A20(u32 index);
extern void func_00547A40(s32 a0, s32 a1, s32 a2);
extern s32 D_003DD9F0[];

// Permutes the eight-entry table D_003DD9F0, then visits the entries that pass func_00546A20.
void func_00525EE0(void *arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 d;
    s32 count;
    s32 held;
    s32 idx;
    s32 r;
    s32 t;
    void *vt;

    i = 0;
    n = func_00472560(4) + 3;
    d = 8;
    for (; i < n && i < 8; i++) {
        held = D_003DD9F0[i];
        if (i < 3) {
            idx = func_00472560(5) + 3;
        } else {
            idx = func_00472560(8);
        }
        idx %= d;
        D_003DD9F0[i] = D_003DD9F0[idx];
        D_003DD9F0[idx] = held;
    }

    count = 0;
    i = 0;
    do {
        if (func_00546A20(D_003DD9F0[i]) != 0) {
            func_00522AF8(arg0, D_003DD9F0[i], 0, 1);
            if (*(u8 *)((u32)arg0 + 0x266D) != 0) {
                vt = *(void **)((u32)arg0 + 0x14);
                r = ((s32 (*)(void *))*(s32 *)((u32)vt + 0x4C))(arg0);
                func_00547A40(r, D_003DD9F0[i], -1);
            }
            if (count == 0 || D_003DD9F0[i] == 2) {
                func_00522868(arg0, D_003DD9F0[i]);
            }
            count += 1;
            if (count == arg1) {
                break;
            }
        }
        i++;
    } while (i < 8);

    if (count == 0) {
        t = func_00525E30(arg0);
        func_00522AF8(arg0, t, 0, 1);
        func_00522868(arg0, t);
    }
}
