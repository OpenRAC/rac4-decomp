#include "common.h"
/* Ported from rac3-decomp's func_L39_004BB898 (src/levels/39_multiplayer_menu/L39_004BB4C0.c, GPL-3.0), the same code in both games. */

extern s32 D_004667F8[];
extern s32 D_004667FC[];
s32 func_L00_004F7698(s32 idx, s32 val) {
    s32 ret = 1;
    switch (idx) {
    case 0:
        D_004667F8[0] = val;
        break;
    case 1:
        D_004667FC[0] = val;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
extern s32 (*D_L39_004433C8[])(void);
extern s32 (*D_L39_004433D0[])(void);
extern s32 (*D_L39_004433D4[])(void);
extern s32 (*D_L39_004433DC[])(void);
extern s32 (*D_L39_004433E4[])(void);
extern s32 (*D_L39_004433E8[])(void);
extern s32 (*D_L39_004433EC[])(void);
extern s32 (*D_L39_0044340C[])(void);
extern s32 (*D_L39_0044341C[])(void);
extern s32 (*D_L39_00443420[])(void);
extern s32 (*D_L39_0044342C[])(void);
extern s32 (*D_L39_00443428[])(void);
extern s32 (*D_L39_00443440[])(void);
extern s32 (*D_L39_00443450[])(void);
extern s32 (*D_L39_00443454[])(void);
extern s32 (*D_L39_00443474[])(void);
extern s32 (*D_L39_00443478[])(void);
extern s32 (*D_L39_0044347C[])(void);
extern s32 (*D_L39_00443494[])(void);
