/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char pad[0x408]; s32 f408; } Type1;
// Sets the output default and copies the context value if available.
s32 func_01EC9B08(s32 *out, Type1 *ctx) {
    s32 result = 0x17;
    if (out == NULL) return result;
    *out = 0x100;
    if (ctx == NULL) return result;
    { s32 value = ctx->f408; result = 0; *out = value; }
    return result;
}
