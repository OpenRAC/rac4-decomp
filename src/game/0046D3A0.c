/* cflags:  */

#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
void func_0046D110(void);
int func_0046D198(void);
void func_0046D340(void);
int func_00470BF0(unsigned int arg0, unsigned int arg1, int arg2, int arg3);
int func_004E7450(unsigned int arg0);
extern char D_00117A60[];
extern int D_002213F4;
int D_00221408 = 0;
extern int D_00221438;
void func_0046D3A0()
{
  int v0; // $a3

  func_0046D198();
  func_004E7450((unsigned int)D_00117A60);
  func_0046D110();
  v0 = 1;
  if ( D_00221438 )
  {
    D_00221438 = 0;
    v0 = 3;
  }
  D_00221408 = func_00470BF0(D_002213F4, D_00221408, -1, v0);
  func_0046D340();
}
