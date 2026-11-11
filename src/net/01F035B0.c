/* cflags: -Os -mno-split-addresses -fno-schedule-insns2 */
#include "common.h"

extern void func_01EF382C(void *,s32,s32);
extern void *func_01EEDCD0(void *,const void *,s32);
extern s32 func_01EE3A18(s32, void *);
extern char D_00170A98[],D_0019DF20[],D_0019DF18[];
/* Initializes a record and looks up a named value. */
void func_01F035B0(u8 *p,s32 a,s32 b)
{
 func_01EF382C(p,a,b); *(void**)(p+0xb0)=D_00170A98; func_01EEDCD0(p+0x38,D_0019DF20,0x40); *(void**)(p+0xa0)=(void *)func_01EE3A18(*(s32 *)p,D_0019DF18);
}
