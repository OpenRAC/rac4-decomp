/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void **D_001B6A50;
extern void *func_01EA0668(s32);
void *func_01EC8F68(s32 a0, u32 i) {
    void *p;
    if (i >= 0x100) {
        return 0;
    }
    if (a0 == 0) {
        return 0;
    }
    p = func_01EA0668(0x24);
    D_001B6A50[i] = p;
    return p;
}
