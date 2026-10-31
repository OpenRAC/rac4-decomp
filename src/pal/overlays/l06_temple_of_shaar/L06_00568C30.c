/* cflags:  -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
extern u32 D_00222780;
int func_L06_00568C30(int a1)
{
  int v1; // $a1
  int v2; // $a2
  unsigned int v3; // $v1

  v1 = (s32)(0);
  if ( D_00222780 )
  {
    v2 = *(int *)(D_00222780 + 12308);
    v3 = *(_DWORD *)(D_00222780 + 12312);
    if ( v2 > 0 )
    {
      do
      {
        if ( *(_WORD *)v3 == 1 )
        {
          if ( *(_DWORD *)(v3 + 12) == a1 )
            return (unsigned __int16)v1;
          v1 = (int)v1 + 1;
        }
        else
        {
          v1 = (int)v1 + 1;
        }
        v3 += 32;
      }
      while ( v1 < v2 );
    }
  }
  return 0xFFFF;
}
