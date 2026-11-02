/* cflags: -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
void func_L01_00506DC8(void *);
void func_00591BD8(void * arg0, int arg1, int arg2);
void func_L01_005A8A28(void * arg0);
void func_L01_005BAE58(void * arg0, void * arg1, void * arg2, float arg3, float arg4);
void func_L01_00506D68(void *arg0)
{




  func_L01_00506DC8(arg0);
  func_L01_005BAE58(arg0, (char *)arg0 + 16, (void *)0x8000, 1.0f, 4.0f);
  func_L01_005A8A28(arg0);
  func_00591BD8(arg0, 1, 0);
  return;
}
