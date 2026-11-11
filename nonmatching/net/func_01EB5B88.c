/* Not matching yet: BYTES 13/60 (tools/try_func.py func_01EB5B88 --diff). Not part of the build. */
/* cflags: @ee296 -Os -G0 */
#include "common.h"
extern s32 D_001694FC;
extern char D_001B26C0[];
extern s32 func_01E9D378(void *);
/* Checks global state and returns a status. */
s32 func_01EB5B88(void)
{
 s32 r=5; if(D_001694FC) r=func_01E9D378(D_001B26C0) ? 0xc350 : 0; return r;
}
