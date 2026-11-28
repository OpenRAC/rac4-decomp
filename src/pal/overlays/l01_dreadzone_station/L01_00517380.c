#include "common.h"

extern u16 D_001F4570[];
extern u8 D_001F8878[];
extern s32 func_0054C100(s32 id, s32 *value);
extern s32 func_0045DFC8(s16 a, s16 b, s16 c, s32 d, f32 x, f32 y, f32 z, f32 w);

/* Register the station effects when their progress row is enabled. */
void func_L01_00517380(u8 *object) {
    s32 slot;
    s32 count;
    u32 off;
    u8 *row;

    if (D_001F4570[0] != 0) {
        return;
    }
    count = func_0054C100(0x72, &slot);
    off = count * 12 + ((slot - 1) % 20) * 0x304;
    row = D_001F8878 + off;
    if (row[9] == 0) {
        return;
    }
    func_0045DFC8(0x2AC0, 0x414, 3, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    func_0045DFC8(0x2AC1, 0x415, 3, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    func_0045DFC8(0x2AC2, 0x416, 3, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    func_0045DFC8(0x2AC3, 0x417, 3, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    func_0045DFC8(0x2AC4, 0x418, 3, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    (void)object;
}
