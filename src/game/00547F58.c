#include "common.h"

s32 func_00547E30(s32, s32);
s32 func_00547E00(s32, s32);
void func_00547DC8(s32, s32, s32);
s32 func_00547F58(s32 a, s32 b, s32 c) {
    s32 n, m, rem;
    n = func_00547E30(a, b);
    if (n == 0) {
        return 0;
    }
    m = func_00547E00(a, b);
    func_00547DC8(a, b, n < m + c ? n : m + c);
    rem = m - n;
    if (rem > 0) {
        func_00547DC8(a, b, n);
    } else {
        rem = 0;
    }
    return rem;
}
