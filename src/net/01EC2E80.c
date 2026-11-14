/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 w[12]; } Info;
extern void *func_0011A518(void *, s32, u32);
extern s32 func_00126AA0(s32, Info *);
s32 func_01EC2E80(s32 id, Info *out, u32 size, s32 *outlen) {
    Info info;
    if (outlen == 0) {
        return 2;
    }
    *outlen = 0;
    if (out == 0) {
        return 2;
    }
    if (size < sizeof(Info)) {
        return 2;
    }
    func_0011A518(&info, 0, sizeof(Info));
    if (func_00126AA0(id, &info) != -1) {
        *out = info;
        *outlen = sizeof(Info);
    }
    return 0;
}
