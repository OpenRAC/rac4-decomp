/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char pad[0x404]; s32 f404; } Type1;
// Sets the output default and copies the context value if available.
s32 func_01EA0610(s32 *out, Type1 *ctx) {
    s32 result = 0x17;
    if (out == NULL) return result;
    *out = 0x100;
    if (ctx == NULL) return result;
    { s32 value = ctx->f404; result = 0; *out = value; }
    return result;
}
