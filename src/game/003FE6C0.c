/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_003FE7D0(void *);
extern s32 func_00403308(void *, s32, s32);

s32 func_003FE6C0(u8 *arg0)
{
    func_003FE7D0(arg0);
    return func_00403308(arg0 + 12, 0, 8);
}
