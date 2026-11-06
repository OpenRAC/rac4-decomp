#include "common.h"

extern u8 D_0021E6FA;
extern s32 D_0021DE70;
extern s32 D_00171D38_[];
#define D_00171D38 (D_00171D38_[0])

/* Unless D_0021E6FA is set, counts D_0021DE70 up by 1, or by 11 on every 50th tick while D_00171D38 is set. */
void func_L00_0061DAA8(void) {
    if (D_0021E6FA == 0) {
        s32 v = D_0021DE70;
        D_0021DE70 = v + 1;
        if ((v + 1) % 50 == 0 && D_00171D38 != 0) {
            D_0021DE70 = v + 11;
        }
    }
}
