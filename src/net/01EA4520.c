/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EA06A8(void *);
extern s32 D_001AF928[];
/* Initializes a global array of records. */
s32 func_01EA4520(void)
{
 s32 i; s32 *p=D_001AF928; for(i=255;i>=0;i--,p++) func_01EA06A8(p); return 0;
}
