/* Not matching yet: 10/23 (43.48%) relocation-masked positional words; 100/92 candidate/target bytes. Two extra words; aggregate layout and callee contracts remain hypotheses. Reproduce: python tools/check_func.py --version pal func_004A30F8 nonmatching/pal/game/func_004A30F8.c --diff. Not part of the build. */
/* cflags: -mno-split-addresses -Wuninitialized */
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

void *func_004A3090(void);                                /* extern */
void func_00502508(void *);                         /* extern */
s32 func_00506D28(void *);                         /* extern */



extern s32 D_0021F710;
extern s32 D_0021F714;


struct GlobalView_001719C8 { unsigned char gap_0[16]; s32 field_10; unsigned char gap_14[440]; s32 field_1CC[2]; };
extern char D_001719C8[];
typedef char GlobalViewOffset_001719C8_10[((unsigned int)&(((struct GlobalView_001719C8 *)0)->field_10) == 16) ? 1 : -1];
typedef char GlobalViewWidth_001719C8_10[(sizeof(((struct GlobalView_001719C8 *)0)->field_10) == 4) ? 1 : -1];
typedef char GlobalViewOffset_001719C8_1CC[((unsigned int)&(((struct GlobalView_001719C8 *)0)->field_1CC[0]) == 460) ? 1 : -1];
typedef char GlobalViewWidth_001719C8_1CC[(sizeof(((struct GlobalView_001719C8 *)0)->field_1CC[0]) == 4) ? 1 : -1];
typedef char GlobalViewOffset_001719C8_1D0[((unsigned int)&(((struct GlobalView_001719C8 *)0)->field_1CC[1]) == 464) ? 1 : -1];
typedef char GlobalViewWidth_001719C8_1D0[(sizeof(((struct GlobalView_001719C8 *)0)->field_1CC[1]) == 4) ? 1 : -1];
typedef char GlobalViewPointer_001719C8[(sizeof(void *) == 4) ? 1 : -1];
void func_004A30F8(void) {
  func_00502508(func_004A3090());
  func_00506D28(func_004A3090());
  D_0021F710 = 0;
  D_0021F714 = 0;
  ((struct GlobalView_001719C8 *)D_001719C8)->field_10 = 0;
  if (((struct GlobalView_001719C8 *)D_001719C8)->field_1CC[0] < 0)
  {
    ((struct GlobalView_001719C8 *)D_001719C8)->field_1CC[1] = 0;
    ((struct GlobalView_001719C8 *)D_001719C8)->field_1CC[0] = 7;
  }
}
