#include "common.h"

typedef struct Type1 {
    char pad[0x18];
    s32 f18, f1C;
} Type1;
extern Type1 D_0023AC00[];
extern s32 D_00221550;
extern s32 D_00221554;
extern void func_0046FF90(void);
extern void func_00470410(void);

/* Copy the pending state fields and initialize both state groups. */
void func_0046FFD8(void)
{
    D_00221554 = D_0023AC00[0].f18;
    D_00221550 = D_0023AC00[0].f1C;
    func_0046FF90();
    func_00470410();
}
