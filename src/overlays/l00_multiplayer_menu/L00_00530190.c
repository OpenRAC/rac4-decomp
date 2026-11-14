/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8();
extern void *func_L00_00536290(s32 arg0);

// Allocate an 8-byte record: word 0 and word 1 from func_L00_00536290(0x17); report and return NULL on failure, NULL when either word is zero.
void *func_L00_00530190(void) {
    s32 buf[12];
    s32 *temp_v0;
    s32 val;

    temp_v0 = func_L00_004FACD8(8);
    if (temp_v0 == 0) {
        buf[11] = 0x37;
        func_L00_004F84C8(0xD, 0xDD, 0x21, 0, 0);
        return 0;
    }
    val = (s32)func_L00_00536290(0x17);
    temp_v0[0] = val;
    if (val == 0) {
        return 0;
    }
    val = (s32)func_L00_00536290(0x17);
    temp_v0[1] = val;
    return (val == 0) ? 0 : temp_v0;
}
