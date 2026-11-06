#include "common.h"

extern s32 D_0021DE98;
extern s32 D_0021EE3C;
extern s32 D_002213E0;
extern u8 D_00171DB8[];
extern s32 func_00466450(void);
extern s32 func_004CB780(void);
extern void func_004381D8(s32);

s32 D_0021FAD0 = 0;

/* Update the selected mode and synchronize its public byte. */
s32 func_004CC218(void)
{
    s32 initial;
    s32 mode_zero;
    s32 mode_nonzero;
    s32 current;
    s32 base;
    s32 result;
    s32 one;
    result = func_00466450();
    if (result == 0x16) {
        result = 0;
        goto done;
    }
    one = 1;
    initial = D_0021DE98;
    D_0021EE3C = one;
    if (initial == 0x0F || initial == 0x23) {
        D_0021DE98 = one;
    }
    result = func_004CB780();
    if (result != 0) {
        mode_nonzero = D_0021DE98;
        D_0021DE98 = mode_nonzero % 0x14 + 0x14;
    } else {
        mode_zero = D_0021DE98;
        D_0021DE98 = mode_zero % 0x14;
    }
    base = (s32)D_00171DB8;
    current = D_0021DE98;
    D_002213E0 = current;
    if (D_0021FAD0 != *(u8 *)(base + 0xBD)) {
        func_004381D8(*(u8 *)(base + 0xBD));
        D_0021FAD0 = *(u8 *)(base + 0xBD);
    }
    result = 0;
done:
    return result;
}
