/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4, f8, fc; s16 f10; } Type1;
// Clears three fields and marks the final field invalid.
s32 func_01ED8500(Type1 *p) {
    s32 result = -0x15;
    if (p == NULL) return result;
    p->fc = 0; p->f4 = 0; p->f0 = 0; p->f10 = -1;
    return 0;
}
