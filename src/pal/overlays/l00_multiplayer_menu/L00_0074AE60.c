#include "common.h"
#include "pal/multiplayer_menu.h"

// Maps a direction (-1, 0, 1) to a message id and submits it with a second fixed message.
void func_L00_0074AE60(void *arg0, s32 arg1) {
    s32 id;

    switch (arg1) {
    case -1:
        id = 0x23;
        break;
    case 0:
        id = 0x25;
        break;
    case 1:
        id = 0x24;
        break;
    default:
        return;
    }
    func_L00_0071FD20(arg0, id, 2, 0x18, 0x19);
    func_L00_0071FD20(arg0, 0x26, 1, 7, 6);
}
