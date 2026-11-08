/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

u16 func_01ED9088(u16 **arg0)
{
    u16 *p;

    if (arg0 == NULL) {
        return 0;
    }
    p = *arg0;
    return *p;
}
