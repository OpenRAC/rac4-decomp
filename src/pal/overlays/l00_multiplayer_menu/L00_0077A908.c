#include "common.h"

extern s32 func_L00_0077A610(u8 *request);
extern s32 func_L00_0077A6F8(u8 *request);
extern s32 func_L00_0077A818(u8 *request);

s32 func_L00_0077A908(u8 *request)
{
    s32 result = 0;
    u32 flags = *(u32 *)request;
    if (flags & 0x200)
        func_L00_0077A610(request);
    else if (flags & 8)
        func_L00_0077A6F8(request);
    else if (flags & 2)
        result = 1;
    else if (flags & 0x40)
        func_L00_0077A818(request);
    return result;
}
