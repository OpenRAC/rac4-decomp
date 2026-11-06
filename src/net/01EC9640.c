/* cflags: @ee296 -O2 -G0 */
/* Not matching yet: BYTES 44/128 (tools/try_func.py func_01EC9640 --diff). Not part of the build. */
#include "common.h"
s32 func_01EA42D8(s32);
s32 func_01EA57B8(void);
s32 func_01EA57F8(void);
s32 func_01ECFBD8(s32,s32,s32,s32);
s32 func_01EC9640(s32 a0,s32 a1,s32 a2,s32 a3) {
    s32 result=func_01EA42D8(func_01EA57B8());
    if (result == 0) {
       s32 saved=func_01ECFBD8(a0,a1,a2,a3);
       s32 check=func_01EA42D8(func_01EA57F8());
       if(check == 0) result=saved; else result=check;
    }
    return result;
}
