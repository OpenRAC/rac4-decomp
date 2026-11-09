/* cflags: -msplit-addresses */
#include "common.h"

extern s32 func_0011AB04(const char *);
extern s32 func_0011DD48(void *, const char *, void *);
extern void *D_00163E74[];
extern s32 func_0011D9A0(void);
typedef struct { char *f0; s32 f4; u8 p8[4]; s16 fc; u8 pe[2]; char *f10; s32 f14; u8 p18[8]; s32 (*f20)(void); u8 p24[12]; s32 f30; u8 p34[16]; s32 f44; u8 p48[12]; void *f54; u8 p58[8]; } Type1;
/* Scans an input string through a temporary stream. */
s32 func_0011D9A8(void *p, const char *fmt,...)
{
 Type1 st; s32 n;
 st.fc=4; st.f0=p; st.f10=p;
 n=func_0011AB04(p);
 st.f20=func_0011D9A0; st.f54=D_00163E74[0]; st.f4=n; st.f14=n; st.f30=0; st.f44=0;
 return func_0011DD48(&st,fmt,(u8*)__builtin_next_arg(fmt)-0x30);
}
