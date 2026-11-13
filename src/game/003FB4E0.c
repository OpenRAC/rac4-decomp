/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00126BB0(s32);
extern s32 D_003CB990[];
extern s32 D_356198[];

void func_003FB4E0(void)
{
    s32 v;

    v = D_003CB990[0] - 1;
    D_003CB990[0] = v;
    if (v == 0) {
        func_00126BB0(D_356198[0]);
    }
}
