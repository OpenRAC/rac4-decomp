#include "common.h"

/* Release the pending state and clear its request flags. */
extern u8 D_0021DD54;
extern s32 D_0021DD44;
extern char D_00209148[], D_003D08A8[];
extern void func_00460110(void);
extern void func_00460AA8(void *, s32, void *);
void func_00461030(void)
{
    if (D_0021DD54) {
        func_00460110();
        func_00460AA8(D_00209148, 1, D_003D08A8);
        D_0021DD44 = 0;
        D_0021DD54 = 0;
    }
}
