#include "common.h"

extern u8 *D_00222D14;

typedef struct {
    s32 id;
    s32 unused;
} LevelSlot;

typedef struct {
    void *unused;
    s32 (*callback)(u8 *);
} CallbackTable;

typedef struct {
    LevelSlot slots[16];
    CallbackTable *callbacks;
    s16 mode;
    s16 selected;
} LevelData;

typedef struct {
    u8 padding[0xAC];
    LevelData *data;
} LevelObject;

s32 func_L01_004E51F0(LevelObject *object)
{
    LevelData *data = object->data;
    CallbackTable *callbacks = data->callbacks;
    s16 selected;

    if (callbacks == 0) {
        return 0;
    }

    selected = data->selected;

    if (selected >= 0) {
        return callbacks->callback(
            D_00222D14 + (data->slots[selected].id << 8)
        );
    }

    return 0;
}
