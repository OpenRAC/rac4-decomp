#include "common.h"
/* Ported from rac3-decomp's func_L39_00647A20 (src/levels/shared/L39_00646980.c, GPL-3.0), the same code in both games. */

typedef struct {
    s32 ids[8];
} IdList;
extern IdList D_003D3DC8;
extern s32 func_00546A20(s32);
s32 func_00525E30(void) {
    IdList list = D_003D3DC8;
    s32 *p = list.ids;
    s32 i;
    s32 ret = 0x1;
    for (i = 0; i < 8; i++) {
        if (func_00546A20(*p) != 0) {
            ret = *p;
            break;
        }
        p++;
    }
    return ret;
}
