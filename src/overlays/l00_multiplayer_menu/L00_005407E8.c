/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_005049D8 (src/levels/39_multiplayer_menu/L39_005047E8.c, GPL-3.0), the same code in both games. */

typedef struct {
    char pad0[0x88];
    s32 f88[0x10];
    s32 fC8[0x10];
    char pad108[0x80];
    s32 f188;
} Type1;
extern Type1 *func_L00_004F86B0();
void func_L00_005407E8(s32 a0, s32 a1) {
    Type1 *p = func_L00_004F86B0();
    s32 i = p->f188;
    if (i == 0) {
        i = 15;
    }
    p->f88[i] = a0;
    p->fC8[p->f188] = a1;
}
