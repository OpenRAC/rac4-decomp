#include "common.h"

typedef void (*Cleanup)(s32);
typedef struct {
    u32 unknown0;
    Cleanup cleanup;
    u8 tail[8];
} Handler;
typedef struct {
    u8 unknown0[0xC];
    s32 count;
    u8 tail[0x2C];
} State;
extern State D_00306EC0[];
extern Handler D_003D8EC8[];
extern u16 D_001F36AC[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern u32 D_002216A4;
extern u32 D_0021EE4C;
extern s32 func_00506BB8(void);
extern void func_00498B48(s32);

void func_0049B9B0(void)
{
    s32 index = func_00506BB8();
    State *state = (State *)((u32)D_00306EC0 + (u32)index * 0x3C);

    D_001F36AC[0] = 0;
    if (!D_0021EE54 && D_0021EE58 == 1) {
        D_0021EE4C = D_002216A4;
    }
    while (state->count > 0) {
        state->count--;
        {
            Handler *handler = (Handler *)((u32)D_003D8EC8 + ((u32)state->count << 4));
            if (handler->cleanup) {
                handler->cleanup(index);
            }
        }
    }
    func_00498B48(index);
}
