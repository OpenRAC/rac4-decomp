/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8();
extern s32 func_L00_0051C858(s32);

// Allocate an 8-byte record, store func_L00_0051C858(0) in its first word and clear the second; report and return NULL on failure.
void *func_L00_005423D8(void) {
    s32 buf[12];
    s32 *temp_v0;

    temp_v0 = func_L00_004FACD8(8);
    if (temp_v0 != 0) {
        temp_v0[0] = func_L00_0051C858(0);
        temp_v0[1] = 0;
        return temp_v0;
    }
    buf[11] = 0x40;
    func_L00_004F84C8(0xD, 0xCA, 0x21, 0, 0);
    return 0;
}
