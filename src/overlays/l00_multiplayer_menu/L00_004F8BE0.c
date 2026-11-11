/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004BCDE0 (src/levels/39_multiplayer_menu/L39_004BCDE0.c, GPL-3.0), the same code in both games. */

typedef struct Type1 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} Type1;
extern s32 **func_L00_004F8F78(Type1 *, s32, s32 *);
s32 func_L00_004F8BE0(Type1 *self, s32 a1) {
    s32 local[4];
    s32 *p;
    self->fA0 = 0;
    p = *func_L00_004F8F78(self, a1, local);
    if (p == 0) {
        self->f90++;
        return 0;
    }
    self->f88++;
    return *p;
}
