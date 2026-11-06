#include "common.h"

extern s32 func_00548B00(void *, u8, u8, s32, s32, s32, s32, void *);
/* Forward the selected entry and current object parameters. */
int func_005229E0(char *p, unsigned char i, int a, void *b)
{
    return func_00548B00(*(void **)(p + 0x26E4), i, *(unsigned char *)(p + 0x2F10), a, *(unsigned char *)(p + 0x266D) != 0, *(int *)(p + 0x2F28), *(int *)(p + i * 80 + 0x2318), b);
}
