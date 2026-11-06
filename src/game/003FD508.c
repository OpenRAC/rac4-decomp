/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00403210(void *);

void func_003FD508(u8 *object)
{
    func_00403210(object + 8);
    *(s32 *)object = 0;
}
