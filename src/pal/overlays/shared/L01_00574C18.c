/* cflags: -O2 -G8 */
#include "common.h"

extern int func_0011A518(void *, int, int);

typedef struct {
    u8 f0[16];
    u8 f10[30];
    u16 f2E;
} Type1;

extern Type1 D_0024F220[];

/* Reset selected fields of a 48-byte entry, except for the 2049 sentinel index. */
int func_L01_00574C18(u16 index, long flag)
{
    Type1 *entry;

    if (index == 2049) return 1;
    entry = &D_0024F220[index];
    func_0011A518(entry->f0, 0, 16);
    entry->f2E = 65535;
    if (!flag) func_0011A518(D_0024F220[index].f10, 0, 10);
    return 1;
}
