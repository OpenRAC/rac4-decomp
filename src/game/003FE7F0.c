/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_003FE818(void *);
extern s32 func_00403440(s32);

s32 func_003FE7F0(u8 *arg0)
{
    func_003FE818(arg0);
    return func_00403440(*(s32 *)(arg0 + 8));
}
