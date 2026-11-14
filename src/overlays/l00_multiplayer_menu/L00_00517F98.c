/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_00520DC8(s32, s32, s32);
extern void *func_L00_00520E90(void);

/* Gets a pointer from func_L00_00520E90, passes it with arguments 2 and 1 to func_00520DC8, stores the result in *arg3 and returns 0 */
s32 func_L00_00517F98(s32 unused0, s32 arg1, s32 arg2, s32 *arg3) {
    (void)unused0;
    *arg3 = func_00520DC8(func_L00_00520E90(), arg2, arg1);
    return 0;
}
