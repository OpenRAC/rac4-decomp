/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern char D_00199AF8[];
extern s32 func_0011D920(char *, const char *, ...);
/* Format the input string and integer into the destination. */
s32 func_01EDEB28(char *text, s32 value, s32 unused, char *out)
{
    func_0011D920(out, D_00199AF8, text, value);
    return 0;
}
