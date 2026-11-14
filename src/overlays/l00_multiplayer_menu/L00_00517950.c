/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* checks the record at arg0, starts its setup calls and returns a status code */
typedef struct Type1 {
    u8 pad0[0x1C];
    void *f1C;
} Type1;

extern s32 func_0051E240(void);
extern s32 func_L00_0051EBD0(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_L00_005206A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void *func_L00_00520E90(void);

s32 func_L00_00517950(Type1 *arg0, s32 arg1) {
    s32 var_s2;
    void *temp;

    var_s2 = 0;
    if (arg1 == 0) {
        var_s2 = 0x2721;
    } else if (arg0->f1C == 0) {
        var_s2 = 0x2722;
    } else {
        func_L00_005206A8(arg1, 1, 2, 0, func_L00_00520E90(), 0, 0);
        temp = (void *) func_0051E240();
        func_L00_0051EBD0(arg0->f1C, temp, arg1, 0, 0);
    }
    return var_s2;
}
