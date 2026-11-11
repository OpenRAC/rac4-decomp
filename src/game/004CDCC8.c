#include "common.h"

extern s32 func_004A1730(void *);
extern void func_004CDEC8(void);
extern void func_004CDF08(void);
extern void func_004CDFE0(void);
extern void func_004CE130(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern unsigned int D_00171C08[];
extern u8 D_0030ECC0[];

void func_004CDCC8(s32 arg0) {
    s32 index = func_00505B20();
    s32 off = index * 0x280;
    s32 *state = (s32 *)(D_0030ECC0 + off);
    s32 *slot = (s32 *)(off + (D_0030ECC0 + 0x27C));
    s32 id = *slot;

    if (id != -1) {
        if (id >= 0)
            D_00171C08[(unsigned int)id >> 5] &= ~(1u << (id & 31));
        *slot = -1;
    }
    switch (state[0]) {
    case 1:
        state[0] = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    case 0:
        func_004CE130();
        break;
    }
    if (state[2] & 1)
        func_004CDEC8();
    if (state[2] & 2)
        func_004CDF08();
    func_004A1730(state + 0x210 / 4);
    if (state[2] & 4)
        func_004CDFE0();
}
