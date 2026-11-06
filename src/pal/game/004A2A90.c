#include "common.h"

extern void func_0049FC68(s32);
s32 D_0021F6F8 = 1;

/* Select the active mode, resetting it when requested. */
void func_004A2A90(s32 active)
{
    if (active) {
        D_0021F6F8 = 4;
    } else {
        func_0049FC68(0);
        D_0021F6F8 = 1;
    }
}

typedef struct GameInfo {
    u8 pad00[8];
    s32 mode;
    s32 value;
    s32 unknown10;
    s32 ready;
    s16 code;
    u8 pad1A[0x1AA];
    s32 connection;
    s32 unknown1C8;
    s32 error;
} GameInfo;
extern u8 D_001719C8[];
extern const char *func_0045E898(s32 label);
extern void func_0049F4C8(s32 mode, const char *text, void (*callback)(s32),
                          s32 buttons, s32 f4, s32 f5, s32 f6, f32 timeout);
extern void func_0049BE80(s32 context, s32 mask);
extern void func_00502520(s32 *group);

void func_004A2880(s32 *group)
{
    switch (D_0021F6F8) {
    case 1: {
        GameInfo *game = (GameInfo *)D_001719C8;
        if (game->connection == 2 && game->error < 0) {
            if (game->mode != 2) {
                func_0049F4C8(0, func_0045E898(0x19C), func_004A2A90,
                              3, 0, 0, 0, -1.0f);
                D_0021F6F8 = 2;
            } else if (game->ready != 0 && game->code < -1 && game->value < 400) {
                func_0049F4C8(0, func_0045E898(0x199), func_004A2A90,
                              3, 0, 0, 0, -1.0f);
                D_0021F6F8 = 3;
            } else {
                D_0021F6F8 = 4;
            }
        }
        break;
    }
    case 2: {
        GameInfo *game = (GameInfo *)D_001719C8;
        if (game->connection == 2 && game->error < 0 && game->mode == 2) {
            func_0049FC68(0);
            D_0021F6F8 = 1;
        }
        break;
    }
    case 3: {
        GameInfo *game = (GameInfo *)D_001719C8;
        if (game->connection == 2 && game->error < 0 && game->mode != game->connection) {
            func_0049FC68(0);
            func_0049F4C8(0, func_0045E898(0x19C), func_004A2A90,
                          3, 0, 0, 0, -1.0f);
            D_0021F6F8 = 1;
        }
        break;
    }
    case 4:
        func_0049BE80(0, 0x20);
        func_00502520(group);
        break;
    }
}
