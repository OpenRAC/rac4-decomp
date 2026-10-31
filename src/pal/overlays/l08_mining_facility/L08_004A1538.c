/* cflags: -Wuninitialized */
/* cflags:  -Wuninitialized */
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

M2C_UNK func_0046C6B0(void *);                      /* extern */
M2C_UNK func_00474368(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_004E2EF0(M2C_UNK, M2C_UNK, void *);    /* extern */
M2C_UNK func_L08_004A1760(void *);                  /* extern */
extern s32 D_0021E714;

void func_L08_004A1538(void *arg0) {
  s32 var_3;
  u8 temp_3;
  u8 temp_3_2;
  if (D_0021E714 != 0)
  {
    goto block_12;
  }
  temp_3 = *((u8 *) (((u8 *) arg0) + 0x20));
  if (temp_3 == 0)
  {
    goto block_6;
  }
  if (temp_3 != 2)
  {
    goto block_4;
  }
  ;
  goto block_7;
  block_4:
  return;

  ;
  block_6:
  *((s32 *) (((u8 *) arg0) + 0x98)) = (s32) (*((s32 *) (((u8 *) (*((void **) (((u8 *) arg0) + 0x24)))) + 0x10)));

  func_00474368(arg0, 1, -1);
  return;
  block_7:
  if (!(((*((u8 *) (((u8 *) arg0) + 0xBE))) ^ 1) & 1))
  {
    goto block_9;
  }

  var_3 = 1;
  *((u8 *) (((u8 *) arg0) + 0xBE)) = (u8) ((*((u8 *) (((u8 *) arg0) + 0xBE))) | 1);
  goto block_10;
  block_9:
  var_3 = 0;

  block_10:
  if (var_3 == 0)
  {
    goto block_12;
  }

  func_L08_004A1760(arg0);
  func_004E2EF0(1, 0, arg0);
  func_0046C6B0(arg0);
  block_12:
  return;

}
