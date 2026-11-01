/* cflags: -O2 -G8 */
#include "common.h"
typedef struct { u8 unknown[0x9C]; s32 field_9C; } ChildView;
typedef struct { u8 unknown[0xAC]; ChildView *field_AC; } ObjectView;
void func_L01_005B0178(void *, f32, f32, f32);
void func_00474368(void *, u8, s32);

s32 func_L01_004B58F0(ObjectView *object, s32 mode)
{
    ChildView *child = object->field_AC;
    switch (mode) {
    case 1:
        func_L01_005B0178(object, 0.0f, 15.0f, 30.0f);
        break;
    case 4:
        child->field_9C = 0;
        func_00474368(object, 3, 3);
        break;
    }
    return 1;
}
