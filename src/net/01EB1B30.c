/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EB1C20(s32 *);
extern void *func_01EB1C60(void *,const void *,s32);
extern void func_01EB1DC0(void *,void *);
/* Runs a three-step transformation using local state. */
void func_01EB1B30(const void *a,s32 b,void *c)
{
 s32 buf[24]; func_01EB1C20(buf); func_01EB1C60(buf,a,b); func_01EB1DC0(c,buf);
}
