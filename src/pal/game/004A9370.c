#include "common.h"

typedef struct {
    u8 prefix[0x26E4];
    const void *config;
} Player;
typedef struct {
    u8 prefix[0x8C];
    s32 row;
    u8 tail[0x28];
} State;
extern State D_00308208[];
extern s32 D_003D17A8[];
extern u8 D_003D1810[];
extern s32 func_00506BB8(void);
extern Player *func_00511CC0(s32);
extern f32 func_004A91A0(const Player *);
extern s32 func_004A9340(f32);
extern u32 func_0054A308(const void *, s32);
s32 func_004A9370(void)
{
    s32 index = func_00506BB8();
    State *state = (State *)((u32)D_00308208 + (u32)index * 0xB8);
    Player *player = func_00511CC0(index);
    f32 angle = func_004A91A0(player);
    s32 direction;
    s32 test;
    if (angle != 360.0f) {
        direction = func_004A9340(angle);
        {
            s32 row = state->row;
            s32 column = *(s32 *)((u32)direction * 4 + (u32)D_003D17A8);
            s32 *values = (s32 *)((u32)D_003D1810 + (u32)row * 32);
            test = *(s32 *)((u32)values + (u32)column * 4);
        }
        if (!test || !(func_0054A308(player->config, test) & 255))
            goto fallback;
    } else {
    fallback:
        direction = 4;
    }
    return direction;
}
