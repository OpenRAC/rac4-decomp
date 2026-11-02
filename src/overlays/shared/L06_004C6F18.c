/* cflags: -O2 -G8 */
#include "common.h"
typedef struct {
    s32 field_00;
    s32 field_04;
    f32 field_08;
    u8 unknown_0C[3];
    s8 field_0F;
    u8 unknown_10[4];
    f32 field_14;
    f32 field_18;
    f32 field_1C;
    u8 unknown_20[4];
    s32 field_24;
    u8 unknown_28[2];
    s16 field_2A;
} ConfigView;
extern u32 D_00222614;
s32 func_005315C0(void *);
s32 func_L06_004C70B8(void *, ConfigView *);
s32 func_0053C1C8(void *, s32, s32);

s32 func_L06_004C6F18(void * object, ConfigView *config)
{
    if (config->field_04 == -1) {
        func_005315C0(object);
        return 0;
    }
    if (config->field_00 == -1) {
        func_005315C0(object);
        return 0;
    }
    config->field_0F = 0;
    if (config->field_14 <= 0.0f) config->field_14 = 1.0f;
    if (config->field_18 <= 0.0f) config->field_18 = 1.0f;
    config->field_2A = 0;
    config->field_1C = config->field_18;
    config->field_24 = 0;
    if (config->field_08 > 0.0f) {
        *((s8 *)(*(u8 **)(D_00222614 + ((u32)config->field_04 << 8) + 0xAC) + 0x354)) = 1;
    }
    func_L06_004C70B8(object, config);
    func_0053C1C8(object, 1, -1);
    return 1;
}
