/* cflags: @ee296 -O2 -G0 */
/* Not matching yet: BYTES 6/44 (2 words differ) (tools/try_func.py func_004F5E18 --diff). Not part of the build. */
#include "common.h"
extern char D_00221218[];
extern void func_004493E8(void *a, void *b, s32 c);
extern void func_004F5E48(void);
void func_004F5E18(s32 arg)
{
  void (*new_var)(void);
  new_var = func_004F5E48;
 do { func_004493E8(D_00221218, new_var, arg); } while (0);
}
