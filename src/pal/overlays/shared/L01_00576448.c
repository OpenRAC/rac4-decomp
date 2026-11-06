/* cflags: @ee29 -O2 -G0 */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"
#define __int64 long
#define __int16 short
#define __int8 char
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD;
extern u8 D_0024F220;
float func_L01_00576448(void *arg0, void *arg1)
{
  float result; // $f0
  char *v3; // $a0
  int v4; // $v0

  result = *((float *)arg0 + 6) * *((float *)arg1 + 2);
  v3 = (char *)&D_0024F220 + 48 * *((unsigned __int16 *)arg1 + 10);
  v4 = *((unsigned __int16 *)v3 + 12) + (int)result;
  if ( v4 >= 1025 )
    v4 = (u16)(1024);
  *((_WORD *)v3 + 12) = v4;
  return result;
}
