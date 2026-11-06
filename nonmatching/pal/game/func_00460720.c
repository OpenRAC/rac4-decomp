/* Not matching yet on PAL: BYTES 2/108 (2 words differ) (tools/check_func.py --version pal func_00460720 --diff). Not part of the build. */
/* Retail builds these fixed addresses as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"

extern s32 D_0021DE98;
extern u8 D_000C2900[];
extern u8 D_000C24FF[];
extern u8 D_000C2500[];
extern s32 func_0011EF60(void *);

s32 D_0021EF94 = 0;

/* Call the fixed-address handler while the state is outside its valid range. */
void func_00460720(void)
{
    s32 skip = 0;
    s32 test;
    if (D_0021DE98 == 0 || D_0021DE98 >= 40) {
        skip = 1;
    }
    if (skip != 0) {
        test = 1;
    } else {
        test = 0;
    }
    if (test == 0 && (s32)D_000C24FF < (s32)D_000C2900) {
        D_0021EF94 = func_0011EF60(D_000C2500);
    }
}
