#ifndef PAL_MENU_MESSAGE_PAIR_H
#define PAL_MENU_MESSAGE_PAIR_H

#include "common.h"
#include "pal/menu_labels.h"
#include "pal/multiplayer_menu.h"

/* Map a menu identifier to a pair of messages and submit both. */
static inline void submit_menu_message_pair(void *menu, s32 identifier) {
    s32 first;
    s32 second;

    switch (identifier) {
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
    func_L00_0071FD20(menu, first, 1, 0x2A, 0x28);
    func_L00_0071FD20(menu, second, 2, 3, 0xFFFFFFFF);
}

#endif
