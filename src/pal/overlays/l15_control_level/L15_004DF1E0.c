/* cflags:  -Wuninitialized -Wa,-G0 */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;

void func_L15_004DF1E0(int a1)
{
  int result;
  result = *((int *) (a1 + 172));
  *((float *) (result + 788)) = (*((float *) (result + 784)) = 0.0025132743f);
  *((float *) (result + 792)) = 0.12566371f;
  *((float *) (result + 800)) = (*((float *) (result + 796)) = 0.14400001f);
  *((float *) (result + 804)) = 7.2000003f;
  *((_DWORD *) (result + 816)) = 1;
  return;
}
