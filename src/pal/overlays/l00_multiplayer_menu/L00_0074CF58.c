#include "common.h"
#include "pal/menu_labels.h"
#include "pal/multiplayer_menu.h"

// Map a weapon-style id onto one message, then submit four fixed follow-ups.
void func_L00_0074CF58(void *arg0, s32 arg1) {
    s32 message;

    switch (arg1) {
    case -1:
        message = 0x27;
        break;
#define SET_MESSAGES(id, index) case id: message = 0x2C + (index); break;
        PAL_MENU_LABELS(SET_MESSAGES)
#undef SET_MESSAGES
    default:
        return;
    }
    func_L00_0071FD20(arg0, message, 1, 0x10, 0xF);
    func_L00_0071FD20(arg0, 0x28, 2, 0xA, 0xFFFFFFFF);
    func_L00_0071FD20(arg0, 0x28, 2, 7, 0xFFFFFFFF);
    func_L00_0071FD20(arg0, 0x28, 2, 5, 0xFFFFFFFF);
    func_L00_0071FD20(arg0, 0x28, 2, 3, 0xFFFFFFFF);
}
