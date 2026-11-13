/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a; s32 b; } Type1;
s32 func_01EC27F8(u8 *arg0, Type1 *arg1, s32 *arg2) {
    if (arg0 == NULL) {
        return 2;
    }
    if (*(s32 *)(arg0 + 0x3C) != 0) {
        return 0xD6DA;
    }
    if (arg1 == NULL) {
        return 2;
    }
    if (arg2 == NULL) {
        return 2;
    }
    *arg1 = *(Type1 *)(arg0 + 0xC);
    *arg2 = *(s32 *)(arg0 + 0x18);
    return 0;
}
