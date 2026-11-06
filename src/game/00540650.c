/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L39_0066C748.c func_L39_0066D888.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    u8 prefix[0x44];
    union {
        u8 byte;
        s32 word;
    } team;
    u8 gap[8];
    u8 sequence;
} Player;
extern s32 func_00511000(s32);
s32 func_00540650(Player *player, u8 sequence, u8 team)
{
    s32 changed = 0;
    s32 same = 1;
    if (team != player->team.byte) {
        same = 0;
        if (func_00511000(team) != 0) {
            player->team.word = team;
            changed = 1;
        }
    }
    if (same) {
        if (player->sequence < sequence)
            changed = 1;
        else if (player->sequence >= 193 && sequence <= 63)
            changed = 1;
    }
    return changed;
}
