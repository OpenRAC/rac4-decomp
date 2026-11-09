/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_00510BE8();
s32 func_00512748(s32);
extern u8 D_0021DE32[];
extern u8 D_0021DE33[];
extern s32 D_0021EDD4;

s32 func_00498950(s32 arg0) {
    s32 r;
    s32 v;
    r = func_00512748(func_00510BE8());
    if (D_0021EDD4 != 1) {
        if (arg0 == 0) v = D_0021DE32[0]; else v = D_0021DE33[0];
        if (v != 0) { v--; r = v; }
    }
    return r;
}
