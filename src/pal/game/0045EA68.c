#include "common.h"

extern u16 D_001F7810[];
extern s32 D_0021DEFC;
extern s32 func_0045E740(s32);
extern s32 func_0045E770(s32);

// MRU list
s32 func_0045EA68(s32 id) {
    s32 i;
    u16 key;

    if (func_0045E740(id) != 0) {
        return 0;
    }
    if (func_0045E770(id) != 0) {
        return 0;
    }
    key = id;
    for (i = 0; D_001F7810[i] != key && i < D_0021DEFC; i++) {
    }
    if (i < D_0021DEFC) {
        for (; i < D_0021DEFC - 1; i++) {
            D_001F7810[i] = D_001F7810[i + 1];
        }
        D_001F7810[i] = 0;
        D_0021DEFC--;
    }
    D_001F7810[D_0021DEFC++] = key;
    return 1;
}
