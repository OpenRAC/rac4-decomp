/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 *f0; u32 f4; } Type1;
extern u32 func_01EDA958(void *, u16 *, u16);
// Builds a mask from the halfwords described by the input record.
u32 func_01EDB030(void *arg0, Type1 *arg1) {
    return func_01EDA958(arg0, arg1->f0, (u16)(arg1->f4 >> 1));
}
