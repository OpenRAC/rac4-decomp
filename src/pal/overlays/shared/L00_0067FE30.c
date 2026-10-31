/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_0046C6B0(unsigned int arg0);
int func_0047FEB0(int arg0, int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
extern int D_00223054;
extern int D_00223058;
void func_L00_0067FE30(void)
{
  if (D_00223054) {
    if (!*(_DWORD *)(D_00223054 + 184) ||
        *(unsigned char *)(*(_DWORD *)(D_00223054 + 184) + 32) == 254 ||
        *(unsigned char *)(*(_DWORD *)(D_00223054 + 184) + 32) == 253) {
      func_0046C6B0(D_00223054);
      D_00223054 = 0;
    }
  }
  if (D_00223058 && !--D_00223058)
    func_0047FEB0(8, 2, 0, 0, 0);
}
