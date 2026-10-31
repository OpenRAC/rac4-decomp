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

void *func_0046C1F0(M2C_UNK, M2C_UNK);              /* extern */

void func_L11_00408DE8(s32 arg0, s32 arg1, s32 arg2) {
  void *temp_2;
  void *temp_2_2;
  temp_2 = func_0046C1F0(0x275E, 0x10);
  if (temp_2 != ((void *) 0))
  {
    temp_2_2 = *((void **) (((u8 *) temp_2) + 0xAC));
    *((unsigned char *) (((u8 *) temp_2) + 0x30)) = 0xFF;
    *((s32 *) (((u8 *) temp_2_2) + 4)) = arg0;
    *((s32 *) (((u8 *) temp_2_2) + 8)) = arg1;
    *((s32 *) (((u8 *) temp_2_2) + 0xC)) = arg2;
    *((s32 *) (((u8 *) temp_2_2) + 0)) = 0x96;
  }
}
