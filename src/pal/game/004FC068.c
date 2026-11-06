#include "common.h"

typedef struct {
    char pad[0x18];
    s32 f18;
    s32 f1C;
    char pad20[0xC];
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
} Config;

typedef struct {
    char pad[0x10];
    s32 f10;
    s32 f14;
} Bounds;

extern s32 D_0021DFB8[1];
extern char *D_00221F20;
extern char D_0020F880[];
extern char D_00329300[];
extern s32 D_0021DFBC[1];
extern s32 D_0021DF6C[1];
extern s32 D_0021DF84[1];
extern Config D_00328A40;
extern Bounds D_001D3FC0;
extern void func_004FBCB8(void);
extern void func_004F9BE0(void);
extern void func_004F9E78(s32, s32);
extern void func_004FA700(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004F97F8(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004E88B8(s32, u64, s32);

s32 D_00220AB4 = 0;
u8 D_00220AB8 = 0;

void func_004FC068(void)
{
    s32 x;
    s32 y;
    u64 mask;
    u64 value;

    func_004FBCB8();
    *(s32 *)(D_00221F20 + 0) = (D_0021DFB8[0] >> 4) | 0x30000000;
    *(s32 *)(D_00221F20 + 4) = (s32)D_0020F880;
    *(s32 *)(D_00221F20 + 8) = 0;
    *(s32 *)(D_00221F20 + 12) = (D_0021DFB8[0] >> 4) | 0x50000000;
    D_00221F20 += 16;
    func_004F9BE0();
    func_004F9E78(D_0021DFBC[0], (s32)D_00329300 + (D_00220AB4 << 10));
    func_004FA700(D_0021DF6C[0], D_00328A40.f18, D_00328A40.f1C,
                  D_00328A40.f34 << 4, D_00328A40.f38 << 4,
                  D_00328A40.f3C << 4, D_00328A40.f40 << 4, 0xFFFF,
                  D_0021DFBC[0]);
    func_004F97F8(D_0021DF84[0], 0x100, 0x100, 0, 1, 0x80, 0x00808080, 0xFFFF);
    if (D_00220AB8) {
        mask = 0xFFFF00000000ULL;
        func_004E88B8(0x47, 0x70000, 0);
        func_004E88B8(1, 0x3F80000080808080ULL, 0);
        func_004E88B8(0x42, 0x8000000098ULL, 0);
        func_004E88B8(0x42, 0x8000000098ULL, 0);
        func_004E88B8(0, 0x146, 0);

        y = (D_00328A40.f2C << 4) + D_001D3FC0.f10 - 8;
        x = (D_00328A40.f30 << 4) + D_001D3FC0.f14 - 8;
        value = D_001D3FC0.f10 - 8;
        value |= (u64)(D_001D3FC0.f14 - 8) << 16;
        value |= mask;
        func_004E88B8(5, value, 0);
        value = ((u64)(s64)x << 16) | y | mask;
        func_004E88B8(5, value, 0);
    }
}
