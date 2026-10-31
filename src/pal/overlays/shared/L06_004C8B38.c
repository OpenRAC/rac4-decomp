/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

/* Read and clear the word at offset 0x24 of the object reached through offset 0xAC. */
int func_L06_004C8B38(int a1)
{
    int v1;
    int result;

    v1 = *(u32 *)(a1 + 172);
    result = *(int *)(v1 + 36);
    if (!*(u32 *)(v1 + 36))
        return 0;
    *(u32 *)(v1 + 36) = 0;
    return result;
}
