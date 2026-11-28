/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/l41_descriptor_state.h"

extern s32 D_0021E714;
extern char D_00386050[];

void *func_L41_00444998(s32 arg0, s32 arg1, s32 *arg2)
{
    if (D_0021E714 != 1 || D_L41_00221A10 == NULL)
        return 0;
    if (arg1 == 0) {
        *arg2 = 20;
        return D_00386050;
    }
    return 0;
}