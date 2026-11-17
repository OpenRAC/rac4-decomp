#include "common.h"

extern s32 func_L06_004C7518(void *a, s32 b);
extern void func_L06_004C7F78(void *a);
extern void func_L06_004C8068(int a1);

/* Pushes up to four string ids onto the object's list depending on the mode and count, then refreshes. */
void func_L06_004C73F0(void *arg0, s32 mode, s32 count) {
    u8 *b = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 *list;
    s32 v;

    *(s16 *)(b + 0xF8) = -1;
    if (mode == 1) {
        v = func_L06_004C7518(arg0, 0x2149);
        *(s16 *)(b + 0xF8) = *(s16 *)(b + 0xF8) + 1;
        *(s32 *)(b + (*(s16 *)(b + 0xF8) << 2) + 0xE0) = v;
    } else if (mode == 2) {
        v = func_L06_004C7518(arg0, 0x214A);
        *(s16 *)(b + 0xF8) = *(s16 *)(b + 0xF8) + 1;
        *(s32 *)(b + (*(s16 *)(b + 0xF8) << 2) + 0xE0) = v;
    } else {
        v = func_L06_004C7518(arg0, 0x214D);
        list = (s32 *)(b + 0xE0);
        *(s16 *)(b + 0xF8) = *(s16 *)(b + 0xF8) + 1;
        *(s32 *)((u8 *)list + (*(s16 *)(b + 0xF8) << 2)) = v;
        if (count > 0) {
            v = func_L06_004C7518(arg0, 0x214C);
            *(s16 *)(b + 0xF8) = *(s16 *)(b + 0xF8) + 1;
            *(s32 *)((u8 *)list + (*(s16 *)(b + 0xF8) << 2)) = v;
        }
        if (count >= 2) {
            v = func_L06_004C7518(arg0, 0x214B);
            *(s16 *)(b + 0xF8) = *(s16 *)(b + 0xF8) + 1;
            *(s32 *)((u8 *)list + (*(s16 *)(b + 0xF8) << 2)) = v;
        }
    }
    func_L06_004C7F78(arg0);
    func_L06_004C8068(arg0);
}
