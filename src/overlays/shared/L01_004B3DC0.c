/* cflags: -O2 -G8 */
#include "common.h"
typedef struct { u8 unknown[0x9C]; s32 field_9C; } ChildView;
typedef struct { u8 unknown[0xAC]; ChildView *field_AC; } ObjectView;
void func_L01_005ABDE8(void *, f32, f32, f32);
void func_00591BD8(void *, u8, s32);

s32 func_L01_004B3DC0(ObjectView *object, s32 mode)
{
    ChildView *child = object->field_AC;
    switch (mode) {
    case 1:
        func_L01_005ABDE8(object, 0.0f, 15.0f, 30.0f);
        break;
    case 4:
        child->field_9C = 0;
        func_00591BD8(object, 3, 3);
        break;
    }
    return 1;
}
