/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00436C40(void);
extern void func_00436C48(void);
extern void func_00470870(u32);
extern s32 func_004F4D28(void);
extern u32 D_002213F4;
extern u32 D_0022140C;
extern u8 D_00221F48[];

s32 func_004F6328(void)
{
    u32 p;
    s32 r;
    s32 f;

    for (p = D_002213F4; p < D_0022140C; p += 0x100) {
        func_00470870(p);
    }
    r = func_004F4D28();
    D_00221F48[0] = r;
    f = (u8)r != 0;
    func_00436C40();
    func_00436C48();
    return f;
}
