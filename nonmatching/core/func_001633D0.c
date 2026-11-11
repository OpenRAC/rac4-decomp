/* Not matching yet: BYTES 31/56 (tools/try_func.py func_001633D0 --diff). Not part of the build. */
/* cflags: @ee32-040921 -O2 -G0 -mno-split-addresses */
#include "common.h"
extern u32 D_0021DC80[];
/* Advances the stored pseudorandom state. */
u32 func_001633D0(void)
{ u32 x=D_0021DC80[0]*0x3343fd+0x269ec3; D_0021DC80[0]=x; return x&0x7fffffff; }
