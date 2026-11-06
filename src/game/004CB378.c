#include "common.h"

extern s32 D_0021DE10;
extern s32 D_0021EDBC;
extern s32 D_002212E0;
extern u8 D_00171D38[];
extern s32 func_00465C08(void);
extern s32 func_004CA8E8(void);
extern void func_00437CD8(s32);

s32 D_0021FA30 = 0;

/* Update the selected mode and synchronize its public byte. */
s32 func_004CB378(void)
{
    s32 initial;
    s32 mode_zero;
    s32 mode_nonzero;
    s32 current;
    s32 base;
    s32 result;
    s32 one;
    result = func_00465C08();
    if (result == 0x16) {
        result = 0;
        goto done;
    }
    one = 1;
    initial = D_0021DE10;
    D_0021EDBC = one;
    if (initial == 0x0F || initial == 0x23) {
        D_0021DE10 = one;
    }
    result = func_004CA8E8();
    if (result != 0) {
        mode_nonzero = D_0021DE10;
        D_0021DE10 = mode_nonzero % 0x14 + 0x14;
    } else {
        mode_zero = D_0021DE10;
        D_0021DE10 = mode_zero % 0x14;
    }
    base = (s32)D_00171D38;
    current = D_0021DE10;
    D_002212E0 = current;
    if (D_0021FA30 != *(u8 *)(base + 0xBD)) {
        func_00437CD8(*(u8 *)(base + 0xBD));
        D_0021FA30 = *(u8 *)(base + 0xBD);
    }
    result = 0;
done:
    return result;
}
