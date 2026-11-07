/* Not matching yet: SIZE ours 64 / retail 40 (tools/try_func.py func_L00_0052ADF0 --diff). Not part of the build. */
#include "common.h"

extern s32 func_L00_0052AE18(s32, s32);

// True when entry `index` of the table is marked.
s32 func_L00_0052ADF0(u8 *p, s32 index) {
    if (*(s32 *)p == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if (index < *(s32 *)p) {
        return func_L00_0052AE18(*(s32 *)(p + 4), index);
    }
    return 0;
}
