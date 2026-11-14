/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00508310(s32, void *);
extern s32 D_004A1B00[];
extern s32 D_004A1B04[];
extern void func_L00_0051A9E0(void);

// When D_004A1B00 is set, passes it and the address of func_L00_0051A9E0 + 0x10 to func_L00_00508310, clears both globals, and returns 1.
s32 func_L00_0052DB30(void) {
    if (D_004A1B00[0] != 0) {
        func_L00_00508310(D_004A1B00[0], (u8 *)func_L00_0051A9E0 + 0x10);
        D_004A1B00[0] = 0;
        D_004A1B04[0] = 0;
    }
    return 1;
}
