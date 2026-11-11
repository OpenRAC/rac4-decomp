/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00126BB0(s32);
extern s32 func_01E9DD68(void *);
extern s32 func_01E9DD18(void *);
/* Destroys a handle and its embedded state. */
s32 func_01E9B290(s32 *p)
{
 s32 *q=p; func_00126BB0(*q); func_01E9DD68((u8*)q+0x44); func_01E9DD18(&q); return 0;
}
