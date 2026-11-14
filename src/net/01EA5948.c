/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011AFC8(void *, const void *, unsigned int);
s32 func_01EA5948(char *o, s32 a1, s32 a2, void *src) {
    if (o == 0) {
        return -1;
    }
    func_0011AFC8(o + 0x418, src, 0x10);
    return 0x10;
}
