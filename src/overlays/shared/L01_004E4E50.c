#include "common.h"

typedef struct {
    u8 pad[0x50];
    f32 value;
} LevelData;

typedef struct {
    u8 pad_00[0x20];
    u8 mode;
    u8 pad_21[0xAC - 0x21];
    LevelData *data;
} LevelObject;

s32 func_L01_004E4E50(LevelObject *object)
{
    u8 mode = object->mode;
    LevelData *data = object->data;
    s32 result = 0;

    if (mode == 3) {
        result = 1;
    } else if (data->value <= 0.0f) {
        result = 1;
    }

    return result;
}
