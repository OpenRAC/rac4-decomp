#include "common.h"

/* stores its arguments in two globals, clears two words, and calls func_00127438 on two buffers */
extern void func_00127438(void *, void *);

void *D_0021DCA8 = 0;
s32 D_0021DCAC = 0;

void func_00158240(u8 *arg0, s32 arg1) {
    s32 off;
    u8 *p;

    off = arg1 * 4;
    D_0021DCAC = arg1;
    D_0021DCA8 = arg0;
    *(s32 *)((u32)off + (u32)arg0 + 4) = 0;
    *(s32 *)arg0 = 0;
    func_00127438(arg0, arg0 + 3);
    off += 4;
    p = arg0 + off;
    func_00127438(p, p + 3);
}
