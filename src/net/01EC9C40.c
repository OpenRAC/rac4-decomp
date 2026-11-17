/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; u8 f8; } E;
typedef void (*H)(u32, s32);
extern H *D_001B73B8;
E *func_01EC98E8(s32);
void func_01EC9C40(u32 a0, s32 a1) {
    E *e;
    H h;
    if (a0 >= 0x100) {
        return;
    }
    e = func_01EC98E8(a1);
    if (e == 0) {
        return;
    }
    h = D_001B73B8[e->f8];
    if (h == 0) {
        return;
    }
    h(a0, a1);
}
