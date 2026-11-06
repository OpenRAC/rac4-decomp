/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B2148[];
extern void func_01EA8A50(void *);
extern s32 func_0011A370(void *, const void *, s32);

s32 func_01EA7DF0(void *arg0)
{
    func_01EA8A50(arg0);
    return func_0011A370(arg0, D_001B2148, 0x38);
}
