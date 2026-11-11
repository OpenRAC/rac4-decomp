#include "common.h"

extern u8 D_0021DD52;
extern u8 D_0021DD53;
extern u8 D_0021DD54;
extern u8 D_00209148[];
extern char D_0021EF70[];
extern char D_003D0780[];
extern u8 D_003D0798[];
extern char D_0021EF80[];
extern u8 D_003D07D8[];
extern char D_0021EF20[];
extern char D_003D07F0[];
extern char D_0021EF90[];
extern char D_003D0808[];
extern char D_003D0820[];
extern char D_0021EFA0[];
extern u8 D_0021EFA8[];
extern char D_0021EFB8[];
extern u8 D_003D0838[];
extern char D_0021EFC8[];
extern char D_0021EFD8[];
extern u8 D_003D0868[];
extern char D_0021EFE0[];
extern u8 D_0021EFE8[];
extern char D_0021EFF8[];
extern char D_003D0888[];

extern void func_00460558(void *menu, s32 count);
extern void func_004605A8(void *menu, const char *label, void *owner,
                          void *stats, s32 bytes, s32 dataSize,
                          const void *data, s32 kind);
extern void func_004608E8(void *menu, s32 count, const char *title);
extern s32 func_004600C0(u32 mask, s32 mode);

void func_00460D48(u8 *stats)
{
    u8 *menu;

    if (D_0021DD52 || D_0021DD54 || D_0021DD53) {
        return;
    }
    menu = D_00209148;
    func_00460558(menu, 1);
    func_004605A8(menu, D_0021EF70, stats, stats + 0x48,
                  0x40E00, 0, 0, 14);
    func_004605A8(menu, D_003D0780, stats, stats + 0x50,
                  0xCD00, 62, D_003D0798, 12);
    func_004605A8(menu, D_0021EF80, stats, stats + 0x58,
                  0x9100, 18, D_003D07D8, 15);
    func_004605A8(menu, D_0021EF20, stats, stats + 0x68,
                  0x2900, 0, 0, 10);
    func_004605A8(menu, D_003D07F0, stats, stats + 0x70,
                  0x8600, 0, 0, 19);
    func_004605A8(menu, D_0021EF90, stats, stats + 0x80,
                  0x18B00, 0, 0, 16);
    func_004605A8(menu, D_003D0808, stats, stats + 0x88,
                  0x7500, 0, 0, 17);
    func_004605A8(menu, D_003D0820, stats, stats + 0x60,
                  0x2600, 0, 0, 11);
    func_004605A8(menu, D_0021EFA0, stats, stats + 0x78,
                  0x6100, 14, D_0021EFA8, 18);
    func_004605A8(menu, D_0021EFB8, stats, stats + 0x90,
                  0x15F00, 43, D_003D0838, 20);
    func_004605A8(menu, D_0021EFC8, stats, stats + 0xA0,
                  0x3000, 0, 0, 13);
    func_004605A8(menu, D_0021EFD8, stats, stats + 0xB0,
                  0x2A00, 28, D_003D0868, 21);
    func_004605A8(menu, D_0021EFE0, stats, stats + 0x98,
                  0xCC00, 15, D_0021EFE8, 22);
    func_004605A8(menu, D_0021EFF8, stats, stats + 0xA8,
                  0x3500, 0, 0, 23);
    func_004608E8(menu, 1, D_003D0888);
    func_004600C0(0x8000, 3);
    D_0021DD54 = 1;
}
