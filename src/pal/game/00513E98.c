#include "common.h"

extern s32 func_0051C2B0(const void *hero, f32 frame);
extern void func_00513E28(void *hero, s32 channel, s32 value, s32 enabled, s32 duration);

/* Sends pulses when the current animation crosses its frame thresholds. */
void func_00513E98(char *hero)
{
    s32 mode;
    s32 channel;
    if (*(s32 *)(hero + 0x25D4) != 1) {
        return;
    }
    mode = *(s32 *)(hero + 0x25CC);
    if (mode == 2 && *(s32 *)(hero + 0x370) < 12) {
        return;
    }
    channel = *(u8 *)(hero + 0x43B);
    if (mode == 2 && *(s32 *)(hero + 0x370) == 18) {
        func_00513E28(hero, channel, 0, 1, 30);
    }
    switch (*(u8 *)(*(char **)(hero + 0x2EF0) + 0x54)) {
    case 5:
    case 6:
        if (func_0051C2B0(hero, 38.5f)) {
            func_00513E28(hero, channel, 0, 1, 30);
        }
        if (func_0051C2B0(hero, 12.0f)) {
            func_00513E28(hero, channel, 1, 1, 30);
        }
        break;
    case 7:
    case 86:
    case 92:
    case 94:
    case 96:
        if (func_0051C2B0(hero, 12.0f)) {
            func_00513E28(hero, channel, 0, 1, 30);
        }
        if (func_0051C2B0(hero, 1.0f)) {
            func_00513E28(hero, channel, 1, 1, 30);
        }
        break;
    case 8:
    case 91:
    case 93:
    case 95:
    case 97:
        if (func_0051C2B0(hero, 8.0f)) {
            func_00513E28(hero, channel, 0, 1, 30);
        }
        if (func_0051C2B0(hero, 21.0f)) {
            func_00513E28(hero, channel, 1, 1, 30);
        }
        break;
    }
}
