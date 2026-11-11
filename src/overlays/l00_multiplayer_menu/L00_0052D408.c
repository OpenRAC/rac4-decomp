/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s64 func_L00_00528810(void);

s32 func_L00_0052D408(u8 *object) {
    s32 result = 0;
    if (object == 0) {
        result = 0x2721;
    } else {
        s64 value = func_L00_00528810();
        if (value == -1) {
            result = 0x2723;
        } else {
            *(s32 *)(object + 0x10) = 0;
            *(s32 *)(object + 0xC) = (s32)value;
            *(s32 *)(object + 8) = 0;
        }
    }
    return result;
}
