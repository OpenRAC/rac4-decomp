#include "common.h"
/* Ported from rac3-decomp's func_L39_006DB890 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

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
typedef struct { s32 w[0x19]; } Type1;
void func_L00_00778B30(Type1 *arg0) {
    u8 *obj = *(u8 **)((u8 *)D_002233A4 + 0x60);
    obj[0xF4] = 0;
    *(Type1 *)(obj + 0xF8) = *arg0;
}
