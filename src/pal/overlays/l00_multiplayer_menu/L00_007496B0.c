#include "common.h"
#include "pal/menu_labels.h"
#include "pal/multiplayer_menu.h"

// Map a weapon-style id onto a message pair and submit both.
void func_L00_007496B0(void *arg0, s32 arg1) {
    s32 first;
    s32 second;

    switch (arg1) {
    case -1:
        first = 8;
        second = 9;
        break;
#define SET_MESSAGES(id, index) \
    case id:                    \
        first = 0xA + 2 * (index); \
        second = 0xB + 2 * (index); \
        break;
        PAL_MENU_LABELS(SET_MESSAGES)
#undef SET_MESSAGES
    default:
        return;
    }
    func_L00_0071FD20(arg0, first, 1, 0x2A, 0x28);
    func_L00_0071FD20(arg0, second, 2, 3, 0xFFFFFFFF);
}
