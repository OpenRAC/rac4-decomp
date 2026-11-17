#include "common.h"

extern f32 D_001A0388[];
extern f32 D_001A0390[];

s32 func_001492B8(f32 *arg0, s32 arg1, s32 arg2) {
    s32 last = arg1 - 1;
    s32 result = 0;

    if (arg2 < last) {
        s32 off = arg2 * 4;

        if ((arg2 == 0) || (D_001A0388[0] * arg0[0] <= arg0[arg2])) {
            f32 *e = (f32 *)(off + (s32)(u8 *)arg0);
            result = arg2;
            if (D_001A0388[1] * *e <= arg0[last])
                result = last;
        }
    } else {
        if (D_001A0390[0] * arg0[0] <= arg0[last])
            result = last;
    }
    return result;
}
