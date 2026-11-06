#include "common.h"
typedef struct State {
    u8 pad[16];
    s32 volume;
} State;
extern State D_00171DB8;
extern s32 D_002218E0;
extern void func_004985F0(s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_00498818(s32, s32, s32, f32, f32);
void func_004BB130(s32 delta)
{
    s32 a, b;
    if (delta) {
        D_00171DB8.volume = (s32)((u32)D_00171DB8.volume + (u32)(s32)((f32)delta * 102.4f));
        if ((u32)D_00171DB8.volume > 1024)
            func_004985F0(4);
        else
            func_004985F0(17);
        D_00171DB8.volume = D_00171DB8.volume > 1024 ? 1024 : D_00171DB8.volume;
        D_00171DB8.volume = D_00171DB8.volume < 0 ? 0 : D_00171DB8.volume;
    }
    a = func_004A2798(&D_002218E0, 28);
    b = func_004A2798(&D_002218E0, 29);
    func_00498818(a, b, 0, (f32)D_00171DB8.volume * (1.0f / 1024.0f), 0.0f);
}
