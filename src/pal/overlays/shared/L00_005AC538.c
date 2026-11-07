#include "common.h"
s32 func_L00_005AC538(f32 first,f32 second,f32 weight)
{
    return (s32)((first*weight)+((second-first)*(weight*weight)));
}
