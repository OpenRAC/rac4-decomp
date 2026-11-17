/* cflags: @ee29 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(s32);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type1;

void func_L00_00537FB0(Type1 *arg0)
{
  s32 var_s0;
  if (arg0 == 0)
  {
    return;
  }
  if (arg0->f0 != 0)
  {
    func_0011A518((void *) arg0->f0, 0, arg0->f8 << 3);
    var_s0 = arg0->f10 & 1;
    if (!(arg0->f10 & 2))
    {
      func_004FAD28(arg0->f0);
      var_s0 = arg0->f10 & 1;
    }
  }
  else
  {
  }
  var_s0 = arg0->f10 & 1;
  func_0011A518(arg0, 0, 0x14);
  if (var_s0 != 0)
  {
    func_004FAD28((s32) arg0);
  }
}
