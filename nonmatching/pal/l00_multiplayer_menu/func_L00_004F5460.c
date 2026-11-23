/* Not matching yet: PAL WIP; level_00 .text 0x004F5460, 180B. Not part of the build. */
/*
 * Read-wrapper consumed arguments and error-getter address return are private native-supported
 * interfaces with current MATCH source declaration debt. Result/control/layout nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: cbfb7b9d580f0d5cee53cc7483c8bf48d507992e11a4adec4aaebfaa4c0c58ae
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_004F5460 nonmatching/pal/l00_multiplayer_menu/func_L00_004F5460.c --diff
 */
#include "common.h"

extern s32 func_L00_004FFB20(s32, s32, s32);
extern s32 *func_L00_00566230(void);
extern s32 func_L00_004F58C0(s32);

s32 func_L00_004F5460(s32 word0, s32 bufferWord, s32 request)
{
    s32 remaining = request;
    s32 buffer = bufferWord;
    s32 result;

    while (remaining > 0) {
        result = func_L00_004FFB20(word0, buffer, remaining);
        if (result < 0) {
            if (*func_L00_00566230() != 0x71) {
                return -0x262;
            }
            return func_L00_004F58C0(*func_L00_00566230());
        }
        buffer = (s32)((u32)buffer + (u32)result);
        if (result == 0) {
            break;
        }
        remaining = (s32)((u32)remaining - (u32)result);
    }
    return (s32)((u32)request - (u32)remaining);
}
