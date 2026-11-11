#include "common.h"
/* Ported from rac3-decomp's func_L39_006D9BC0 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

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
typedef struct { u8 b[0x70]; } Blob_006D9BC0;
void func_L00_00776C38(Blob_006D9BC0 *src) {
    u8 *dst = *(u8 **)((u8 *)D_002233A4 + 0x5C);
    dst[0x14C] = 0;
    *(Blob_006D9BC0 *)(dst + 0x150) = *src;
}
