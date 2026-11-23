/* Not matching yet: SIZE ours 160 / retail 156 (tools/try_func.py func_01EA6C60 --diff). Not part of the build. */
#include "common.h"
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EA9550(s32 *, s64);
typedef struct Type1 Type1;
struct Type1
{
  s32 f0;
  s32 f4;
  s32 f8;
  s32 fC;
  s32 f10;
  s32 f14;
};
/* Initialises the object and stores arg1/arg2; 2 with no object, 0x64 on failure. */
s32 func_01EA6C60(Type1 *arg0, s64 arg1, s32 arg2)
{
  s32 result = 2;
  s32 *handle;
  if (arg0 != 0 && arg1 != 0)
  {
    handle = &arg0->f10;
    func_0011A518(arg0, 0, 0x18);
    result = func_01EA9550(handle, (u64)((u32)arg1));
    if (result != 0)
    {
      return 0x64;
    }
    if (*handle != 0)
    {
      arg0->f14 = arg2;
      arg0->f8 = (s32)arg1;
      arg0->f0 = 0;
      arg0->f4 = 0;
      arg0->fC = 0;
      return result;
    }
    return 0x64;
  }
  return result;
}
