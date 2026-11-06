#include "common.h"

typedef struct Type1 {
    char pad[0x18];
    s32 f18, f1C;
} Type1;
extern Type1 D_0023AB00[];
extern s32 D_00221450;
extern s32 D_00221454;
extern void func_0046F6B0(void);
extern void func_0046FB30(void);

/* Copy the pending state fields and initialize both state groups. */
void func_0046F6F8(void)
{
    D_00221454 = D_0023AB00[0].f18;
    D_00221450 = D_0023AB00[0].f1C;
    func_0046F6B0();
    func_0046FB30();
}
