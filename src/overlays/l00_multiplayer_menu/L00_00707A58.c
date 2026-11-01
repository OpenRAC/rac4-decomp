/* cflags: @ee29 -O2 -G8 */
#include "common.h"



s32 func_L00_0061DE00(s32);
s32 func_L00_00712418();
s32 func_L00_00718480();
s32 func_L00_007731F8();
extern s32 D_002209B8;
extern s8 D_002209BC;


s32 func_L00_00707A58(void) {
    s32 result;
    D_002209BC = 0;
    func_L00_00712418();
    func_L00_00718480();
    func_L00_007731F8();
    result = func_L00_0061DE00(D_002209B8);
    D_002209B8 = 0;
    return result;
}
