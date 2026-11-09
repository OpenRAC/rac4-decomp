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

extern s32 D_0021DF30[1];
extern char *D_00221E20;
extern char D_0020F800[];
extern char D_00329300[];
extern s32 D_0021DF34[1];
extern s32 D_0021DEE4[1];
extern s32 D_0021DEFC[1];
extern Config D_00328A40;
extern Bounds D_001D3F40;
extern void func_004FAC38(void);
extern void func_004F8B60(void);
extern void func_004F8DF8(s32, s32);
extern void func_004F9680(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004F8778(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_004E7990(s32, u64, s32);

s32 D_00220A1C = 0;
u8 D_00220A20 = 0;

void func_004FAFE8(void)
{
    s32 x;
    s32 y;
    u64 mask;
    u64 value;

    func_004FAC38();
    *(s32 *)(D_00221E20 + 0) = (D_0021DF30[0] >> 4) | 0x30000000;
    *(s32 *)(D_00221E20 + 4) = (s32)D_0020F800;
    *(s32 *)(D_00221E20 + 8) = 0;
    *(s32 *)(D_00221E20 + 12) = (D_0021DF30[0] >> 4) | 0x50000000;
    D_00221E20 += 16;
    func_004F8B60();
    func_004F8DF8(D_0021DF34[0], (s32)D_00329300 + (D_00220A1C << 10));
    func_004F9680(D_0021DEE4[0], D_00328A40.f18, D_00328A40.f1C,
                  D_00328A40.f34 << 4, D_00328A40.f38 << 4,
                  D_00328A40.f3C << 4, D_00328A40.f40 << 4, 0xFFFF,
                  D_0021DF34[0]);
    func_004F8778(D_0021DEFC[0], 0x100, 0x100, 0, 1, 0x80, 0x00808080, 0xFFFF);
    if (D_00220A20) {
        mask = 0xFFFF00000000ULL;
        func_004E7990(0x47, 0x70000, 0);
        func_004E7990(1, 0x3F80000080808080ULL, 0);
        func_004E7990(0x42, 0x8000000098ULL, 0);
        func_004E7990(0x42, 0x8000000098ULL, 0);
        func_004E7990(0, 0x146, 0);

        y = (D_00328A40.f2C << 4) + D_001D3F40.f10 - 8;
        x = (D_00328A40.f30 << 4) + D_001D3F40.f14 - 8;
        value = D_001D3F40.f10 - 8;
        value |= (u64)(D_001D3F40.f14 - 8) << 16;
        value |= mask;
        func_004E7990(5, value, 0);
        value = ((u64)(s64)x << 16) | y | mask;
        func_004E7990(5, value, 0);
    }
}
