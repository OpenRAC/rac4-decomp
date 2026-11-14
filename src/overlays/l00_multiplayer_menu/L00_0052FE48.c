/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8();
extern void *func_L00_00536290(s32 arg0);
extern s32 func_L00_005423D8(void);

// Allocate an 8-byte record and fill both fields; return NULL (and free nothing) on any failure.
void *func_L00_0052FE48(void) {
    s32 *p = (s32 *)func_L00_004FACD8(8);
    s32 temp;
    s32 buf[12];

    if (p == 0) {
        buf[11] = 0x37;
        func_L00_004F84C8(0xD, 0xDB, 0x21, 0, 0);
        return 0;
    }
    p[0] = func_L00_005423D8();
    if (p[0] == 0) {
        return 0;
    }
    temp = (s32)func_L00_00536290(4);
    p[1] = temp;
    return (temp == 0) ? 0 : p;
}
