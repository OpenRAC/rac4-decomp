/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_00517808();
s32 func_L00_00540310(s32 arg0) {
    s32 result=func_L00_00517808();
    *(s32*)(result+56)=arg0;
    return result;
}
