/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern s32 func_00540E68(s32);
extern s32 func_L00_0051C290(s32, s32, s32);
extern s32 func_L00_0051C910(s32);
extern s32 func_L00_0051C9C8(s32);
s32 func_L00_0051A800(s32 value) {
    s32 handle = func_00540E68(value);
    if (func_L00_0051C290(func_L00_0051C910(handle), 2, value) == 0) {
        return 0;
    }
    return func_L00_0051C290(func_L00_0051C9C8(handle), 2, value);
}
