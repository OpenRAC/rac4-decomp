/* Not matching yet: 15/26 (57.69%) relocation-masked positional words; 104/104 candidate/target bytes. Pointee bounds, alignment and return usage remain unproved. Reproduce: python tools/check_func.py --version pal func_L01_0045C538 nonmatching/pal/l01_dreadzone_station/func_L01_0045C538.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 15/26 target positions match (57.69%) under relocation-masked positional
 * comparison; 104/104 bytes. Branch and register scheduling differ. A prior
 * candidate used an unsequenced pointer assignment and was corrected here.
 * Pointee alignment, extents and return usage remain unproved. Verify with
 * tools/diff_func.py --version pal func_L01_0045C538. */
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
typedef solver_s128 s128; typedef solver_u128 u128;
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))
#define M2C_R5900_PAND(a,b) __builtin_pand((u128)(a),(u128)(b))
#define M2C_R5900_POR(a,b) __builtin_por((u128)(a),(u128)(b))
#define M2C_R5900_PCPYLD(a,b) __builtin_pcpyld((u128)(a),(u128)(b))
#define M2C_R5900_PEXTLW(a,b) __builtin_pextlw((u128)(a),(u128)(b))
#define M2C_R5900_PEXTUW(a,b) __builtin_pextuw((u128)(a),(u128)(b))
#define M2C_R5900_PROT3W(a) __builtin_prot3w((u128)(a))
typedef char m2c_fpr_width[(sizeof(f32)==4)?1:-1];

void func_L01_005A5EB0(void *);                        /* extern */

void func_L01_0045C538(void *arg0) {
  void **new_var;
  s128 var_2;
  s32 temp_2;
  void *temp_16;
  void *var_3;
  temp_16 = *((void **) (((u8 *) arg0) + 0xAC));
  func_L01_005A5EB0(arg0);
  var_3 = *((void **) (((u8 *) temp_16) + 0x320));
  if (var_3 != ((void *) 0))
  {
    goto block_2;
  }
  temp_2 = *((s32 *) (((u8 *) temp_16) + 0x334));
  goto block_4;
  block_2:
  var_2 = *((s128 *) (((u8 *) temp_16) + 0x310));

  goto block_7;
  block_4:
  if (temp_2 < 0)
  {
    goto block_8;
  }

  new_var = &(*((void **) (((u8 *) (temp_16 + (temp_2 * 4))) + 0x360)));
  var_3 = *new_var;
  if (var_3 == ((void *) 0))
  {
    goto block_8;
  }
  var_2 = *((s128 *) (((u8 *) var_3) + 0x10));
  block_7:
  *((s128 *) (((u8 *) temp_16) + 0x5D0)) = var_2;

  *((s8 *) (((u8 *) temp_16) + 0x61B)) = 1;
  *((s128 *) (((u8 *) temp_16) + 0x5E0)) = *((s128 *) (((u8 *) var_3) + 0xF0));
  block_8:
  return;

}




