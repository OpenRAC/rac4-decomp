#include "common.h"

extern u32 *func_005112C8(void);

/* The word func_005112C8 returns a pointer to, or 0xFFFFFFFF when it returns null. */
u32 func_00511298(void) {
    u32 *p = func_005112C8();
    if (p != 0) {
        return *p;
    }
    return 0xFFFFFFFF;
}
