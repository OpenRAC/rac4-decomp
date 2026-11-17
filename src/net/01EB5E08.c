/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169508;
extern char D_001B26C0[];
extern char D_001B2700[];
extern void *func_0011A518(void *, s32, s32);
extern s32 func_01E9BE70(void *, void *, s32, s32, void *, s32);
extern s32 func_01EB4D80(u8 *);
s32 func_01EB5E08(s32 *out) {
    u8 info[16];
    if (D_00169508 < 0) {
        return 0xC350;
    }
    func_0011A518(info, 0, sizeof(info));
    if (func_01E9BE70(D_001B26C0, D_001B2700, D_00169508, 11, info, sizeof(info)) != 0) {
        return 0xC350;
    }
    *out = func_01EB4D80(info);
    return 0;
}
