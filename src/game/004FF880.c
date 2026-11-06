#include "common.h"

s32 func_004FF880(s32 *arg0,s32 arg1) {
    if(arg1<*arg0) return (s32)&arg0[arg1+1];
    return 0;
}
