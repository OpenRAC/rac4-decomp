/* Not matching yet: BYTES 31/144 (permuter --legal 900 s; best body). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-strength-reduce */
#include "common.h"

extern s32 func_01EF2624(void *);
extern void func_01EF235C(s32, s32, s32, s32);

void func_01EF2588(s32 arg0, s32 *arg1, s32 arg2)
{
  s32 n = func_01EF2624(arg1);
  s32 i = 0;
  s32 *new_var2;
  unsigned short new_var;
  if (n > 0)
  {
    new_var2 = (s32 *) (((char *) arg1) + (i * 8));
    do
    {
      s32 *p = new_var2;
      new_var = 0;
      func_01EF235C(arg0, p[new_var], inline_fn(p), arg2);
      i++;
    }
    while (i < n);
  }
}
