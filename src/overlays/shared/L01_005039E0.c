#include "common.h"

typedef struct { long long v; } Q_5039E0;
extern void func_0046C978(u8 *a0, s32 a1, Q_5039E0 *a2);
extern void func_L01_0055B420(Q_5039E0 *a0, s32 a1, s32 a2);
extern void func_L01_0055B8F8(Q_5039E0 a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

/* from rac3-decomp's func_L13_003C5E20 */
void func_L01_005039E0(u8 *a0) {
    Q_5039E0 buf;
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 172);
        if (s0 != 0) {
            func_0046C978(a0, 0, &buf);
            func_L01_0055B420(&buf, 0x103080, 0);
            func_L01_0055B8F8(buf, s0 + 48, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
