/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_01F07100();
s32 func_01F072C8();

s32 func_01F070D0(s32 arg0) {
    s32 result = func_01F07100();
    return func_01F072C8(result, arg0);
}
