/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_004A03AC[];
extern s32 func_L00_004F8888(void *, void *);
extern s32 func_L00_0051C140(s32 *);
extern s32 func_L00_0051C0C8(s32 **, s32 **);

/* Lazily creates D_004A03AC through func_L00_004F8888; returns 1 if it exists or was created. */
s32 func_L00_0051C080(void) {
    if (D_004A03AC[0] != 0) {
        return 1;
    }
    D_004A03AC[0] = func_L00_004F8888(func_L00_0051C140, func_L00_0051C0C8);
    return D_004A03AC[0] != 0;
}
