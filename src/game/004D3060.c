#include "common.h"
typedef struct {
    s32 mode;
    u8 pad[0x4B];
    u8 active;
} State;
extern State D_003D9BE0;
extern s32 D_002214D0;
extern void *D_0021DDCC;
u8 D_0021FB2C = 0;
extern void func_0047EF38(void), func_00489458(s32), func_0048A060(void *, s32), func_00501498(void *), func_004E21D8(u32, s32, void *), func_0048FA80(void *);
extern s32 func_00158868(s32), func_0049B120(s32), func_00157F98(void), func_00505B20(void), func_00505AD8(s32), func_00505C90(void *);
extern void *func_004D36E0(void);
void func_004D3060(s32 mode)
{
    s32 old;
    func_0047EF38();
    func_00158868(0xCD);
    if (func_0049B120(0) != 24)
        func_00489458(0);
    func_0048A060(&D_002214D0, 1);
    func_00157F98();
    if (!D_003D9BE0.active)
        D_003D9BE0.mode = mode;
    old = func_00505B20();
    func_00505AD8(4);
    func_00501498(func_004D36E0());
    func_00505C90(func_004D36E0());
    func_00505AD8(old);
    if (D_0021FB2C) {
        D_0021FB2C = 0;
        func_004E21D8(0xFFFFFFFFU, 0, 0);
    }
    if (D_0021DDCC)
        func_0048FA80(D_0021DDCC);
}
