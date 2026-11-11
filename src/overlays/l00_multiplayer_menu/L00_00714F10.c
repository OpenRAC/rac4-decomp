#include "common.h"

extern s32 func_0069CC48(s32, s32, s32);
extern u32 func_005E6358(u32, u32, s32, s32, s32, s32);
extern s32 func_0069D318(s32, u8 *);
extern s32 func_0069D408(s32, u32);
extern void func_0069E7A8(s32, s32);

void func_L00_00714F10(u8 *item) {
    u32 col;
    s32 mode;

    if (*(s32 *)(item + 4) == 0) {
        return;
    }
    if (*(s32 *)(item + 0x14) == 0 && *(s32 *)(item + 0x5C) == 0) {
        return;
    }
    func_0069CC48(*(s32 *)(item + 0x14), 1, 0);
    if (*(s32 *)(item + 4) == 1) {
        func_0069CC48(*(s32 *)(item + 0x5C), 1, 0);
        return;
    }
    func_0069CC48(*(s32 *)(item + 0x5C), 1, 1);
    mode = *(s32 *)(item + 4);
    if (mode == 3) {
        col = 0x80808080;
    } else if (mode == 4) {
        col = *(u32 *)(item + 0x130);
    } else if (mode == 5) {
        col = func_005E6358(0x80D6CBBE, 0x66A6BEFA, 0x2D, 1, 0, 1);
    } else if (mode == 6) {
        col = 0x66A6BEFA;
    } else {
        col = *(u32 *)(item + 0x130);
    }
    if (*(s32 *)(item + 0x14) != 0 && item[0x18] != 0) {
        func_0069D318(*(s32 *)(item + 0x14), item + 0x18);
        func_0069D408(*(s32 *)(item + 0x14), col);
        func_0069CC48(*(s32 *)(item + 0x14), 1, 1);
    }
    if (*(s32 *)(item + 0x5C) != 0) {
        if (*(s32 *)(item + 0x128) != 0) {
            if (item[0x134] != 0) {
                func_0069E7A8(*(s32 *)(item + 0x5C), 1);
            } else {
                func_0069E7A8(*(s32 *)(item + 0x5C), 0);
            }
        }
        func_0069D318(*(s32 *)(item + 0x5C), item + 0x60);
        func_0069D408(*(s32 *)(item + 0x5C), col);
    }
}
