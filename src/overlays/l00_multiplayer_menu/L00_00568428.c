/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_0051A3B8 (src/levels/39_multiplayer_menu/L39_0051A3B8.c, GPL-3.0), the same code in both games. */

typedef struct Type1 { char pad[0x14]; char f14[0x40]; s32 f54; } Type1;
extern Type1 *func_L00_005669E0(s32);
extern void func_L00_005669C0(void);
extern void func_01E9BCE8(void *, s32, s32, s32);
extern s32 func_L00_00566950(void);
extern s32 func_L00_00566BA0(Type1 *, s32);
s32 func_L00_00568428(s32 arg) {
    Type1 *p = func_L00_005669E0(0);
    if (p == 0) return -1;
    func_L00_005669C0();
    func_01E9BCE8(p->f14, p->f54, 0, 0x52534C56);
    if (func_L00_00566950() < 0) {
        return func_L00_00566BA0(p, -1);
    }
    return func_L00_00566BA0(p, 0);
}
