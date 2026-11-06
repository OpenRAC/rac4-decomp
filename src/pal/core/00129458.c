/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef s32 (*Write)(void *context, s32 *remaining, s32 character);

extern s32 func_00128698(Write write, void *context, s32 count,
                         const char *format, void *arguments);

s32 func_00129458(Write write, void *context, s32 *remaining, const char *format, ...)
{
    /* Four remaining eight-byte GPR slots precede the first stack argument. */
    void *arguments = (char *)__builtin_next_arg(format) - 4 * sizeof(u64);
    s32 result = func_00128698(write, context, *remaining, format, arguments);

    *remaining = (s32)((u32)*remaining - (u32)result);
    return result;
}
