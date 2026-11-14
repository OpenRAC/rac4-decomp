/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_L00_005466E8(void *dv, void *rm, void *m, void *d, void *ctx);

/* Calls func_L00_005466E8 with a null first argument and its other four arguments shifted along by one. */
int func_L00_00537CE8(void *arg0, void *arg1, void *arg2, void *arg3)
{
    return func_L00_005466E8(0, arg0, arg1, arg2, arg3);
}
