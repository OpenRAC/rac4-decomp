/* Not matching yet: BYTES 59/112 (@ee32-030210, was 85/108). Not part of the build. */
/* cflags: @ee32-030210 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x104];
    u32 f104;
    u8 pad108[0x10];
    u32 f118;
    u8 pad11C[0x48];
    u8 *f164;
} Type1;

extern Type1 *D_00167F38;

s32 func_01ECFB68(u32 *arg0, u32 *arg1)
{
    s32 result = 0x17;
    u32 key, slot;
    Type1 *p;
    u8 *e;

    if (arg0 == NULL) {
        return result;
    }
    if (arg1 == NULL) {
        return result;
    }
    key = arg0[0];
    if (key == 0) {
        return result;
    }
    result = 0x13;
    p = D_00167F38;
    slot = p->f118;
    if (slot >= p->f104) {
        return result;
    }
    arg1[0] = slot;
    result = 0;
    e = p->f164 + slot * 8;
    arg1[1] = 0;
    *(u32 *)(e + 4) = arg0[1];
    *(u32 *)(e + 0) = key;
    p->f118 = p->f118 + 1;
    return result;
}
