#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD6E0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

extern long func_0012E370(void);
extern long func_0012FEB0(long, long);
s32 func_L00_00771028(u8 *);
s32 func_L00_00770FA0(u8 *arg0) {
    s32 result = 1;
    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            if (((s32) func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *) (arg0 + 0xC)) >= 0x3A99) {
                arg0[8] = 0;
                result = 0;
                func_L00_00771028(arg0);
            }
        }
    }
    return result;
}
long func_0012E370(void);
long func_0012FEB0(long, long);
