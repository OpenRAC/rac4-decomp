/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct Type1 Type1;

extern s64 func_L00_00527840(Type1 *, s32, s32, s32, u64, s32 *);
extern s32 func_L00_00506250(Type1 *, s32, s32);
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);

// Reads the expected message and reports an unexpected nonempty body.
s32 func_L00_00504388(Type1 *arg0)
{
    s32 complete;
    s64 size = func_L00_00527840(arg0, 0x1160, 0x1161, 0xE, 0x1E, &complete);

    if (!complete) {
        return size;
    }
    if (size > 0) {
        func_L00_00506250(arg0, 2, 0x32);
        func_L00_004F89C8(0x14, 0x91, 0x9F, NULL, 0);
    }
    return 1;
}
