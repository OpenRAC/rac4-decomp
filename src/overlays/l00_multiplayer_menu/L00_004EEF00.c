/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern int func_00126BA0();

// Zero a 0x18-byte stack block, fill three words and pass it to func_00126BA0.
void func_L00_004EEF00(s32 a0, s32 a1, s32 a2) {
    s32 buf[6];
    func_0011A518(buf, 0, 0x18);
    buf[2] = a0;
    buf[1] = a1;
    buf[5] = a2;
    func_00126BA0(buf);
}
