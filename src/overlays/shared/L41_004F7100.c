#include "common.h"

extern u8 *func_L00_006F0C48(void);

s32 func_L41_004F7100(void) {
    u8 *p;

    p = func_L00_006F0C48();
    if (p != NULL) {
        return *(s32 *)(p + 4);
    }
    return 0;
}
