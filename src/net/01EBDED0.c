/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char pad[0x70]; s32 f70; } Type1;
// Clears the output and copies the context value when available.
s32 func_01EBDED0(Type1 *arg0, s32 *arg1) {
    s32 result = 0xD2F2;
    *arg1 = 0;
    if (arg0 == NULL) return result;
    {
        s32 value = arg0->f70;
        result = 0;
        *arg1 = value;
    }
    return result;
}
