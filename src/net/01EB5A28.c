/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC[];
extern s32 D_00169500[];
/* Copy the current value if initialized. */
s32 func_01EB5A28(s32 *p)
{
    if (!D_001694FC[0]) return 5;
    *p = D_00169500[0];
    return 0;
}
