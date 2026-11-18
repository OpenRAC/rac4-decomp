/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0012BF10();
extern void func_00155A98();
extern s32 func_01EAB228(void *arg0);
extern s32 D_001965C8[];
extern s32 D_1B23F8[];

// Reads a packed-BCD time block into a table and validates it, returning 0 or 0x640.
s32 func_01EAB700(void) {
    u8 buf[8];

    if (func_0012BF10(D_001965C8, 0x430C, 0, 0, buf, 8) < 0) {
        return 0x640;
    }
    func_00155A98(buf);
    D_1B23F8[0] = 0;
    D_1B23F8[1] = (buf[1] >> 4) * 10 + (buf[1] & 0xF);
    D_1B23F8[2] = (buf[2] >> 4) * 10 + (buf[2] & 0xF);
    D_1B23F8[3] = (buf[3] >> 4) * 10 + (buf[3] & 0xF);
    D_1B23F8[4] = (buf[5] >> 4) * 10 + (buf[5] & 0xF);
    D_1B23F8[5] = (buf[6] >> 4) * 10 + (buf[6] & 0xF);
    D_1B23F8[6] = (buf[7] >> 4) * 10 + (buf[7] & 0xF);
    return func_01EAB228(D_1B23F8 + 8) == 0 ? 0 : 0x640;
}
