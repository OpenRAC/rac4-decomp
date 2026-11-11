#include "common.h"

void func_L00_00772A60(s32 arg0, u8 *arg1);
void func_L00_00771A48(void *arg0)
{
  *((s32 *) (((s8 *) arg0) + 4)) = -1;
  *((s8 *) (((s8 *) arg0) + 8)) = 0;
  *((s8 *) (((s8 *) arg0) + 0x14)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xC)) = -1;
  *((s32 *) (((s8 *) arg0) + 0x10)) = -1;
  func_L00_00772A60(*((s32 *) (((s8 *) arg0) + 0x80)), arg0 + 0x68);
}
