/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 *func_01ED85B0(void *);
/* Return the second word of the returned object when present. */
s32 func_01ED8608(void *arg) {
    s32 *p = func_01ED85B0(arg);
    if (p) {
        return p[1];
    }
    return 0;
}
