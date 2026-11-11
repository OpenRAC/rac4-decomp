/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EB10A0(void *);
extern void *func_01EB10E0(void *,const void *,s32);
extern void func_01EB11C8(void *,void *);
/* Runs a three-step transformation using local state. */
void func_01EB1040(const void *a,s32 b,void *c)
{
 s32 buf[24]; func_01EB10A0(buf); func_01EB10E0(buf,a,b); func_01EB11C8(buf,c);
}
