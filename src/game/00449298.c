/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
void func_00453718(unsigned int arg0, unsigned int arg1, int arg2);
void func_004E7B88(void);
extern int D_0021DA30;
extern int D_00221E20;
extern u8 D_003DA570[];
extern u8 D_003DA5E0[];
int func_00449298(int a1, int a2)
{
  int v2; // $s0
  int v4; // $v0
  int v5; // $v1

  v2 = D_0021DA30 >> 8;
  if ( a2 == 20 )
  {
    func_00453718(D_00221E20, (unsigned int)&D_003DA570, 112);
    D_0021DA30 += 256;
  }
  else
  {
    func_00453718(D_00221E20, (unsigned int)&D_003DA5E0, 112);
    D_0021DA30 += 1024;
  }

  v5 = D_00221E20;
  *(_DWORD *)(D_00221E20 + 100) = a1;
  *(_WORD *)(v5 + 36) = v2;
  D_00221E20 += 112;
  func_004E7B88();
  return v2;
}
