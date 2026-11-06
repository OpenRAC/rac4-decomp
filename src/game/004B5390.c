#include "common.h"

typedef struct State {
    u8 prefix[0x1C];
    f32 offset;
    u8 middle[0x14];
    s32 mode;
} State;
extern State D_00309840;
extern s32 D_00221758;
extern s32 func_00497810(u32 index);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505B70(s32 index, s32 handle);

void func_004B5390(void)
{
    switch (func_00497810(0)) {
    case 0:
    case 2:
        func_00501638(&D_00221758, 0x11, -1);
        D_00309840.mode = 2;
        D_00309840.offset = 0.1f;
        break;
    case 1:
    case 3:
    case 4:
        func_00501638(&D_00221758, 0x12, -1);
        D_00309840.offset = -0.4f;
        D_00309840.mode = 0;
        break;
    }
    func_00505B70(10, D_00221758);
}
