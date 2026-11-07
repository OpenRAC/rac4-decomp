#include "common.h"
/* Both native float paths, with the live input updated in the negative path. */
f32 func_L02_003C5BF0(f32 value)
{
    if(value<0.0f){
        value=-value;
        return 1.0f-(value-=(f32)(s32)value);
    }
    return value-(f32)(s32)value;
}
