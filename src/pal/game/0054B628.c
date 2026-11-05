/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef struct { u8 f00[13]; u8 f0D[10]; u8 f17[33]; } Type1;
void *func_0054B050(int);
// Check the entry's ten byte identifiers after copying its 56-byte record.
int func_0054B628(int a1, int a2)
{
    Type1 entry;
    int i;
    entry = *(Type1 *)func_0054B050(a2);
    for (i = 0; i < 10; i++) {
        if (entry.f0D[i] == a1) return 1;
    }
    return 0;
}
