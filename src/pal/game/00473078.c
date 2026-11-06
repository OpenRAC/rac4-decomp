#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern u32 D_00222110;
extern f32 func_00472F70(void);
extern f32 func_00472EB8(f32, f32);
extern u128 func_004FF8C0(void *, f32, f32, f32);

void func_00473078(u128 *result, f32 minimum, f32 maximum)
{
    f32 first = func_00472F70();
    f32 second = func_00472F70();
    f32 magnitude = func_00472EB8(minimum, maximum);
    *result = func_004FF8C0(&D_00222110, magnitude, first, second);
}
