/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9850(void *, u16 *);
/* Reads a packed value into its fields. */
void func_01EB8EB0(void *p, s32 *a, u16 *b)
{
  u16 x; func_01EA9850(p, &x); *a=x >> 11; *b=x & 0x7ff;
}
