/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0; u8 f1[3]; u32 f4, f8, fC, f10; } Type1;
extern s32 func_01EA9F90(Type1 *);
/* Clears the context and marks it active if initialization succeeds. */
s32 func_01EA9D98(Type1 *arg0) {
    s32 result;
    if (arg0 == NULL) return 2;
    arg0->f0 = 0;
    arg0->f4 = 0;
    arg0->f8 = 0;
    result = func_01EA9F90(arg0);
    if (result == 0) arg0->f0 = 1;
    return result;
}
