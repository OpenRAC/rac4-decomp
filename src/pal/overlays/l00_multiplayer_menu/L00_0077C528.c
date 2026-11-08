#include "common.h"

void func_L00_0077E500(s32 object, u8 *arg1);
void func_L00_0077E5B0(s32 object, u8 *arg1);
void func_L00_0077C528(void *object)
{
  *((s8 *) (((s8 *) object) + 4)) = 0;
  *((s8 *) (((s8 *) object) + 0xC0)) = 0;
  *((s8 *) (((s8 *) object) + 0xE4)) = 0;
  *((s8 *) (((s8 *) object) + 0xEC)) = 0;
  *((s8 *) (((s8 *) object) + 0xF4)) = 0;
  *((s8 *) (((s8 *) object) + 0x15D)) = 0;
  *((s8 *) (((s8 *) object) + 0x168)) = 0;
  *((s8 *) (((s8 *) object) + 0x199)) = 0;
  *((s8 *) (((s8 *) object) + 0x1A4)) = 0;
  *((s32 *) (((s8 *) object) + 0)) = -1;
  *((s32 *) (((s8 *) object) + 0x160)) = -1;
  *((s32 *) (((s8 *) object) + 0x164)) = -1;
  *((s32 *) (((s8 *) object) + 0x16C)) = 0x2710;
  *((s32 *) (((s8 *) object) + 0x1A8)) = 0x2710;
  *((s32 *) (((s8 *) object) + 0x170)) = -1;
  *((s32 *) (((s8 *) object) + 0x19C)) = -1;
  *((s32 *) (((s8 *) object) + 0x1A0)) = -1;
  *((s32 *) (((s8 *) object) + 0x1AC)) = -1;
  func_L00_0077E500(*((s32 *) (((s8 *) object) + 0x190)), (u8 *)object + 0x178);
  func_L00_0077E5B0(*((s32 *) (((s8 *) object) + 0x1CC)), (u8 *)object + 0x1B4);
}
