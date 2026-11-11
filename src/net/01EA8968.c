/* cflags: @ee296 -O2 -G8 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Pair;

extern s32 D_1B2148[];
extern s32 D_1B2180[];
extern s32 func_01EAB270();

/* Clear the eleven words of the global record, let the reset pass run and copy
   its first 8 bytes to the second record. */
void func_01EA8968(void)
{
    s32 *p = D_1B2148;

    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    func_01EAB270(p);
    *(Pair *)D_1B2180 = *(Pair *)p;
}
