/* cflags: -Wuninitialized */
#include "common.h"

s32 func_00549A30(s32 kind, s32 level);
s32 func_00433788(s32 level);
f32 func_00549900(s32 kind, s32 level, s32 index, s32 scale);

s32 func_00549A30(s32 kind, s32 level) {
    if (kind == 8) {
        return func_00433788(level);
    }
    return (s32)(func_00549900(kind, level, 0, 1) * 10.0f);
}
