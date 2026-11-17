/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA7248(s32 *arg0, s32 *arg1) {
    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    *arg1 = arg0[2] - arg0[3];
    return 0;
}
