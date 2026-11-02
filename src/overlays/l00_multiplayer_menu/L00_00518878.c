/* Call the overlay helper, store the returned word at +0x1C, and return 0 if nonzero or 10005 otherwise. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1C];
    s32 f1C;
};

s32 func_L00_0051EB20();

s32 func_L00_00518878(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = func_L00_0051EB20();
    arg0->f1C = temp_v0;
    return (temp_v0 != 0) ? 0 : 0x2715;
}
