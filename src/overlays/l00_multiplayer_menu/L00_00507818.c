/* cflags: @ee29 */
#include "common.h"

extern char D_004ACE68[];

typedef struct S_arg1 S_arg1;
struct S_arg1 {
    char _p0[0x44];
    s32 f44;
};

s32 func_L00_004FAAC0(s32, s32, s32, s32);
s32 func_L00_005078A8(s32, void *);


s32 func_L00_00507818(s32 arg0, S_arg1 *arg1) {
    s32 var_s1;
    char *base;

    if ((arg1 != NULL) && (arg1->f44 != 0)) {
        base = D_004ACE68;
        func_L00_004FAAC0(9, 0xC, (s32) base, 0x14B);
        var_s1 = func_L00_005078A8(arg0, arg1);
        func_L00_004FAAC0(0xA, 0xC, (s32) base, 0x14D);
    } else {
        var_s1 = 0;
    }
    return var_s1;
}
