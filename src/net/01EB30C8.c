/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EAE980(void *);
extern void *func_01EAEA48(void *,const void *,s32);
extern void func_01EAEBE0(void *,void *,s32);
/* Runs a three-step transformation using local state. */
void func_01EB30C8(const void *a,s32 b,void *c,s32 d)
{
 s32 buf[24]; func_01EAE980(buf); func_01EAEA48(buf,a,b); func_01EAEBE0(buf,c,d);
}
