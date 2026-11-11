#include "common.h"

#ifndef L01_00513F68_CALLBACKDATA_DEFINED
#define L01_00513F68_CALLBACKDATA_DEFINED
typedef struct {
    f32 value;
    u8 *entries;
    u32 unknown08;
    s32 count;
    f32 *values10;
    f32 *values14;
    s32 arg18;
    s32 arg1C;
} L01_00513F68_CallbackData;
#endif

void func_L01_0055C108(
    void *object,
    void *entry,
    s32 flag,
    s32 arg3,
    s32 arg4,
    s32 arg5,
    f32 value1,
    f32 value2,
    f32 value3
);

void func_L01_00513F68(void *object)
{
    L01_00513F68_CallbackData *data;
    f32 value;
    s32 i;

    data = *(L01_00513F68_CallbackData **)((u8 *)object + 0xAC);

    value = data->value - 0.1f;
    data->value = value;

    if (value <= -8.0f) {
        data->value = value + 8.0f;
    }

    for (i = 0; i < data->count; i++) {
        func_L01_0055C108(
            object,
            data->entries + (i * 16),
            1,
            data->arg18,
            data->arg1C,
            0x17,
            data->values14[i],
            data->values10[i],
            data->value
        );
    }
}
