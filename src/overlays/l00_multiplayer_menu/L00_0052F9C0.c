/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8();
extern void *func_L00_00536290(s32 arg0);
extern s32 func_L00_005423D8(void);

// Allocate a 0xC-byte record: word 0 from func_L00_005423D8, word 1 from func_L00_00536290(3), word 2 cleared; report and return NULL on failure.
void *func_L00_0052F9C0(void) {
    s32 buf[12];
    s32 *temp_v0;
    s32 val;

    temp_v0 = func_L00_004FACD8(0xC);
    if (temp_v0 == 0) {
        buf[11] = 0x42;
        func_L00_004F84C8(0xD, 0xD7, 0x21, 0, 0);
        return 0;
    }
    val = func_L00_005423D8();
    temp_v0[0] = val;
    if (val == 0) {
        return 0;
    }
    val = (s32)func_L00_00536290(3);
    temp_v0[1] = val;
    if (val == 0) {
        return 0;
    }
    temp_v0[2] = 0;
    return temp_v0;
}
