/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_01E9BD30(void *a, s32 b, s32 c, s32 d, void *e, s32 f);

/* applies two optional settings of a request, returning the first failure */
s32 func_L00_00567368(u8 *a, u8 *b) {
    s32 r;
    if (*(s32 *)(b + 0x70) >= 0) {
        r = func_01E9BD30(a + 0x14, *(s32 *)(a + 0x54), *(s32 *)(b + 0xC), 0xD, b + 0x70, 4);
        if (r < 0) {
            return r;
        }
    }
    if (*(s32 *)(b + 0x74) >= 0) {
        r = func_01E9BD30(a + 0x14, *(s32 *)(a + 0x54), *(s32 *)(b + 0xC), 0xF, b + 0x74, 4);
        if (r < 0) {
            return r;
        }
    }
    return 0;
}
