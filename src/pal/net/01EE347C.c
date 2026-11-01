/* cflags: -O2 -G8 */
#include "common.h"

s32 func_01EE366C(s32 value);

s32 func_01EE347C(void *object) {
    u32 nonzero;
    s32 argument;
    s64 word;

    word = *(s32 *)((u8 *)object + 4);
    nonzero = word;
    argument = *(s32 *)((u8 *)object + 4);
    if (nonzero != 0) {
        func_01EE366C(argument);
    }
    return 0;
}
