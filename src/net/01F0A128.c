/* cflags: @ee296 -O2 -G0 -falign-loops=1 */
#include "common.h"

extern void func_01F09BC8(void *);
/* Initializes each record. */
void func_01F0A128(u8 *p)
{
 s32 i; for(i=4;i>=0;i--,p+=8) func_01F09BC8(p);
}
