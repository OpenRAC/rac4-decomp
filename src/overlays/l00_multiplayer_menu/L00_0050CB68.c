/* cflags: -fno-strength-reduce -fno-schedule-insns2 */
#include "common.h"
/* XOR eight bytes into the second buffer. */
unsigned char *func_L00_0050CB68(unsigned char *a, unsigned char *b)
{
    int i;
    for (i = 0; i < 8; i++)
        b[i] ^= a[i];
    return b;
}
