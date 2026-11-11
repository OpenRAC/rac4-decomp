/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void *func_01EEDCD0(void *, const void *, s32);
extern char D_0019DBA8[];
/* Initializes a record. */
s32 func_01F0026C(void *record)
{
 u8 *p=record;
 void *result = func_01EEDCD0(p+0x38,D_0019DBA8,0x40); *(s32*)(p+8)=0; return (s32)result;
}
