/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_L00_004FACD8(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);

// Allocates 0x34 bytes; when that fails, calls func_L00_004F84C8 with 0xB, 0xEA and 0x21 and returns the pointer.
void *func_L00_0052DBB8(void) {
    void *p = func_L00_004FACD8(0x34);

    if (p == 0) {
        func_L00_004F84C8(0xB, 0xEA, 0x21, 0, 0);
    }
    return p;
}
