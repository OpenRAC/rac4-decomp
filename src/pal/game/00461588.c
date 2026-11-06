#include "common.h"

extern u8 D_0021DDDA;
extern u8 D_0021DDDB;
extern u8 D_0021DDDC;
extern u8 D_002091C8[];
extern char D_0021EFF0[];
extern char D_003D07E8[];
extern u8 D_003D0800[];
extern char D_0021F000[];
extern u8 D_003D0840[];
extern char D_0021EFA0[];
extern char D_003D0858[];
extern char D_0021F010[];
extern char D_003D0870[];
extern char D_003D0888[];
extern char D_0021F020[];
extern u8 D_0021F028[];
extern char D_0021F038[];
extern u8 D_003D08A0[];
extern char D_0021F048[];
extern char D_0021F058[];
extern u8 D_003D08D0[];
extern char D_0021F060[];
extern u8 D_0021F068[];
extern char D_0021F078[];
extern char D_003D08F0[];

extern void func_00460D98(void *menu, s32 count);
extern void func_00460DE8(void *menu, const char *label, void *owner,
                          void *stats, s32 bytes, s32 dataSize,
                          const void *data, s32 kind);
extern void func_00461128(void *menu, s32 count, const char *title);
extern s32 func_00460900(u32 mask, s32 mode);

void func_00461588(u8 *stats)
{
    u8 *menu;

    if (D_0021DDDA || D_0021DDDC || D_0021DDDB) {
        return;
    }
    menu = D_002091C8;
    func_00460D98(menu, 1);
    func_00460DE8(menu, D_0021EFF0, stats, stats + 0x48,
                  0x40E00, 0, 0, 14);
    func_00460DE8(menu, D_003D07E8, stats, stats + 0x50,
                  0xCD00, 62, D_003D0800, 12);
    func_00460DE8(menu, D_0021F000, stats, stats + 0x58,
                  0x9100, 18, D_003D0840, 15);
    func_00460DE8(menu, D_0021EFA0, stats, stats + 0x68,
                  0x2900, 0, 0, 10);
    func_00460DE8(menu, D_003D0858, stats, stats + 0x70,
                  0x8600, 0, 0, 19);
    func_00460DE8(menu, D_0021F010, stats, stats + 0x80,
                  0x18B00, 0, 0, 16);
    func_00460DE8(menu, D_003D0870, stats, stats + 0x88,
                  0x7500, 0, 0, 17);
    func_00460DE8(menu, D_003D0888, stats, stats + 0x60,
                  0x2600, 0, 0, 11);
    func_00460DE8(menu, D_0021F020, stats, stats + 0x78,
                  0x6100, 14, D_0021F028, 18);
    func_00460DE8(menu, D_0021F038, stats, stats + 0x90,
                  0x15F00, 43, D_003D08A0, 20);
    func_00460DE8(menu, D_0021F048, stats, stats + 0xA0,
                  0x3000, 0, 0, 13);
    func_00460DE8(menu, D_0021F058, stats, stats + 0xB0,
                  0x2A00, 28, D_003D08D0, 21);
    func_00460DE8(menu, D_0021F060, stats, stats + 0x98,
                  0xCC00, 15, D_0021F068, 22);
    func_00460DE8(menu, D_0021F078, stats, stats + 0xA8,
                  0x3500, 0, 0, 23);
    func_00461128(menu, 1, D_003D08F0);
    func_00460900(0x8000, 3);
    D_0021DDDC = 1;
}
