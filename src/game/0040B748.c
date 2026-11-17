/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4; } P;
s32 func_0040A780(s32, s32, s32, s32, s32);
s32 func_0040B748(s32 a0, s32 a1, s32 a2, P *p) {
    if (p == 0 || p->f0 == 0) {
        return 0;
    }
    return func_0040A780(a0, a1, a2, p->f0, p->f4);
}
