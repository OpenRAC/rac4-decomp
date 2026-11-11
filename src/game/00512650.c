#include "common.h"
typedef struct {
    u8 prefix[0x2314];
    s32 mode, item;
    u8 gap[0x33C];
    u8 enabled;
    u8 gap2[7];
    u8 blocked;
} Player;
typedef struct {
    u8 prefix[0x30];
    s16 value;
} Descriptor;
extern Descriptor *func_00548D28(s32, s32);
extern s32 func_00512610(Player *);
extern s32 D_0021EDD4;

s32 func_00512650(Player *player, s32 use_descriptor)
{
    s32 item;
    if (use_descriptor && player->enabled && !player->blocked) {
        item = player->mode == 2 ? player->item : -1;
        if (item == -1)
            return 0;
        return func_00548D28(item, 0)->value;
    }
    if (func_00512610(player) && D_0021EDD4 != 1)
        return 0x65;
    item = player->item;
    if (item == 5)
        return 0x42;
    if (item == 2)
        return 0x40;
    if (item == 4 || item == 10)
        return 0x44;
    if (item == 6 || item == 7 || item == 3 || item == 8 || item == 9 || item == 13)
        return 0x4E;
    return 0;
}
