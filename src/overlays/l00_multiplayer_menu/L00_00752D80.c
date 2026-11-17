#include "common.h"

extern s32 func_L00_00753810(void *);
extern s32 func_L00_00753930(void *);

/* Steps the menu state machine according to the state at 0x230. */
s32 func_L00_00752D80(u8 *arg0) {
    s32 r = 0;
    u8 *o;
    switch (*(s32 *)(arg0 + 0x230)) {
    case 6:
        o = *(u8 **)(arg0 + 0xC8);
        (*(void (**)(void *, s32))(*(u8 **)(o + 0x58) + 0x18))(o, 7);
        o = *(u8 **)(arg0 + 0xC8);
        if ((*(s32 (**)(void *))(*(u8 **)(o + 0x58) + 0x78))(o) != 0) {
            func_L00_00753930(arg0);
        }
        r = 1;
        break;
    case 0:
        r = func_L00_00753810(arg0) != 0;
        break;
    case 7:
        r = func_L00_00753930(arg0) != 0;
        break;
    }
    return r;
}
