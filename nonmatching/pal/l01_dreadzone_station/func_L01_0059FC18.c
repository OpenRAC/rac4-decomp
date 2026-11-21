/* Not matching yet on PAL: 16/26 positional words match (61.54%); 10 differ, size 108/104 bytes (delta +4). */
/* cflags: -O2 -G8 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L01_0059FC18 nonmatching/pal/l01_dreadzone_station/func_L01_0059FC18.c --diff
 * Instruction order and size differ; the callee signature and object layout remain inferred. */
#include "common.h"
extern s32 func_0046D0B0(s32);
void func_L01_0059FC18(s32 a, void *v) {
 char *p=v; s32 x=*(s32 *)(p+0x78);
 if (x && x==a && *(u8 *)(p+1)) func_0046D0B0(x);
 *(u8 *)(p+1)=0; *(f32 *)(p+0x70)=1.0f; __builtin_memset(p+0x40,0,48);
}
