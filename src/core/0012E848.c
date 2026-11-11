/* cflags: @ee29-01 -O2 -G0 */
#include "common.h"
/* Compiler-revision lead: RAC3 docs/us/compiler_matrix_i5bootn.md (GPL-3.0). */
extern u64 func_0012FEB0(u64,u64);
/* Form both unsigned products before dividing and combining. */
u64 func_0012E848(u32 a,u32 b)
{
    u64 x=(u64)a*0x08ca0000ULL;
    u64 y=(u64)b*0x08ca0000ULL;
    u64 q=func_0012FEB0(y,1000000ULL);
    return x+q;
}
