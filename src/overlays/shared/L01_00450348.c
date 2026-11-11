#include "common.h"

void func_00453718(void *destination, const void *source, u32 bytes);
f32 func_004756D0(f32 first, f32 last, f32 fraction);
s32 func_004756A8(s32 first, s32 last, f32 fraction);
void func_L01_00450348(void *arg0, void *arg1, void *arg2, f32 fparg0)
{
  if ((arg1 == arg2) || (fparg0 <= 0.0f))
  {
    func_00453718(arg0, arg1, 0x20U);
  }
  else
    if (fparg0 >= 1.0f)
  {
    func_00453718(arg0, arg2, 0x20U);
  }
  else
  {
    *((f32 *) (((s8 *) arg0) + 0)) = func_004756D0(*((f32 *) (((s8 *) arg1) + 0)), *((f32 *) (((s8 *) arg2) + 0)), fparg0);
    *((f32 *) (((s8 *) arg0) + 4)) = func_004756D0(*((f32 *) (((s8 *) arg1) + 4)), *((f32 *) (((s8 *) arg2) + 4)), fparg0);
    *((f32 *) (((s8 *) arg0) + 8)) = func_004756D0(*((f32 *) (((s8 *) arg1) + 8)), *((f32 *) (((s8 *) arg2) + 8)), fparg0);
    *((f32 *) (((s8 *) arg0) + 0xC)) = func_004756D0(*((f32 *) (((s8 *) arg1) + 0xC)), *((f32 *) (((s8 *) arg2) + 0xC)), fparg0);
    *((f32 *) (((s8 *) arg0) + 0x10)) = func_004756D0(*((f32 *) (((s8 *) arg1) + 0x10)), *((f32 *) (((s8 *) arg2) + 0x10)), fparg0);
    *((s8 *) (((s8 *) arg0) + 0x14)) = func_004756A8(*((u8 *) (((s8 *) arg1) + 0x14)), *((u8 *) (((s8 *) arg2) + 0x14)), fparg0);
    *((s8 *) (((s8 *) arg0) + 0x15)) = func_004756A8(*((u8 *) (((s8 *) arg1) + 0x15)), *((u8 *) (((s8 *) arg2) + 0x15)), fparg0);
    *((s8 *) (((s8 *) arg0) + 0x16)) = func_004756A8(*((u8 *) (((s8 *) arg1) + 0x16)), *((u8 *) (((s8 *) arg2) + 0x16)), fparg0);
    *((s8 *) (((s8 *) arg0) + 0x17)) = func_004756A8(*((u8 *) (((s8 *) arg1) + 0x17)), *((u8 *) (((s8 *) arg2) + 0x17)), fparg0);
  }
}
