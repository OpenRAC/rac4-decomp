/* cflags: @ee296 -O2 -G0 -falign-loops=1 */
#include "common.h"

extern void func_01F040B0(void *);
/* Initializes each record. */
void func_01F044F4(u8 *p)
{
 s32 i; for(i=63;i>=0;i--,p+=8) func_01F040B0(p);
}
