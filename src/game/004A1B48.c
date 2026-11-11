#include "common.h"

extern void func_0049EF30(s32);
s32 D_0021F658 = 1;

extern void func_004A1D58(s32 active);

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
extern u8 D_00171948[];
extern const char *func_0045E080(s32 label);
extern void func_0049E790(s32 mode, const char *text, void (*callback)(s32),
                          s32 buttons, s32 f4, s32 f5, s32 f6, f32 timeout);
extern void func_0049B148(s32 context, s32 mask);
extern void func_005014B0(s32 *group);

void func_004A1B48(s32 *group)
{
    switch (D_0021F658) {
    case 1: {
        GameInfo *game = (GameInfo *)D_00171948;
        if (game->connection == 2 && game->error < 0) {
            if (game->mode != 2) {
                func_0049E790(0, func_0045E080(0x19B), func_004A1D58,
                              3, 0, 0, 0, -1.0f);
                D_0021F658 = 2;
            } else if (game->ready != 0 && game->code < -1 && game->value < 400) {
                func_0049E790(0, func_0045E080(0x198), func_004A1D58,
                              3, 0, 0, 0, -1.0f);
                D_0021F658 = 3;
            } else {
                D_0021F658 = 4;
            }
        }
        break;
    }
    case 2: {
        GameInfo *game = (GameInfo *)D_00171948;
        if (game->connection == 2 && game->error < 0 && game->mode == 2) {
            func_0049EF30(0);
            D_0021F658 = 1;
        }
        break;
    }
    case 3: {
        GameInfo *game = (GameInfo *)D_00171948;
        if (game->connection == 2 && game->error < 0 && game->mode != game->connection) {
            func_0049EF30(0);
            func_0049E790(0, func_0045E080(0x19B), func_004A1D58,
                          3, 0, 0, 0, -1.0f);
            D_0021F658 = 1;
        }
        break;
    }
    case 4:
        func_0049B148(0, 0x20);
        func_005014B0(group);
        break;
    }
}
