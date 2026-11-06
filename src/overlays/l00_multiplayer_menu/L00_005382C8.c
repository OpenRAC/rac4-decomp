/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
void func_0011A370(int arg0, unsigned int arg1, unsigned int arg2);
int func_L00_004FACD8(unsigned int arg0);
int func_L00_004FAD28(unsigned int arg0);
int func_L00_00541790(unsigned int arg0, int arg1, int arg2, int arg3);
extern int D_004A3050;
extern char D_004AFE88[];
int func_L00_005382C8(int a1, int a2)
{
  int v5;
  int v6;
  _BYTE v7[16];
  v7[0] = 0;
  func_L00_00541790((unsigned int) v7, (int) D_004AFE88, 340, ++D_004A3050);
  if ((*((int *) (a1 + 8))) < a2)
  {
    if (((*((_DWORD *) (a1 + 16))) & 2L) == 0)
    {
      v5 = func_L00_004FACD8(8 * (((int) a2) + 1));
      v6 = v5;
      if (!v5)
      {
        return 0;
      }
      else
      {
        if (*((_DWORD *) a1))
        {
          func_0011A370(v5, *((int *) a1), 8 * (*((_DWORD *) (a1 + 4))));
          func_L00_004FAD28(*((int *) a1));
          *((_DWORD *) a1) = v6;
        }
        else
        {
          *((_DWORD *) a1) = v5;
        }
        *((_DWORD *) (a1 + 8)) = a2;
        return a1;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return a1;
  }
}
