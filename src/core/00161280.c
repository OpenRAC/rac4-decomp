#include "common.h"

extern s32 func_01E9E798();
typedef struct {
    u8 pad[0x2C0];
    s32 f2C0;
} Type1;
extern Type1 D_00172160[];
extern s32 D_0021DE10;

/* Store 0 or -0xC at D_00172160+0x2C0 from D_0021DE10 and return the stored value. */
s32 func_00161280(void) {
    if (D_0021DE10 > 0 && (u32) (D_0021DE10 - 0x29) >= 0x28U && D_0021DE10 != 0x1A0A && D_0021DE10 != 0x25EC) {
        D_00172160[0].f2C0 = 0;
    } else {
        D_00172160[0].f2C0 = (func_01E9E798() == 0) ? 0 : -0xC;
    }
    return D_00172160[0].f2C0;
}
