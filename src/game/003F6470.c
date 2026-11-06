/* cflags: -fno-strength-reduce -fno-schedule-insns2 */
#include "common.h"
/* XOR eight bytes into the second buffer. */
unsigned char *func_003F6470(unsigned char *a, unsigned char *b)
{
    int i;
    for (i = 0; i < 8; i++)
        b[i] ^= a[i];
    return b;
}
