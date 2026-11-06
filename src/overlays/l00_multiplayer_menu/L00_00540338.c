/* cflags: @ee29 */
#include "common.h"
s32 func_0011A518();
s32 func_L00_004F84C8(s32, s32, s32, s32, s32); /* extern */
s32 func_L00_004FACD8(s32);                     /* extern */

s32 func_L00_00540338(void) {
    s32 temp_v0;

    temp_v0 = func_L00_004FACD8(0x60);
    if (temp_v0 == 0) {
        func_L00_004F84C8(6, 0x72, 0x21, 0, 0);
        return 0;
    }
    func_0011A518(temp_v0, 0, 0x60);
    return temp_v0;
}
