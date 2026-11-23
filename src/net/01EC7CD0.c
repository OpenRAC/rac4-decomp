/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EC3460(void);
void func_01EC3498(void);
void *func_01EC5280(s32 arg0);
s32 func_01EC7920(s32, s32, s32, s32);

s32 func_01EC7CD0(s32 arg0)
{
    s32 t7;
    s32 s0;
    void *p;

    t7 = func_01EC3460();
    if (t7 != 0)
        return t7;
    s0 = 2;
    p = func_01EC5280(arg0);
    if (p != NULL)
        s0 = func_01EC7920(*(s32 *)((char *)p + 0x9C), 0, 0, 0x2B);
    func_01EC3498();
    return s0;
}
