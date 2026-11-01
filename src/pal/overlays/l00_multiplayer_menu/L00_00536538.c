/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

s32 func_L00_005468B0(void *, s64);

s32 func_L00_00536538(void *object)
{
    s32 result;
    s32 state;

    if (*(s32 *)((u8 *)object + 0xC) == 0x21) {
        goto check_field;
    }
    goto check_value;
check_field:
    if (*(s32 *)((u8 *)object + 4) == 0) {
        goto check_callback;
    }
    goto check_value;
check_callback:
    if (func_L00_005468B0(object, *(s64 *)((u8 *)object + 0x18)) == 0) {
        goto select_nine;
    }
    goto check_value;
select_nine:
    state = 9;
    goto store_state;
check_value:
    result = 1;
    if (*(s64 *)((u8 *)object + 0x18) != 0) {
        if (!(*(s32 *)((u8 *)object + 0xC) & 1)) {
            state = 8;
            result = 0;
            *(s32 *)((u8 *)object + 8) = state;
            return result;
        } else {
            result = 1;
            if (*(s64 *)((u8 *)object + 0x18) >= 0) {
                return result;
            } else {
                state = 8;
                result = 0;
                *(s32 *)((u8 *)object + 8) = state;
                return result;
            }
        }
    }
    goto done;
store_state:
    result = 0;
    *(s32 *)((u8 *)object + 8) = state;
done:
    return result;
}
