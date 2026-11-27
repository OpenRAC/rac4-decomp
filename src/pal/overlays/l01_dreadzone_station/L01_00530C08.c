#include "common.h"
#include "pal/level01_scene_data.h"

typedef struct {
    u8 pad00[0x62];
    s16 f62;
} Type1;

extern Type1 D_003B3F50;
extern u8 D_003B3FD0[];
extern u8 D_003B3FF0[];
extern s32 D_0023F774[];

void func_L01_00530C08(void)
{
    if (D_003B3F50.f62 >= D_0023F774[0]) {
        D_0022FFA0.f4 = &D_003B3F50;
        D_0022FFA0.f8 = D_003B3FD0;
    } else {
        D_0022FFA0.f4 = D_003B3FF0;
    }
}
