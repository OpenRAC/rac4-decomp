/* Not matching yet: BYTES 35/84 (tools/try_func.py func_L00_005CF440 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
} Struct_001F3FC0;

extern Struct_001F3FC0 D_00247700;
extern s32 D_00222D90;
extern s32 D_00222D94;

void func_L00_005CF440(void)
{
    s32 i;

    if (D_00247700.unk1C == 0) {
        for (i = 0; i < D_00222D94; i++) {
            *(s16 *)(D_00222D90 + (i << 6) + 0x3A) = 0x7F80;
        }
    }
}
