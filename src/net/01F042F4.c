/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_01F040A4(s32 *);
void func_01F042F4(s32 *arg0)
{
    s32 *p = arg0;
    s32 i = 0x3F;
    for (; i != -1; i--) {
        func_01F040A4(p);
        p += 2;
    }
    func_0011A518(arg0, 0, 0x200);
    *(s32 *)((char *)arg0 + 0x200) = 0;
}
