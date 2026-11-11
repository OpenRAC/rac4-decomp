/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EE3A18(s32,void *);
/* Stores a successful helper result. */
s32 func_01EF339C(s32 a,void *b,void *out)
{
 s32 x=func_01EE3A18(a,b); if(x){*(s32 *)out=x; return 1;} return x;
}
