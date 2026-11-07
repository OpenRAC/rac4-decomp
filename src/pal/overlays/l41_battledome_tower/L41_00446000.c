/* cflags: @ee29 */
#include "common.h"
extern u32 D_003982C0;
void func_L41_00446000(void *object)
{
    u8 *state=*(u8 **)((u8 *)object+0xAC);
    u32 value=D_003982C0|0x1F000000U;
    *(u32 *)(state+0x6C)=value;
    *(u32 *)(state+0x68)=value;
}
