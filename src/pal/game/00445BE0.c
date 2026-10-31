/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_00449B28(int arg0, int arg1);
__int64 func_004E8448(void);
void func_004E8560(void);
void func_004E8758(int arg0);
extern __int16 D_00206A18[];
extern int D_0021DAB4;
unsigned short D_0021EBAC = 65535;
extern float D_002212D0;
extern int D_00235A58[];
void func_00445BE0()
{
  func_004E8758(1);
  func_004E8448();
  func_004E8560();
  D_002212D0 = 0.0f;
  D_0021DAB4 = D_00235A58[0];
  func_00449B28(30, 0);
  D_00206A18[0] = D_0021EBAC;
  return;
}
