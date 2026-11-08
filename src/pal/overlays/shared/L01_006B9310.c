#include "common.h"

extern u32 D_00222E2C;
extern s32 func_L01_006B9368(void *src);
extern u8 *func_00489750(void *src);

/* PAL: from rac3-decomp's func_L39_0066C828 */
s32 func_L01_006B9310(void *src) {
    if ((u32)src < D_00222E2C) {
        return func_L01_006B9368(src);
    }
    return (*(s32 (**)(void *))(func_00489750(src) + 4))(src);
}
