/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EF370C(s32);
extern void func_01EF5A14(void *, s32, s32);
/* Allocates and initializes a record. */
void func_01EF5FE8(s32 a, s32 b, void **out, s32 d, s32 e)
{
 void *p=(void *)func_01EF370C(0x15c); func_01EF5A14(p,b,e); *out=p;
}
