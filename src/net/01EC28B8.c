/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EC2960(void *o);
extern s32 func_01EC29E8(void *o);

s32 func_01EC28B8(void *arg0) {
    s32 r = 0;
    if (arg0 == NULL) return 2;
    switch (*(s32 *)((u8 *)arg0 + 0x3C)) {
    case 0: r = func_01EC2960(arg0); break;
    case 1: r = func_01EC29E8(arg0); break;
    }
    return r;
}
