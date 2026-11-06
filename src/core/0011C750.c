/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_L08_0033CD18 (src/levels/shared/L08_002F2D10.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

extern s32 func_00123DF8(void *stream, const char *format, void *arguments);

/* The compiler supplies the R5900 variadic save area. The worker consumes its
 * integer-register slots; the ABI places these 0x30 below next_arg here. */
s32 func_0011C750(void *stream, const char *format, ...)
{
    return func_00123DF8(stream, format, (char *)__builtin_next_arg(format) - 0x30);
}
