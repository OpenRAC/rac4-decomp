#include "common.h"

/* Updates the object interpolation parameters in the active transition states. */
extern f32 D_0021DE7C;
extern void func_00479EF8(void *, void *, void *, f32, f32, f32);
void func_00514350(char *p)
{
    s32 state = *(s32 *)(p + 0x25CC);
    if (state == 0x7E || (state == 0x99 && *(s32 *)(p + 0x25D8) == 0x7E))
        func_00479EF8(*(void **)(p + 0x2EF0), p + 0x1C58, p + 0x1C5C, 0.3f, D_0021DE7C * 6.981317043304443f * *(f32 *)(p + 0x25C4), -1.0f);
}
