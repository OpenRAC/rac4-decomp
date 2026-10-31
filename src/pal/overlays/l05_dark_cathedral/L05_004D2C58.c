/* cflags: -Wuninitialized */
#include "common.h"
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef solver_u128 _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
typedef char solver_guard_int32[(sizeof(int)==4)?1:-1];
typedef char solver_guard_u32[(sizeof(u32)==4)?1:-1];
typedef char solver_guard_s32[(sizeof(s32)==4)?1:-1];
typedef char solver_guard_ptr32[(sizeof(void *)==4)?1:-1];
typedef char solver_guard_quad128[(sizeof(solver_u128)==16)?1:-1];
int func_0046C6B0(void *arg0);
extern char *D_00222CA0;
void func_L05_004D2C58(void *a1)
{
  char *quad_base_v1;
  char *v1; // $a1

  v1 = *(char **)((char *)a1 + 172);
  if ( *(s32 *)(v1 + 48) == -1 )
    { (void)(func_0046C6B0(a1)); return; }
  *(_BYTE *)((char *)a1 + 48) = -1;
  { u32 quad_offset_tmp = (u32)*(s32 *)(v1 + 48) << 7; quad_base_v1 = (char *)(quad_offset_tmp + (u32)D_00222CA0); }
  {
    solver_u128 quad_value = *(solver_u128 *)((char *)quad_base_v1 + 48);
    *(solver_u128 *)((char *)v1 + 32) = quad_value;
  }
  return;
}
