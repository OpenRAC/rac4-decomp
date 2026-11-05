/* cflags:  -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;

int func_L02_004C7578(int a1)
{
  int result; // $v0

  switch ( a1 )
  {
    case 0L:
    case 1L:
    case 3L:
    case 11L:
    case 13L:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
