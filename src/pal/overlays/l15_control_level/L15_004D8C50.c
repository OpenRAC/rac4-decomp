/* cflags: -Wuninitialized -Wa,-G0 */
/* cflags:  -Wuninitialized -Wa,-G0 */
#include "common.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
typedef long long s128; typedef unsigned long long u128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))
#define M2C_R5900_PAND(a,b) __builtin_pand((u128)(a),(u128)(b))
#define M2C_R5900_POR(a,b) __builtin_por((u128)(a),(u128)(b))
#define M2C_R5900_PCPYLD(a,b) __builtin_pcpyld((u128)(a),(u128)(b))
#define M2C_R5900_PEXTLW(a,b) __builtin_pextlw((u128)(a),(u128)(b))
#define M2C_R5900_PEXTUW(a,b) __builtin_pextuw((u128)(a),(u128)(b))
#define M2C_R5900_PROT3W(a) __builtin_prot3w((u128)(a))

int func_00472E70(int, int);
void func_L01_0044BBA0(void *, int, float);
extern int D_00222794;
int D_002227E0 = 0;
extern s16 *D_00288C20[];
void func_L15_004D8C50(void *arg0, s32 arg1, s32 arg2) {
  s32 temp_3;
  s32 temp_4;
  s16 *var_16;
  u32 object;
  s32 var_3;
  void *temp_17;
  temp_17 = *((void **) (((u8 *) arg0) + 0xAC));
  temp_3 = *((s32 *) (((u8 *) temp_17) + 0x1E4));
  if (arg1 != 0)
  {
    goto block_3;
  }
  if (temp_3 != 0)
  {
    goto block_4;
  }
  return;
  block_3:
  if (temp_3 == 3)
  {
    goto block_21;
  }

  block_4:
  *((s32 *) (((u8 *) temp_17) + 0x1EC)) = 0;

  if (arg2 == 0)
  {
    goto block_6;
  }
  var_3 = 4;
  goto block_7;
  block_6:
  var_3 = func_00472E70(1, 3);

  block_7:
  *((s32 *) (((u8 *) temp_17) + 0x1E8)) = var_3;

  *((s32 *) (((u8 *) temp_17) + 0x1E4)) = (s32) ((arg1 == 0) ? (0) : (3));
  if (arg2 == 0)
  {
    goto block_21;
  }
  var_16 = D_00288C20[*((s32 *) (((u8 *) temp_17) + 0x1D4))];
  for (;;)
  {
    temp_4 = *((s32 *) (((u8 *) temp_17) + 0x1D4));
    if ((temp_4 & 0xFF) == 0xFF)
    {
      break;
    }
    if (D_002227E0 < temp_4)
    {
      break;
    }
    if (var_16 == 0)
    {
      break;
    }
    if ((var_16[-1] < 0) && (var_16 != D_00288C20[temp_4]))
    {
      break;
    }
    object = ((u32) D_00222794) + ((((u32) (*((u16 *) var_16))) & 0x7FFF) << 8);
    if (object == 0)
    {
      break;
    }
    var_16++;
    func_L01_0044BBA0((void *) object, *((s32 *) (((u8 *) temp_17) + 0x1E4)), 500.5f);
  }

  *((s32 *) (((u8 *) temp_17) + 0x1E8)) = 0;
  block_21:
  return;

}
