#include "common.h"

extern s32 func_L00_00775238(u8 *request);
extern s32 func_L00_00775320(u8 *request);
extern s32 func_L00_00775440(u8 *request);

s32 func_L00_00775530(u8 *request)
{
    s32 result = 0;
    u32 flags = *(u32 *)request;
    if (flags & 0x200)
        func_L00_00775238(request);
    else if (flags & 8)
        func_L00_00775320(request);
    else if (flags & 2)
        result = 1;
    else if (flags & 0x40)
        func_L00_00775440(request);
    return result;
}
