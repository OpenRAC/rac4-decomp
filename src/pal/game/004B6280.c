#include "common.h"

typedef struct State {
    u8 prefix[0x1C];
    f32 offset;
    u8 middle[0x14];
    s32 mode;
} State;
extern State D_00309940;
extern s32 D_00221858;
extern s32 func_00498468(u32 index);
extern void func_005026A8(s32 *group, s32 type, s32 owner);
extern s32 func_00506C08(s32 index, s32 handle);

void func_004B6280(void)
{
    switch (func_00498468(0)) {
    case 0:
    case 2:
        func_005026A8(&D_00221858, 0x11, -1);
        D_00309940.mode = 2;
        D_00309940.offset = 0.1f;
        break;
    case 1:
    case 3:
    case 4:
        func_005026A8(&D_00221858, 0x12, -1);
        D_00309940.offset = -0.4f;
        D_00309940.mode = 0;
        break;
    }
    func_00506C08(10, D_00221858);
}
