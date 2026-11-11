/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_00165D48[];
extern s32 D_00165D4C[];
extern char D_1ACE08[];
extern void *func_0011A518(void *, s32, u32);
/* Clear state and initialize the buffer. */
void func_0012EC40(void)
{
 D_00165D48[0] = 0; D_00165D4C[0] = 0; func_0011A518(D_1ACE08, 0, 0x200);
}
