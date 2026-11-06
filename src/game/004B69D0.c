/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"
#include "common.h"

typedef struct {
    u8 unk00[0x0C];
    s32 unk0C;
    s32 unk10;
    u8 unk14[0x1E4];
} Record003098F0;
extern Record003098F0 D_003098F0[];

void func_004B69D0(s32 index)
{
    D_003098F0[index].unk10 = 0;
}
