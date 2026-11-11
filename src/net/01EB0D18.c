/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_01EB0D78(void *);
extern void *func_01EB0D98(void *,const void *,s32);
extern void func_01EB0E58(void *,void *);
/* Runs a three-step transformation using local state. */
void func_01EB0D18(const void *a,s32 b,void *c)
{
 s32 buf[16]; func_01EB0D78(buf); func_01EB0D98(buf,a,b); func_01EB0E58(buf,c);
}
