/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 Type2;
struct Type2 {
    u64 f0;
    s32 f8;
    void (*fC)(s32, s32, s32 *, s32, u64, s32);
};

typedef struct Type1 {
    s32 f0;
    Type2 **f4;
} Type1;

s32 func_L00_0051AC38(s32 *, s32);

void func_L00_0051AD48(Type1 *arg0, s32 arg1, s32 *arg2) {
    s32 count;
    s32 i;
    Type2 *entry;

    *arg2 = 0;
    if (arg0 == 0) return;
    count = arg0->f0;
    for (i = 0; i < count; i++) {
        entry = arg0->f4[i];
        if (entry != 0 && entry->fC != 0) {
            entry->fC(arg1, func_L00_0051AC38(arg2, i), arg2, i, entry->f0, entry->f8);
        }
    }
}
