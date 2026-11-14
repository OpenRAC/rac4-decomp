/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_00520D90(void *arg0, s32 arg1, s32 arg2);
extern void *func_L00_00520E90(void);

// Forwards two fields of the argument to func_L00_00520D90 and returns 0.
s32 func_L00_00517F60(s32 arg0, s32 *arg1) {
    func_L00_00520D90(func_L00_00520E90(), arg1[1], arg1[0]);
    return 0;
}
