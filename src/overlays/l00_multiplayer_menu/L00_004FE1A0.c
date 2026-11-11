/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C23A0 (src/levels/39_multiplayer_menu/L39_004C1F40.c, GPL-3.0), the same code in both games. */

extern void func_L00_00519490(void *, s32);
typedef struct A_004C23A0 { u8 _00[0xF8]; s32 fF8; s32 fFC; } A_004C23A0;
typedef struct B_004C23A0 { u8 _00[0x104]; s32 f104; s32 f108; } B_004C23A0;
typedef struct Type1 { u8 _00[0x54]; A_004C23A0 *pA; u8 _58[0xDC - 0x58]; B_004C23A0 *pB; } Type1;
s32 func_L00_004FE1A0(Type1 *self) {
    if (((s32 (*)(s32, s32))func_L00_00519490)(self->pA->fF8, self->pB->f104) == 0) {
        return 0;
    }
    return ((s32 (*)(s32, s32))func_L00_00519490)(self->pA->fFC, self->pB->f108) != 0;
}
