/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C[5]; } Info;
extern s32 func_00126AA0(s32, Info *);
s32 func_01EC2D60(s32 *out) {
    Info info;
    s32 n = 0;
    s32 i;
    if (out == 0) {
        return 2;
    }
    *out = 0;
    for (i = 0; i < 256; i++) {
        if (func_00126AA0(i, &info) != -1 && info.f0 != 0) {
            n++;
        }
    }
    *out = n;
    return 0;
}
