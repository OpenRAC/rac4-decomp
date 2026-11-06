#include "common.h"
typedef struct {
    u8 enabled;
    u8 unknown1[3];
    s32 index;
    s32 selected;
    s32 selector;
    s32 texture;
    u8 unknown14[4];
    u64 primary_key;
    u64 current;
    u64 current_secondary;
    u64 key30;
    u64 key38;
    u64 texture_key;
    u64 key48;
} State;
extern State D_00239640;
extern u64 func_004495D8(s32 texture, s32 mode);
extern void func_004E88B8(s32 reg, u64 value, s32 retained_mode);
void func_0044DBE0(void *context, s32 texture)
{
    u64 key;
    if (D_00239640.enabled == 0) {
        func_004E88B8(6, func_004495D8(texture, 1), 0);
        return;
    }
    if (D_00239640.texture != texture) {
        key = func_004495D8(texture, 1);
        if (D_00239640.texture_key != key) {
            D_00239640.texture_key = key;
            func_004E88B8(6, key, 1);
        }
        D_00239640.texture = texture;
    }
}
