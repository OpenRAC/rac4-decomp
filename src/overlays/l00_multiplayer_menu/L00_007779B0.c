#include "common.h"
/* Ported from rac3-decomp's func_L39_006DA878 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;
extern Obj_006DA090 *D_002233A4;
extern Obj_006DA090 *D_002233A4;
typedef struct { char bytes[0xB8]; } Block_006DA878;
typedef struct { char pad[4]; unsigned char f4; char pad2[3]; Block_006DA878 f8; } Type1_006DA878;
typedef struct { char pad[0x60]; Type1_006DA878 *f4C; } Type2_006DA878;
void func_L00_007779B0(Block_006DA878 *arg0) {
    Type1_006DA878 *p = ((Type2_006DA878 *)D_002233A4)->f4C;
    p->f4 = 0;
    p->f8 = *arg0;
}
