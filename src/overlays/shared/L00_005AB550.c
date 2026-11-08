#include "common.h"

/* from rac3-decomp's func_L01_00400368 */
s32 func_L00_005AB550(f32 a,f32 b,f32 t) {
 f32 difference=b-a;
 f32 squared=t*t;
 a=a*t;
 difference=difference*squared;
 a=a+difference;
 return (s32)a;
}
