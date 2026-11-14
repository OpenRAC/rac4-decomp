/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *D_0016A074;
extern void (*D_00199184)(void *);
void func_01EDA8C0(void) {
    if (D_0016A074 != 0) {
        D_00199184(D_0016A074);
        D_0016A074 = 0;
    }
}
