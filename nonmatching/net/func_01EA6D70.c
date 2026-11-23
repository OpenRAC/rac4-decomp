/* Not matching yet: BYTES 101/164 (tools/try_func.py func_01EA6D70 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
};

extern s32 func_01EA70B0(Type1 *arg0, s32 arg1);
extern s32 func_01EA71C8(void *object, s32 *out);

s32 func_01EA6D70(Type1 *arg0, u32 arg1) {
    s32 temp = 0;
    s32 result;
    s32 cur;
    s32 rem;

    if (arg0 == 0)
        return 2;
    if (arg1 == 0)
        return 0;
    result = func_01EA71C8(arg0, &temp);
    if (result != 0)
        return result;
    if (temp < arg1)
        return 0xC8;
    cur = arg0->f0;
    rem = arg0->f8 - cur;
    if (arg1 < rem) {
        arg0->f0 = cur + arg1;
    } else {
        arg0->f0 = arg1 - rem;
    }
    arg0->fC -= arg1;
    result = func_01EA70B0(arg0, 0);
    if (result != 0)
        return result;
    return 0;
}
