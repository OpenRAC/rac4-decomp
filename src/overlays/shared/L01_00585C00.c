#include "common.h"

extern void *func_L00_005EAB50(void);
extern void *func_L00_005DEBD0(s32, s32, s32);
extern s32 D_00222D14;

// Recursive check over the two D_00222D14 entries linked from func_L00_005EAB50's
// record (+4 and 0): returns 1 when the first passes; returns 0 when the
// second is set and fails; otherwise asks the callback registered for this
// object's type (table 0x11, at 0).
s32 func_L01_00585C00(u8 *object) {
    u8 *data = (u8 *)func_L00_005EAB50();
    s32 first = *(s32 *)(data + 4);
    s32 second;
    void *callback;

    if (first != -1 && func_L01_00585C00((u8 *)(D_00222D14 + (first << 8))) != 0) return 1;
    second = *(s32 *)data;
    if (second != -1 && func_L01_00585C00((u8 *)(D_00222D14 + (second << 8))) == 0) return 0;
    callback = func_L00_005DEBD0(*(s16 *)(object + 0xBC), 0x11, 0xC);
    return callback == 0 ? 0 : ((s32 (*)(void *))*(void **)((u8 *)callback))(object);
}
