#include "common.h"

/* Release the pending state and clear its request flags. */
extern u8 D_0021DDDC;
extern s32 D_0021DDCC;
extern char D_002091C8[], D_003D0910[];
extern void func_00460950(void);
extern void func_004612E8(void *, s32, void *);
void func_00461870(void)
{
    if (D_0021DDDC) {
        func_00460950();
        func_004612E8(D_002091C8, 1, D_003D0910);
        D_0021DDCC = 0;
        D_0021DDDC = 0;
    }
}
