/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } T12;
typedef struct { s32 f0; s32 f4; T12 f8; s32 f14; s32 f18; s32 f1C; } Type2;
extern s32 func_L00_0052C0A0();

// Copy a 12-byte record into a stack block at +8, then forward it with a second stack buffer.
s32 func_L00_00520CD8(T12 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Type2 s;
    char buf[16];
    if (arg0 == 0) {
        return 0x2721;
    }
    s.f8 = *arg0;
    return func_L00_0052C0A0(&s, arg1, arg2, buf, arg3);
}
