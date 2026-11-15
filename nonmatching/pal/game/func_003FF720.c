/* Not matching yet: 21/26 (80.77%) relocation-masked positional words; 104/104 candidate/target bytes. The D_003CCEC0 pointee and owner are unknown. Reproduce: python tools/check_func.py --version pal func_003FF720 nonmatching/pal/game/func_003FF720.c --diff. Not part of the build. */
/* cflags:  -Wuninitialized */
#include "common.h"

/* 21/26 target words match (80.77%) under relocation-masked positional
 * comparison; 104/104 bytes. Branch, delay slot and register choices differ.
 * Callees use their matched PAL signatures; the extent and owner of the
 * D_003CCEC0 pointee remain unknown. Verify with
 * tools/diff_func.py --version pal func_003FF720. */
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

void func_003FD508(u8 *);                      /* extern */
s32 func_003FE6C0(u8 *);                      /* extern */
s32 func_004033B0(s32);                       /* extern */
extern M2C_UNK D_003CCEC0;

s32 func_003FF720(void **arg0) {
  void *temp_2;
  temp_2 = (void *)func_004033B0(0x30);
  *arg0 = temp_2;
  if (temp_2 != ((void *) 0))
  {
    func_003FE6C0(temp_2);
    func_003FD508((u8 *)temp_2 + 0x14);
    *((void **) (((u8 *) temp_2) + 0x2C)) = temp_2;
    *((M2C_UNK **) (((u8 *) temp_2) + 0x28)) = &D_003CCEC0;
    return 0;
  }
  else
  {
    return 0x206;
  }
}

