/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

typedef struct {
    u8 unknown_00;
    u8 flag_01;
    u8 unknown_02[2];
    s32 state_04;
} CallbackContext;

s32 func_L00_0077B660(s32 unused0, void *result, s32 unused2, CallbackContext *context)
{
    s32 value;

    (void) unused0;
    (void) unused2;

    if (result) {
        value = 1;
        context->flag_01 = value;
    } else if (context->flag_01) {
        value = 3;
        context->state_04 = value;
    } else {
        value = 1;
        context->state_04 = value;
    }
    return value;
}
