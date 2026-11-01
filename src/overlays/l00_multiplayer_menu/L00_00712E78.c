#include "common.h"
typedef struct { unsigned char pad0[0x5C]; s32 f5C; unsigned char pad60[0xC0]; s32 f120; unsigned char pad124[0x400]; s32 f524; s32 f528; s32 f52C; } TypeClamp;
// Constrain the selected item and the visible window to the available range.
void func_L00_00712E78(TypeClamp *obj) {
    s32 x;
    if (obj->f120 - 1 < obj->f524) obj->f524 = obj->f120 - 1;
    if (obj->f120 - obj->f5C < obj->f52C) obj->f52C = obj->f120 - obj->f5C;
    if (obj->f52C > obj->f524) obj->f52C = obj->f524;
    x = obj->f524 + 1;
    x -= obj->f5C;
    if (obj->f52C < x) obj->f52C = x;
    if (obj->f52C < 0) obj->f52C = 0;
}
