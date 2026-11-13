#include "common.h"
u8 *func_0047DE20(void);
/* Select the first nonzero priority byte in the observed descending order. */
f32 func_L01_005A93D8(void)
{
    u8 *p;
    f32 value;
    p = func_0047DE20();
    if (p[0x204] != 0) return 200.0f;
    if (p[0x203] != 0) return 180.0f;
    if (p[0x202] != 0) return 150.0f;
    if (p[0x201] != 0) return 120.0f;
    if (p[0x200] != 0) return 90.0f;
    if (p[0x1FF] == 0) {
        value = 50.0f;
        if (p[0x1FE] == 0) value = 30.0f;
    } else {
        value = 70.0f;
    }
    return value;
}
