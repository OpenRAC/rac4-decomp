/* cflags: -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
int func_005DD4A0(unsigned int arg0);
int func_005F5068(int arg0, int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
extern int D_00222F54;
extern int D_00222F58;
void func_L00_0067C7B8(void)
{
  if (D_00222F54) {
    if (!*(_DWORD *)(D_00222F54 + 184) ||
        *(unsigned char *)(*(_DWORD *)(D_00222F54 + 184) + 32) == 254 ||
        *(unsigned char *)(*(_DWORD *)(D_00222F54 + 184) + 32) == 253) {
      func_005DD4A0(D_00222F54);
      D_00222F54 = 0;
    }
  }
  if (D_00222F58 && !--D_00222F58)
    func_005F5068(8, 2, 0, 0, 0);
}
