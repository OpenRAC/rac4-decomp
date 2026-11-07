/* Not matching yet: EXACT bytes, but its 3 calls to libgcc fptoui (0x131850, emitted for the float-to-u32 cast) are unresolved by tools/audit_relocs.py; land once the audit maps libgcc names (tools/try_func.py func_00498730 --diff). Not part of the build. */
#include "common.h"

u32 func_00498730(u32 color)
{
    u32 a = color & 0xFF000000;
    u32 r = color & 0xFF;
    u32 g = (color & 0xFF00) >> 8;
    u32 b = (color >> 16) & 0xFF;

    r = (u32)(r * 1.5f);
    if (r > 0xFF) r = 0xFF;
    g = (u32)(g * 1.5f);
    if (g > 0xFF) g = 0xFF;
    b = (u32)(b * 1.5f);
    if (b > 0xFF) b = 0xFF;
    return a | (b << 16) | (g << 8) | r;
}
