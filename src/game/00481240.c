#include "common.h"

extern void *func_004765F0(void);

// Looks up the global object; when its byte at +0x32 is below 5, sets +0xC to 1, flags bit 0x800 and clears +0x32, returning 1.
s32 func_00481240(void) {
    u8 *p;

    p = func_004765F0();
    if (p != NULL) {
        if (p[0x32] < 5) {
            *(s32 *)(p + 0xC) = 1;
            *(s32 *)(p + 0x4) = *(s32 *)(p + 0x4) | 0x800;
            p[0x32] = 0;
            return 1;
        }
    }
    return 0;
}
