/* Call the first resident helper; if its result is negative return 0, otherwise forward that result to the second helper. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

s32 func_0012CB20();
s32 func_0045F410(s32);

s32 func_0045F460(void) {
    s32 temp_v0;

    temp_v0 = func_0012CB20();
    if (temp_v0 < 0) {
        return 0;
    }
    return func_0045F410(temp_v0);
}
