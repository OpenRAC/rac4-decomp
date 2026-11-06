#include "common.h"

extern s32 D_0021DE98;
extern u8 D_000C2900[];
extern s32 func_0011EF60(void *);

s32 D_0021EF94 = 0;

#define D_000C24FF ((u8 *)0x000C24FF)
#define D_000C2500 ((u8 *)0x000C2500)

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
        D_0021EF94 = func_0011EF60((void *)D_000C2500);
    }
}
